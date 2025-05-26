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
    }
};

TEST_F(LBMSolverTestbench, CanItCompile) {
    runSimulation(10);
    EXPECT_GE(LBMSolver->en, 0);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
