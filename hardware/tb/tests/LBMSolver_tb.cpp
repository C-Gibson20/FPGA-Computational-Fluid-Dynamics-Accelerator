#include "test_bench.h"

unsigned int ticks = 0;

class LBMSolverTestbench : public Testbench {
protected:
    Vdut* LBMSolver;

        void initializeInputs() override {
        LBMSolver = top.get();  
        LBMSolver->clk = 1;
        LBMSolver->rst = 0;
        LBMSolver->en  = 1;
        LBMSolver->step = 0;
        LBMSolver->omega = 0x4000; // 2.0 in Q3.13, tau=0.5

    }
};

TEST_F(LBMSolverTestbench, BarriersBounce) {
    LBMSolver->barriers[0]= 1;
    LBMSolver->rst = 1;
    runSimulation(7502);
    EXPECT_GE(LBMSolver->testing_cs_n_data_in,0x11);
}

TEST_F(LBMSolverTestbench, BarriersZero) {
    LBMSolver->barriers[0]= 1;
    LBMSolver->rst = 1;
    runSimulation(10002);
    EXPECT_GE(LBMSolver->testing_cs_n_data_in,0x0);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
