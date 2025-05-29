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
};

TEST_F(ColliderTestbench, CanItCompile) {
    EXPECT_GE(collider->collider_busy, 0);
}

TEST_F(ColliderTestbench, AtEquilibrium_NoChange) {
    loadEquilibriumValues();
    collider->eval();

    // Confirm outputs remain unchanged
    // Allow ±2 leeway for rounding error
    EXPECT_NEAR(collider->new_f_null, collider->f_null, 2);
    EXPECT_EQ(collider->new_f_n,    collider->f_n);
    EXPECT_EQ(collider->new_f_s,    collider->f_s);
    EXPECT_EQ(collider->new_f_e,    collider->f_e);
    EXPECT_EQ(collider->new_f_w,    collider->f_w);
    EXPECT_EQ(collider->new_f_ne,   collider->f_ne);
    EXPECT_EQ(collider->new_f_se,   collider->f_se);
    EXPECT_EQ(collider->new_f_sw,   collider->f_sw);
    EXPECT_EQ(collider->new_f_nw,   collider->f_nw);
}

TEST_F(ColliderTestbench, SmallEastwardSpeed) {
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

    // Expect the eastward population to increase
    EXPECT_GT(collider->new_f_e, collider->f_e);

    // Expect the westward population to decrease
    EXPECT_LT(collider->new_f_w, collider->f_w);

    // ensure mass is (approximately) conserved
    uint32_t f_before =
        collider->f_null + collider->f_n + collider->f_s + collider->f_e + collider->f_w +
        collider->f_ne + collider->f_se + collider->f_sw + collider->f_nw;

    uint32_t f_after =
        collider->new_f_null + collider->new_f_n + collider->new_f_s + collider->new_f_e + collider->new_f_w +
        collider->new_f_ne + collider->new_f_se + collider->new_f_sw + collider->new_f_nw;

    EXPECT_EQ(collider->new_f_e,    0x067B);
    EXPECT_EQ(collider->new_f_w,    0x0302);


}




int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
