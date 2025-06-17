#include "test_bench.h"

unsigned int ticks = 0;

class ColliderPipelinedTestbench : public Testbench {
protected:
    Vdut* collider;
    
    void initializeInputs() override {
        collider = top.get();
        collider->omega = 0x4000;
        collider->rst = 1;
        collider->en = 1;
    }

    void loadEquilibriumValues() {
        collider->f_null = 0x0E38; // 4/9
        collider->f_n    = 0x038E; // 1/9
        collider->f_s    = 0x038E;
        collider->f_e    = 0x038E;
        collider->f_w    = 0x038E;
        collider->f_ne   = 0x00E4; // 1/36
        collider->f_se   = 0x00E4;
        collider->f_sw   = 0x00E4;
        collider->f_nw   = 0x00E4;
    }
};

TEST_F(ColliderPipelinedTestbench, AtEquilibrium_NoChange) {
    loadEquilibriumValues();
    runSimulation(21);
    collider->eval();

    // Confirm outputs remain unchanged
    // Allow ±2 leeway for rounding error
    EXPECT_NEAR(collider->f_new_null, collider->f_null, 2);
    EXPECT_EQ(collider->f_new_n,    collider->f_n);
    EXPECT_EQ(collider->f_new_s,    collider->f_s);
    EXPECT_EQ(collider->f_new_e,    collider->f_e);
    EXPECT_EQ(collider->f_new_w,    collider->f_w);
    EXPECT_EQ(collider->f_new_ne,   collider->f_ne);
    EXPECT_EQ(collider->f_new_se,   collider->f_se);
    EXPECT_EQ(collider->f_new_sw,   collider->f_sw);
    EXPECT_EQ(collider->f_new_nw,   collider->f_nw);
}

TEST_F(ColliderPipelinedTestbench, SmallEastwardSpeed) {
    collider->f_null = 0x0E39; // 4/9
    collider->f_n    = 0x038E; // 1/9
    collider->f_s    = 0x038E; 
    collider->f_e    = 0x0558; // ~0.167 (boosted east) 3/18
    collider->f_w    = 0x01cb; // ~0.056 (reduced west) 1/18
    collider->f_ne   = 0x00E4; // 1/36
    collider->f_se   = 0x00E4;
    collider->f_sw   = 0x00E4;
    collider->f_nw   = 0x00E4;
    runSimulation(21);
    collider->eval();
    EXPECT_NEAR(collider->f_new_null, 3514, 1);
    EXPECT_NEAR(collider->f_new_n,     878, 1);
    EXPECT_NEAR(collider->f_new_s,    878, 1);
    EXPECT_NEAR(collider->f_new_e,   1127, 1);
    EXPECT_NEAR(collider->f_new_w,    824, 1);
    EXPECT_NEAR(collider->f_new_ne,   396, 1);
    EXPECT_NEAR(collider->f_new_se,   396, 1);
    EXPECT_NEAR(collider->f_new_sw,    93, 1);
    EXPECT_NEAR(collider->f_new_nw,    93, 1);
}


TEST_F(ColliderPipelinedTestbench, StrongNorthwardSpeed) {
    collider->f_null = 0x0E38;
    collider->f_n    = 0x05C0; // Boosted north
    collider->f_s    = 0x0180; // Weakened south
    collider->f_e    = 0x038E;
    collider->f_w    = 0x038E;
    collider->f_ne   = 0x0120;
    collider->f_se   = 0x0090;
    collider->f_sw   = 0x0090;
    collider->f_nw   = 0x0120;
    runSimulation(21);
    collider->eval();
    tfp->dump(ticks++);
    EXPECT_NEAR(collider->f_new_null, 3322, 2);
    EXPECT_NEAR(collider->f_new_n,    1417, 1);
    EXPECT_NEAR(collider->f_new_s,     671, 1);
    EXPECT_NEAR(collider->f_new_e,     831, 1);
    EXPECT_NEAR(collider->f_new_w,     831, 1);
    EXPECT_NEAR(collider->f_new_ne,    434, 1);
    EXPECT_NEAR(collider->f_new_se,    120, 1);
    EXPECT_NEAR(collider->f_new_sw,    120, 1);
    EXPECT_NEAR(collider->f_new_nw,    434, 1);
}

TEST_F(ColliderPipelinedTestbench, DiagonalNorthEastFlow) {
    collider->f_null = 0x0E38;
    collider->f_n    = 0x038E;
    collider->f_s    = 0x038E;
    collider->f_e    = 0x038E;
    collider->f_w    = 0x038E;
    collider->f_ne   = 0x0150; // More NE
    collider->f_se   = 0x00E4;
    collider->f_sw   = 0x0090; // Less SW
    collider->f_nw   = 0x00E4;

    runSimulation(21);
    collider->eval();
    tfp->dump(ticks++);
    EXPECT_NEAR(collider->f_new_null, 3651, 3);
    EXPECT_NEAR(collider->f_new_n,    1045, 3);
    EXPECT_NEAR(collider->f_new_s,     789, 3);
    EXPECT_NEAR(collider->f_new_e,    1045, 3);
    EXPECT_NEAR(collider->f_new_w,     789, 3);
    EXPECT_NEAR(collider->f_new_ne,    188, 3);
    EXPECT_NEAR(collider->f_new_se,    228, 3);
    EXPECT_NEAR(collider->f_new_sw,    252, 3);
    EXPECT_NEAR(collider->f_new_nw,    228, 3);
}

TEST_F(ColliderPipelinedTestbench, ConservesMass) {
    loadEquilibriumValues();
    runSimulation(21);
    collider->eval();

    uint16_t total_before = collider->f_null + collider->f_n + collider->f_s +
                            collider->f_e + collider->f_w +
                            collider->f_ne + collider->f_se +
                            collider->f_sw + collider->f_nw;

    uint16_t total_after = collider->f_new_null + collider->f_new_n + collider->f_new_s +
                           collider->f_new_e + collider->f_new_w +
                           collider->f_new_ne + collider->f_new_se +
                           collider->f_new_sw + collider->f_new_nw;

    EXPECT_EQ(total_before, total_after);// small tolerance for fixed-point error
}

TEST_F(ColliderPipelinedTestbench, inputZero) {
    collider->f_null = 0x0000;
    collider->f_n    = 0x0000;
    collider->f_s    = 0x0000;
    collider->f_e    = 0x0000;
    collider->f_w    = 0x0000;
    collider->f_ne   = 0x0000;
    collider->f_se   = 0x0000;
    collider->f_sw   = 0x0000;
    collider->f_nw   = 0x0000;
    runSimulation(21);
    collider->eval();
    tfp->dump(ticks++);
    EXPECT_EQ(collider->f_new_null, 0);
    EXPECT_EQ(collider->f_new_n,    0);
    EXPECT_EQ(collider->f_new_s,    0);
    EXPECT_EQ(collider->f_new_e,    0);
    EXPECT_EQ(collider->f_new_w,    0);
    EXPECT_EQ(collider->f_new_ne,   0);
    EXPECT_EQ(collider->f_new_se,   0);
    EXPECT_EQ(collider->f_new_sw,   0);
    EXPECT_EQ(collider->f_new_nw,   0);
}

TEST_F(ColliderPipelinedTestbench, the1daytest) {
    collider->f_null = 0x0E06;
    collider->f_n    = 0x037F;
    collider->f_s    = 0x0385;
    collider->f_e    = 0x04BB;
    collider->f_w    = 0x0298;
    collider->f_ne   = 0x012F;
    collider->f_se   = 0x012F;
    collider->f_sw   = 0x00A6;
    collider->f_nw   = 0x00A6;
    runSimulation(21);
    collider->eval();
    tfp->dump(ticks++);
    EXPECT_NEAR(collider->f_new_null, 3588, 3);
    EXPECT_NEAR(collider->f_new_n,    896, 3);
    EXPECT_NEAR(collider->f_new_s,    898, 3);
    EXPECT_NEAR(collider->f_new_e,    1213, 3);
    EXPECT_NEAR(collider->f_new_w,    665, 3);
    EXPECT_NEAR(collider->f_new_ne,   302, 3);
    EXPECT_NEAR(collider->f_new_se,   304, 3);
    EXPECT_NEAR(collider->f_new_sw,   167, 3);
    EXPECT_NEAR(collider->f_new_nw,   166, 3);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}