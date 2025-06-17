#include "base_testbench.h"
#include <gtest/gtest.h>

unsigned int ticks = 0;

class BRAMCtrlTop : public BaseTestbench {
protected:
    Vdut* s;
    
    void initializeInputs() override {
        s = top.get();
        s->m00_axis_aresetn = 1;
        s->m00_axis_aclk = 1;
    }

    void runSimulation(int cycles = 1)
    {
        for (int i = 0; i < cycles; i++)
        {
            for (int m00_axis_aclk = 0; m00_axis_aclk < 2; m00_axis_aclk++)
            {
                top->eval();
#ifndef __APPLE__
                tfp->dump(2 * ticks + m00_axis_aclk);
#endif
                top->m00_axis_aclk = !top->m00_axis_aclk;
            }
            ticks++;

            if (Verilated::gotFinish())
            {
                exit(0);
            }
        }
    }

};

TEST_F(BRAMCtrlTop, TestDataLoad) {
    s->m00_axis_tready = 1;
    s->chunk_transfer_ready = 1;
    runSimulation(10);
    s->chunk_transfer_ready = 0;
    runSimulation(10);
    s->chunk_transfer_ready = 1;
    runSimulation(5);

}

TEST_F(BRAMCtrlTop, TestDataLoad2) {
    s->m00_axis_tready = 1;
    s->chunk_transfer_ready = 0;
    runSimulation(10);
    s->chunk_transfer_ready = 1;
    runSimulation(5);

}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}