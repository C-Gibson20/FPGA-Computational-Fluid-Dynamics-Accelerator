#include "test_bench.h"
#include <fstream>

unsigned int ticks = 0;

class MYFUckTestBEch : public Testbench {
protected:
    Vdut* s;
    std::ofstream logFile;

    void initializeInputs() override { 
        s = top.get();
        s->clk = 1;
        s->rst = 0;
        s->en  = 1;
        s->step = 1000;
        s->omega = 0x4000; // 2.0 in Q3.13, tau=0.5
        s->init_c0 = 0x0E39; // 4/9
        s->init_cn = 0x038E; // 1/9
        s->init_cs    = 0x038E;
        s->init_ce    = 0x0558;
        s->init_cw    = 0x01cb;
        s->init_cne   = 0x00E4; // 1/36
        s->init_cse  = 0x00E4;
        s->init_csw   = 0x00E4;
        s->init_cnw   = 0x00E4;
        s->m00_axis_tready = 0;

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
                s->rst = 1;
            }
            for (int clk = 0; clk < 2; clk++) {
                s->eval();
#ifndef __APPLE__
                tfp->dump(2 * ticks + clk);
#endif
                s->clk = !s->clk;
            }
            ticks++;

            // ✅ Log u_squared when valid
            // if (s->collider_ready && s->in_collision_state) {
            //     logFile << s->u_squared << "\n";
            // }

            if (Verilated::gotFinish()) {
                break;
            }
        }

        logFile.close();
    }
};

//Make sure to test this using a 50x50 grid or else it will fail
TEST_F(MYFUckTestBEch, Equilibrium) {

    auto setBarrierBit = [&](int i) {
        int word = i >> 5;        // divide by 32
        int bit  = i &  31;       // mod 32
        s->barriers.data()[word] |= (1U << bit);
    };

    for (int w = 0; w < (2500+31)/32; ++w) {
        s->barriers.data()[w] = 0;
    }

    for (int i = 0; i < 2500; i++) {
        bool isBarrier = (100 <= i && i < 150) || (2350 < i && i <= 2400 ) || ((i+2) % 50 == 0) || ((i+3) % 50 == 0);
        if (isBarrier) {
            std::cout << "Barrier at " << i << std::endl;
            setBarrierBit(i);
        }
    }
    runSimulation(20000);

    s->m00_axis_tready = 1;

    runSimulation(50);

    s->m00_axis_tready = 0;

    runSimulation(10);

    s->m00_axis_tready = 1;

    runSimulation(10000);

    s->m00_axis_tready = 0;

    runSimulation(1000);

    s->m00_axis_tready = 1;

    runSimulation(50000);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}