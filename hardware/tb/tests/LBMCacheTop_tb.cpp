#include "test_bench.h"
#include <fstream>

unsigned int ticks = 0;

class LBMCacheTopTestbench : public Testbench {
protected:
    Vdut* LBMCacheTop;
    std::ofstream logFile;

    void initializeInputs() override { 
        LBMCacheTop = top.get();
        LBMCacheTop->clk = 1;
        LBMCacheTop->rst = 0;
        LBMCacheTop->en  = 1;
        LBMCacheTop->step = 1000;
        LBMCacheTop->omega = 0x4000; // 2.0 in Q3.13, tau=0.5
        LBMCacheTop->init_c0 = 0x0E39; // 4/9
        LBMCacheTop->init_cn = 0x038E; // 1/9
        LBMCacheTop->init_cs    = 0x038E;
        LBMCacheTop->init_ce    = 0x0558;
        LBMCacheTop->init_cw    = 0x01cb;
        LBMCacheTop->init_cne   = 0x00E4; // 1/36
        LBMCacheTop->init_cse  = 0x00E4;
        LBMCacheTop->init_csw   = 0x00E4;
        LBMCacheTop->init_cnw   = 0x00E4;

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
                LBMCacheTop->rst = 1;
            }
            for (int clk = 0; clk < 2; clk++) {
                LBMCacheTop->eval();
#ifndef __APPLE__
                tfp->dump(2 * ticks + clk);
#endif
                LBMCacheTop->clk = !LBMCacheTop->clk;
            }
            ticks++;

            // ✅ Log u_squared when valid
            // if (LBMCacheTop->collider_ready && LBMCacheTop->in_collision_state) {
            //     logFile << LBMCacheTop->u_squared << "\n";
            // }

            if (Verilated::gotFinish()) {
                break;
            }
        }

        logFile.close();
    }
};

//Make sure to test this using a 50x50 grid or else it will fail
TEST_F(LBMCacheTopTestbench, Equilibrium) {

    auto setBarrierBit = [&](int i) {
        int word = i >> 5;        // divide by 32
        int bit  = i &  31;       // mod 32
        LBMCacheTop->barriers.data()[word] |= (1U << bit);
    };

    for (int w = 0; w < (2500+31)/32; ++w) {
        LBMCacheTop->barriers.data()[w] = 0;
    }

    for (int i = 0; i < 2500; i++) {
        bool isBarrier = (100 <= i && i < 150) || (2350 < i && i <= 2400 ) || ((i+2) % 50 == 0) || ((i+3) % 50 == 0);
        if (isBarrier) {
            std::cout << "Barrier at " << i << std::endl;
            setBarrierBit(i);
        }
    }
    runSimulation(50000);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}