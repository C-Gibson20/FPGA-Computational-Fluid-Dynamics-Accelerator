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
        LBMController->step = 0;
        LBMController->omega = 0x4000; // 2.0 in Q3.13, tau=0.5

    }
};

TEST_F(LBMControllerTestbench, BarriersBounce) {
    LBMController->barriers[0]= 1;
    LBMController->rst = 1;
    runSimulation(7502);
    EXPECT_GE(LBMController->testing_cs_n_data_in,0x11);
}

TEST_F(LBMControllerTestbench, BarriersZero) {
    LBMController->barriers[0]= 1;
    LBMController->rst = 1;
    runSimulation(10002);
    EXPECT_GE(LBMController->testing_cs_n_data_in,0x0);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
