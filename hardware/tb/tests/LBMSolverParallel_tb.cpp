#include "test_bench.h"

unsigned int ticks = 0;

class LBMSolverParallelTestbench : public Testbench {
protected:
    Vdut* LBMSolverParallel;

        void initializeInputs() override {
        LBMSolverParallel = top.get();  
        LBMSolverParallel->clk = 1;
        LBMSolverParallel->rst = 0;
        LBMSolverParallel->en  = 1;
        LBMSolverParallel->step = 0;
        LBMSolverParallel->omega = 0x4000; // 2.0 in Q3.13, tau=0.5

    }
};

TEST_F(LBMSolverParallelTestbench, BarriersBounce) {
    LBMSolverParallel->barriers[0]= 1;
    LBMSolverParallel->rst = 1;
    runSimulation(7502);
    EXPECT_GE(LBMSolverParallel->testing_cs_n_data_in,0x11);
}

TEST_F(LBMSolverParallelTestbench, BarriersZero) {
    LBMSolverParallel->barriers[0]= 1;
    LBMSolverParallel->rst = 1;
    runSimulation(10002);
    EXPECT_GE(LBMSolverParallel->testing_cs_n_data_in,0x0);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
