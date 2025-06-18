#include "base_testbench.h"
#include <gtest/gtest.h>

unsigned int ticks = 0;

class CacheToggleTop : public BaseTestbench {
protected:
    Vdut* s;

    void initializeInputs() override {
        s = top.get();  // Assumes `top` is a std::unique_ptr<Vcache_toggle>
        s->m00_axis_aresetn = 1;
        s->m00_axis_aclk = 1;

        s->chunk_transfer_ready = 0;
        s->chunk_compute_ready = 0;
        s->DDR_addr = 42;  // Default test value

        // Zero out LBM inputs
        s->null1 = s->n1 = s->ne1 = s->e1 = s->se1 = s->s1 = s->sw1 = s->w1 = s->nw1 = 0;
        s->LBM_null_w = s->LBM_n_w = s->LBM_ne_w = s->LBM_e_w = s->LBM_se_w = s->LBM_s_w = s->LBM_sw_w = s->LBM_w_w = s->LBM_nw_w = 0;
    }

    void runSimulation(int cycles = 1) {
        for (int i = 0; i < cycles; i++) {
            for (int m00_axis_aclk = 0; m00_axis_aclk < 2; m00_axis_aclk++) {
                top->eval();
#ifndef __APPLE__
                tfp->dump(2 * ticks + m00_axis_aclk);
#endif
                top->m00_axis_aclk = !top->m00_axis_aclk;
            }
            ticks++;

            if (Verilated::gotFinish()) {
                exit(0);
            }
        }
    }
};

TEST_F(CacheToggleTop, TestChunkTransfer) {
    s->DDR_addr = 100;
    s->chunk_transfer_ready = 1;
    runSimulation(2);
    s->chunk_transfer_ready = 0;
    runSimulation(1);

    EXPECT_EQ(s->null1_out, 100);
    EXPECT_EQ(s->e1_out, 100);
    EXPECT_EQ(s->nw1_out, 100);
    EXPECT_EQ(s->null1_wen, 1);
    EXPECT_EQ(s->nw1_wen, 1);
}

TEST_F(CacheToggleTop, TestChunkCompute) {
    s->chunk_compute_ready = 1;

    s->null1 = 10; s->n1 = 11; s->ne1 = 12;
    s->e1 = 13; s->se1 = 14; s->s1 = 15;
    s->sw1 = 16; s->w1 = 17; s->nw1 = 18;

    s->LBM_null_w = 1;
    s->LBM_n_w = 0;
    s->LBM_ne_w = 1;
    s->LBM_e_w = 0;
    s->LBM_se_w = 1;
    s->LBM_s_w = 0;
    s->LBM_sw_w = 1;
    s->LBM_w_w = 0;
    s->LBM_nw_w = 1;

    runSimulation(2);
    s->chunk_compute_ready = 0;
    s->chunk_transfer_ready = 1;
    runSimulation(1);

    EXPECT_EQ(s->null1_out, 10);
    EXPECT_EQ(s->nw1_out, 18);
    EXPECT_EQ(s->null1_wen, 1);
    EXPECT_EQ(s->n1_wen, 0);
    EXPECT_EQ(s->se1_wen, 1);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
