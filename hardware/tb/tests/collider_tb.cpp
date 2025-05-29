#include "base_testbench.h"

unsigned int ticks = 0;

class ColliderTestbench : public BaseTestbench {
protected:
    Vdut* collider;

    void initializeInputs() override {
        collider = top.get();
        collider->f_null = 0x0E39;  // 4/9 * 8192 ≈ 3641
        collider->f_n    = 0x038E;  // 1/9 * 8192 ≈ 910
        collider->f_s    = 0x038E;
        collider->f_e    = 0x038E;
        collider->f_w    = 0x038E;
        collider->f_ne   = 0x00E4;  // 1/36 * 8192 ≈ 227
        collider->f_se   = 0x00E4;
        collider->f_nw   = 0x00E4;
        collider->f_sw   = 0x00E4;
    }
};

TEST_F(ColliderTestbench, CanItCompile) {
    EXPECT_GE(collider->collider_busy, 0);
}

TEST_F(ColliderTestbench, AtEquilibrium_NoChange) {
    collider->eval();
    EXPECT_EQ(collider->new_f_null, collider->f_null);
    EXPECT_EQ(collider->new_f_n, collider->f_n);
    EXPECT_EQ(collider->new_f_s, collider->f_s);
    EXPECT_EQ(collider->new_f_e, collider->f_e);
    EXPECT_EQ(collider->new_f_w, collider->f_w);
    EXPECT_EQ(collider->new_f_ne, collider->f_ne);
    EXPECT_EQ(collider->new_f_se, collider->f_se);
    EXPECT_EQ(collider->new_f_nw, collider->f_nw);
    EXPECT_EQ(collider->new_f_sw, collider->f_sw);
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
