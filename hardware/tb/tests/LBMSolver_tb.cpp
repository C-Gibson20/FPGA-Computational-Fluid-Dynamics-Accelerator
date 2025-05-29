#include "test_bench.h"

unsigned int ticks = 0;

class LBMSolverTestbench : public Testbench {
protected:
    Vdut* LBMSolver;

        void initializeInputs() override {
        LBMSolver = top.get();  
        LBMSolver->clk = 1;
        LBMSolver->rst = 1;
        LBMSolver->en  = 1;
        LBMSolver->step = 0;
        LBMSolver->omega = 0x4000; // 2.0 in Q3.13, tau=0.5
        LBMSolver->c0_data_out = 0;

    }
};

TEST_F(LBMSolverTestbench, CanItCompile) {
    runSimulation(1);
    LBMSolver->rst = 0;
    runSimulation(3000);
    EXPECT_GE(LBMSolver->en, 0);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
