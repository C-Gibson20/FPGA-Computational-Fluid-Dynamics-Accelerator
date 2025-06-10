#include "base_testbench.h"

unsigned int ticks = 0;

class ColliderTestbench : public BaseTestbench {
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

    int16_t float_to_q313(float x) {
        // Clamp to Q3.13 range
        if (x > 3.99987793f) x = 3.99987793f;
        if (x < -4.0f)       x = -4.0f;
        return static_cast<int16_t>(roundf(x * 8192.0f));
    }
};

TEST_F(ColliderTestbench, AtEquilibrium_NoChange) {
    loadEquilibriumValues();
    collider->eval();

    // Confirm outputs remain unchanged
    EXPECT_EQ(collider->f_new_null, collider->f_null);
    EXPECT_EQ(collider->f_new_n,    collider->f_n);
    EXPECT_EQ(collider->f_new_s,    collider->f_s);
    EXPECT_EQ(collider->f_new_e,    collider->f_e);
    EXPECT_EQ(collider->f_new_w,    collider->f_w);
    EXPECT_EQ(collider->f_new_ne,   collider->f_ne);
    EXPECT_EQ(collider->f_new_se,   collider->f_se);
    EXPECT_EQ(collider->f_new_sw,   collider->f_sw);
    EXPECT_EQ(collider->f_new_nw,   collider->f_nw);
}

TEST_F(ColliderTestbench, SmallEastwardSpeed) {
    collider->f_null = 0x0E39; // 4/9
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
    tfp->dump(ticks++);
    EXPECT_NEAR(collider->f_new_null, 3527, 3); // Uses mass conservation: f_new_null = rho - sum(f_new_i); ~3514 if skipped
    EXPECT_NEAR(collider->f_new_n,    878, 3);
    EXPECT_NEAR(collider->f_new_s,    878, 3);
    EXPECT_NEAR(collider->f_new_e, 1127, 3);
    EXPECT_NEAR(collider->f_new_w, 824, 3);
    EXPECT_NEAR(collider->f_new_ne,   396, 3);
    EXPECT_NEAR(collider->f_new_se,   396, 3);
    EXPECT_NEAR(collider->f_new_sw,   93, 3);
    EXPECT_NEAR(collider->f_new_nw,   93, 3);
}

TEST_F(ColliderTestbench, StrongNorthwardSpeed) {
    collider->f_null = 0x0E38;
    collider->f_n    = 0x05C0; // Boosted north
    collider->f_s    = 0x0180; // Weakened south
    collider->f_e    = 0x038E;
    collider->f_w    = 0x038E;
    collider->f_ne   = 0x0120;
    collider->f_se   = 0x0090;
    collider->f_sw   = 0x0090;
    collider->f_nw   = 0x0120;

    collider->eval();
    tfp->dump(ticks++);
    EXPECT_NEAR(collider->f_new_null, 3338, 3); // Uses mass conservation: f_new_null = rho - sum(f_new_i); ~3322 if skipped
    EXPECT_NEAR(collider->f_new_n,    1417, 3);
    EXPECT_NEAR(collider->f_new_s,    671, 3);
    EXPECT_NEAR(collider->f_new_e, 831, 3);
    EXPECT_NEAR(collider->f_new_w, 831, 3);
    EXPECT_NEAR(collider->f_new_ne,   434, 3);
    EXPECT_NEAR(collider->f_new_se,   120, 3);
    EXPECT_NEAR(collider->f_new_sw,   120, 3);
    EXPECT_NEAR(collider->f_new_nw,  434, 3);
}

TEST_F(ColliderTestbench, DiagonalNorthEastFlow) {
    collider->f_null = 0x0E38;
    collider->f_n    = 0x038E;
    collider->f_s    = 0x038E;
    collider->f_e    = 0x038E;
    collider->f_w    = 0x038E;
    collider->f_ne   = 0x0150; // More NE
    collider->f_se   = 0x00E4;
    collider->f_sw   = 0x0090; // Less SW
    collider->f_nw   = 0x00E4;

    collider->eval();
    tfp->dump(ticks++);
    EXPECT_NEAR(collider->f_new_null, 3668, 3); // Uses mass conservation: f_new_null = rho - sum(f_new_i); ~3651 if skipped
    EXPECT_NEAR(collider->f_new_n,    1045, 3);
    EXPECT_NEAR(collider->f_new_s,    789, 3);
    EXPECT_NEAR(collider->f_new_e, 1045, 3);
    EXPECT_NEAR(collider->f_new_w, 789, 3);
    EXPECT_NEAR(collider->f_new_ne,   188, 3);
    EXPECT_NEAR(collider->f_new_se,   228, 3);
    EXPECT_NEAR(collider->f_new_sw,   252, 3);
    EXPECT_NEAR(collider->f_new_nw,  228, 3);
}

TEST_F(ColliderTestbench, ConservesMass) {
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

    EXPECT_EQ(total_before, total_after);
}

TEST_F(ColliderTestbench, inputZero) {
    collider->f_null = 0x0000;
    collider->f_n    = 0x0000;
    collider->f_s    = 0x0000;
    collider->f_e    = 0x0000;
    collider->f_w    = 0x0000;
    collider->f_ne   = 0x0000;
    collider->f_se   = 0x0000;
    collider->f_sw   = 0x0000;
    collider->f_nw   = 0x0000;

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

TEST_F(ColliderTestbench, randomtest) {
    collider->f_null = 0x0E06;
    collider->f_n    = 0x037F;
    collider->f_s    = 0x0385;
    collider->f_e    = 0x04BB;
    collider->f_w    = 0x0298;
    collider->f_ne   = 0x012F;
    collider->f_se   = 0x012F;
    collider->f_sw   = 0x00A6;
    collider->f_nw   = 0x00A6;

    collider->eval();
    tfp->dump(ticks++);
    EXPECT_EQ(collider->f_new_null, 3588);
    EXPECT_EQ(collider->f_new_n,    896);
    EXPECT_EQ(collider->f_new_s,    898);
    EXPECT_EQ(collider->f_new_e,    1213);
    EXPECT_EQ(collider->f_new_w,    665);
    EXPECT_EQ(collider->f_new_ne,   302);
    EXPECT_EQ(collider->f_new_se,   304);
    EXPECT_EQ(collider->f_new_sw,   167);
    EXPECT_EQ(collider->f_new_nw,   166);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
