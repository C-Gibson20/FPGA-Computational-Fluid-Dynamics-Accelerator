#include "base_testbench.h"

unsigned int ticks = 0;

class ColliderDivideTestbench : public BaseTestbench {
protected:
    Vdut* collider;

    void initializeInputs() override {
        collider = top.get();
        collider->omega = 0x4000; // 2.0 in Q3.13, tau=0.5
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

TEST_F(ColliderDivideTestbench, AtEquilibrium_NoChange) {
    loadEquilibriumValues();
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

TEST_F(ColliderDivideTestbench, SmallEastwardSpeed) {
    collider->f_null = 0x0E38; // 4/9
    collider->f_n    = 0x038E; // 1/9
    collider->f_s    = 0x038E; 
    collider->f_e    = 0x0558; // ~0.167 (boosted east) 3/18
    collider->f_w    = 0x01cb; // ~0.056 (reduced west) 1/18
    collider->f_ne   = 0x00E4; // 1/36
    collider->f_se   = 0x00E4;
    collider->f_sw   = 0x00E4;
    collider->f_nw   = 0x00E4;

    // Run one evaluation cycle
    collider->eval();
    EXPECT_LT(collider->f_new_e, collider->f_e);
    EXPECT_GT(collider->f_new_w, collider->f_w);
}

TEST_F(ColliderDivideTestbench, StrongNorthwardSpeed) {
    collider->f_null = 0x0E39;
    collider->f_n    = 0x05C0; // Boosted north
    collider->f_s    = 0x0180; // Weakened south
    collider->f_e    = 0x038E;
    collider->f_w    = 0x038E;
    collider->f_ne   = 0x0120;
    collider->f_se   = 0x0090;
    collider->f_sw   = 0x0090;
    collider->f_nw   = 0x0120;

    collider->eval();

    EXPECT_LT(collider->f_new_n, collider->f_n);
    EXPECT_GT(collider->f_new_s, collider->f_s);
}

TEST_F(ColliderDivideTestbench, DiagonalNorthEastFlow) {
    collider->f_null = 0x0E39;
    collider->f_ne   = 0x0150; // More NE
    collider->f_sw   = 0x0090; // Less SW
    collider->f_n    = 0x038E;
    collider->f_s    = 0x038E;
    collider->f_e    = 0x038E;
    collider->f_w    = 0x038E;
    collider->f_se   = 0x00E4;
    collider->f_nw   = 0x00E4;

    collider->eval();

    EXPECT_LT(collider->f_new_ne, collider->f_ne);
    EXPECT_GT(collider->f_new_sw, collider->f_sw);
}

TEST_F(ColliderDivideTestbench, ConservesMass) {
    loadEquilibriumValues();
    collider->eval();

    uint16_t total_before = collider->f_null + collider->f_n + collider->f_s +
                            collider->f_e + collider->f_w +
                            collider->f_ne + collider->f_se +
                            collider->f_sw + collider->f_nw;

    uint16_t total_after = collider->f_new_null + collider->f_new_n + collider->f_new_s +
                           collider->f_new_e + collider->f_new_w +
                           collider->f_new_ne + collider->f_new_se +
                           collider->f_new_sw + collider->f_new_nw;

    EXPECT_NEAR(total_before, total_after, 4); // small tolerance for fixed-point error
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
