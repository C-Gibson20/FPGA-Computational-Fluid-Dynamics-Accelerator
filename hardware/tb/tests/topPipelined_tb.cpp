#include "test_bench.h"

unsigned int ticks = 0;

class TopPipelinedTestbench : public Testbench {
protected:

    void initializeInputs() override {
        top->clk = 1;
        top->rst = 0;
        top->en  = 1;
        top->step = 1000;
        top->omega = 0x4000;
        top->init_c0    = 0x0E38;
        top->init_cn    = 0x038E;
        top->init_cne   = 0x00EA;
        top->init_ce    = 0x03AA;
        top->init_cse   = 0x00EA;
        top->init_cs    = 0x038E;
        top->init_csw   = 0x00DD;
        top->init_cw    = 0x0373;
        top->init_cnw   = 0x00DD;
    }
};

TEST_F(TopPipelinedTestbench, Wavebb) {
    runSimulation(2);
    top->rst = 1;
    runSimulation(75000);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}