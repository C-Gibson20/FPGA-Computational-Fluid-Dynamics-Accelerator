#include "test_bench.h"

unsigned int ticks = 0;

class LBMControllerTestbench : public Testbench {
protected:
    Vdut* LBMController;

        void initializeInputs() override {
        LBMController = top.get(); 
        LBMController->clk = 1;
        LBMController->rst = 0;
        LBMController->en  = 1;
        LBMController->step = 1000;
        LBMController->omega = 0x4000; // 2.0 in Q3.13, tau=0.5
        LBMController->init_c0 = 0x0E38; // 4/9
        LBMController->init_cn = 0x038E; // 1/9
        LBMController->init_cs    = 0x038E;
        LBMController->init_ce    = 0x038E;
        LBMController->init_cw    = 0x038E;
        LBMController->init_cne   = 0x00E4; // 1/36
        LBMController->init_cse  = 0x00E4;
        LBMController->init_csw   = 0x00E4;
        LBMController->init_cnw   = 0x00E4;

    }
};

// TEST_F(LBMControllerTestbench, BarriersBounce) {
//     LBMController->barriers[0]= 1;
//     LBMController->rst = 1;
//     runSimulation(7502);
//     EXPECT_GE(LBMController->testing_cs_n_data_in,0x11);
// }

// TEST_F(LBMControllerTestbench, BarriersZero) {
//     LBMController->barriers[0]= 1;
//     LBMController->rst = 1;
//     runSimulation(10002);
//     EXPECT_GE(LBMController->testing_cs_n_data_in,0x0);
// }

//Make sure to test this using a 50x50 grid or else it will fail
TEST_F(LBMControllerTestbench, Equilibrium) {
    runSimulation(1);
    top->rst = 1;
    // auto setBarrierBit = [&](int i) {
    //     int word = i >> 5;        // divide by 32
    //     int bit  = i &  31;       // mod 32
    //     LBMController->barriers.data()[word] |= (1U << bit);
    // };

    // for (int w = 0; w < (2500+31)/32; ++w) {
    //     LBMController->barriers.data()[w] = 0;
    // }

    // for (int i = 0; i < 2500; i++) {
    //     bool isBarrier = (100 <= i && i < 150) || (2350 < i && i <= 2400 ) || ((i+2) % 50 == 0) || ((i+3) % 50 == 0);
    //     if (isBarrier) {
    //         std::cout << "Barrier at " << i << std::endl;
    //         setBarrierBit(i);
    //     }
    // }
    runSimulation(80000);
    EXPECT_EQ(LBMController->c0_data_in,0x0E38);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
