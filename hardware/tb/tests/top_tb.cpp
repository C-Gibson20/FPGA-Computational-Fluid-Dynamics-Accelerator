#include "test_bench.h"

unsigned int ticks = 0;

class TopTestbench : public Testbench {
protected:

    void initializeInputs() override { 
        top->clk = 1;
        top->rst = 1;
        top->en  = 1;
        top->step = 1000;
        top->omega = 0x4000; // 2.0 in Q3.13, tau=0.5

    }
};

// TEST_F(TopTestbench, BarriersBounce) {
//     top->barriers |= (1 << 0); // set barrier[0] = 1
//     runSimulation(11);
//     EXPECT_GE(top->testing_cs_n_data_in,0x11);
// }

// TEST_F(TopTestbench, BarriersZero) {
//     top->barriers |= (1 << 0); // set barrier[0] = 1
//     runSimulation(14);
//     EXPECT_GE(top->testing_cs_n_data_in,0x0);
// }

// TEST_F(TopTestbench, idk) {
//     top->barriers = 0xF99F; 
//     runSimulation(4000);
// }

// TEST_F(TopTestbench, irdk) {
//     top->barriers = 0x0420; 
//     runSimulation(8000);
// }
// assuming `DEPTH` bits wide, i in [0..DEPTH-1]

TEST_F(TopTestbench, kii) {

    auto setBarrierBit = [&](int i) {
        int word = i >> 5;        // divide by 32
        int bit  = i &  31;       // mod 32
        top->barriers.data()[word] |= (1U << bit);
    };

    // first zero all words
    for (int w = 0; w < (2500+31)/32; ++w) {
        top->barriers.data()[w] = 0;
    }

    // now set the bits you actually want
    for (int i = 0; i < 2500; i++) {
        bool isBarrier = (i < 50) || (i >= 2450) || (i % 50 == 0) || ((i+1) % 50 == 0);
        if (isBarrier) {
            std::cout << "Barrier at " << i << std::endl;
            setBarrierBit(i);
        }
    }
    runSimulation(80000);

}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}