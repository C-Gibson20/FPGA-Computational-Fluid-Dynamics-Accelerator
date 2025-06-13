#include "test_bench.h"

unsigned int ticks = 0;

class LBMSolverPipelinedTestbench : public Testbench {
protected:
    Vdut* LBMSolverPipelined;

    void initializeInputs() override {
        LBMSolverPipelined = top.get();
        LBMSolverPipelined->rst = 0;
        LBMSolverPipelined->step = 3;
        LBMSolverPipelined->omega = 0x4000; 
        LBMSolverPipelined->init_c0    = 0x0E38;
        LBMSolverPipelined->init_cn    = 0x038E;
        LBMSolverPipelined->init_cs    = 0x038E;
        LBMSolverPipelined->init_ce    = 0x03AA;
        LBMSolverPipelined->init_cw    = 0x0298;
        LBMSolverPipelined->init_cne   = 0x00EA;
        LBMSolverPipelined->init_cse   = 0x00EA;        
        LBMSolverPipelined->init_cnw   = 0x00A6;
        LBMSolverPipelined->init_csw   = 0x00DD;
    }
};

TEST_F(LBMSolverPipelinedTestbench, LookAtTheWaves) {
    runSimulation(1);
    LBMSolverPipelined->rst = 1;
    runSimulation(30000);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}