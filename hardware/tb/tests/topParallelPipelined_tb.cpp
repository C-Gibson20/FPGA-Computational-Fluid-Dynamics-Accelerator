#include "test_bench.h"

unsigned int ticks = 0;

class topParallelPipelinedTestbench : public Testbench {
protected:
    Vdut* topParallelPipelined;

    void initializeInputs() override { 
        topParallelPipelined = top.get();
        topParallelPipelined->clk = 1;
        topParallelPipelined->rst = 0;
        topParallelPipelined->en  = 1;
        topParallelPipelined->step = 1000;
        topParallelPipelined->omega = 0x4000; // 2.0 in Q3.13, tau=0.5
        topParallelPipelined->init_c0 = 0x0E39; // 4/9
        topParallelPipelined->init_cn = 0x038E; // 1/9
        topParallelPipelined->init_cs    = 0x038E;
        topParallelPipelined->init_ce    = 0x0558;
        topParallelPipelined->init_cw    = 0x01cb;
        topParallelPipelined->init_cne   = 0x00E4; // 1/36
        topParallelPipelined->init_cse  = 0x00E4;
        topParallelPipelined->init_csw   = 0x00E4;
        topParallelPipelined->init_cnw   = 0x00E4;
    }
};

//Make sure to test this using a 50x50 grid or else it will fail
TEST_F(topParallelPipelinedTestbench, Equilibrium) {

    auto setBarrierBit = [&](int i) {
        int word = i >> 5;        // divide by 32
        int bit  = i &  31;       // mod 32
        topParallelPipelined->barriers.data()[word] |= (1U << bit);
    };

    for (int w = 0; w < (2500+31)/32; ++w) {
        topParallelPipelined->barriers.data()[w] = 0;
    }

    // for (int i = 0; i < 2500; i++) {
    //     bool isBarrier = (100 <= i && i < 150) || (2350 < i && i <= 2400 ) || ((i+2) % 50 == 0) || ((i+3) % 50 == 0);
    //     if (isBarrier) {
    //         std::cout << "Barrier at " << i << std::endl;
    //         setBarrierBit(i);
    //     }
    // }
    runSimulation(2);
    topParallelPipelined->rst = 1;
    runSimulation(20000);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}