#include "test_bench.h"
#include <fstream>

unsigned int ticks = 0;

class TopTestbench : public Testbench {
protected:
    std::ofstream logFile;

    void initializeInputs() override { 
        top->clk = 1;
        top->rst = 0;
        top->en  = 1;
        top->step = 1000;
        top->omega = 0x4000; // 2.0 in Q3.13, tau=0.5
        top->init_c0 = 0x0E38; // 4/9
        top->init_cn = 0x038E; // 1/9
        top->init_cs    = 0x038E;
        top->init_ce    = 0x038E;
        top->init_cw    = 0x038E;
        top->init_cne   = 0x00E4; // 1/36
        top->init_cse  = 0x00E4;
        top->init_csw   = 0x00E4;
        top->init_cnw   = 0x00E4;

        logFile.open("u_squared_log.txt");
        if (!logFile.is_open()) {
            std::cerr << "Failed to open u_squared_log.txt" << std::endl;
            exit(EXIT_FAILURE);
        }
    }

// ✅ override runSimulation in this subclass
void runSimulation(int cycles) {
        for (int i = 0; i < cycles; i++) {
            if(i == 2){
                top->rst = 1;
            }
            for (int clk = 0; clk < 2; clk++) {
                top->eval();
#ifndef __APPLE__
                tfp->dump(2 * ticks + clk);
#endif
                top->clk = !top->clk;
            }
            ticks++;

            // ✅ Log u_squared when valid
            // if (top->collider_ready && top->in_collision_state) {
            //     logFile << top->u_squared << "\n";
            // }

            if (Verilated::gotFinish()) {
                break;
            }
        }

        logFile.close();
    }
};

//Make sure to test this using a 50x50 grid or else it will fail
TEST_F(TopTestbench, Equilibrium) {

    auto setBarrierBit = [&](int i) {
        int word = i >> 5;        // divide by 32
        int bit  = i &  31;       // mod 32
        top->barriers.data()[word] |= (1U << bit);
    };

    for (int w = 0; w < (2500+31)/32; ++w) {
        top->barriers.data()[w] = 0;
    }

    for (int i = 0; i < 2500; i++) {
        bool isBarrier = (100 <= i && i < 150) || (2350 < i && i <= 2400 ) || ((i+2) % 50 == 0) || ((i+3) % 50 == 0);
        if (isBarrier) {
            std::cout << "Barrier at " << i << std::endl;
            setBarrierBit(i);
        }
    }
    runSimulation(82399);
    EXPECT_EQ(top->testing_c0_data_in,0x0E38);
}

TEST_F(TopTestbench, Wave) {
    runSimulation(22000);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}