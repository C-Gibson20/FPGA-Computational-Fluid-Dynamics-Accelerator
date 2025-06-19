#include "test_bench.h"

unsigned int ticks = 0;

class topParallelTestbench : public Testbench {
protected:
    Vdut* topParallel;

    void initializeInputs() override { 
        topParallel = top.get();
        topParallel->clk = 1;
        topParallel->rst = 0;
        topParallel->en  = 1;
        topParallel->step = 1000;
        topParallel->omega = 0x4000; // 2.0 in Q3.13, tau=0.5
        topParallel->init_c0 = 0x0E39; // 4/9
        topParallel->init_cn = 0x038E; // 1/9
        topParallel->init_cs    = 0x038E;
        topParallel->init_ce    = 0x0558;
        topParallel->init_cw    = 0x01cb;
        topParallel->init_cne   = 0x00E4; // 1/36
        topParallel->init_cse  = 0x00E4;
        topParallel->init_csw   = 0x00E4;
        topParallel->init_cnw   = 0x00E4;
    }

};

//Make sure to test this using a 50x50 grid or else it will fail
TEST_F(topParallelTestbench, Equilibrium) {

    // auto setBarrierBit = [&](int i) {
    //     int word = i >> 5;        // divide by 32
    //     int bit  = i &  31;       // mod 32
    //     topParallel->barriers.data()[word] |= (1U << bit);
    // };

    // for (int w = 0; w < (2500+31)/32; ++w) {
    //     topParallel->barriers.data()[w] = 0;
    // }

    // for (int i = 0; i < 2500; i++) {
    //     bool isBarrier = (100 <= i && i < 150) || (2350 < i && i <= 2400 ) || ((i+2) % 50 == 0) || ((i+3) % 50 == 0);
    //     if (isBarrier) {
    //         std::cout << "Barrier at " << i << std::endl;
    //         setBarrierBit(i);
    //     }
    // }
    runSimulation(2);
    topParallel->rst = 1;
    runSimulation(50000);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}