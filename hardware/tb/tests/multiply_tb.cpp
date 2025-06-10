#include "base_testbench.h"

unsigned int ticks = 0;

class multiplyTestbench : public BaseTestbench {
protected:
    Vdut* multiply;

    void initializeInputs() override {
        multiply = top.get();
    }
};

TEST_F(multiplyTestbench, square) {
    multiply->a = 0xFFFA;
    multiply->b = 0xFFFA;
    multiply->eval();
    tfp->dump(ticks++);
    EXPECT_EQ(multiply->c, 0);
}

TEST_F(multiplyTestbench, negtwotimestwodotfiveClipped) {//-2*2.5 = -5
    multiply->a = 0xC000;
    multiply->b = 0x5000;
    multiply->eval();
    tfp->dump(ticks++);
    EXPECT_EQ(multiply->c, 0x8000);
}

TEST_F(multiplyTestbench, onetimesone) {
    multiply->a = 0x2000;
    multiply->b = 0x2000;
    multiply->eval();
    tfp->dump(ticks++);
    EXPECT_EQ(multiply->c, 0x2000);
}

TEST_F(multiplyTestbench, onedotfivetimesonedotfive) { //1.5*1.5
    multiply->a = 0x3000;
    multiply->b = 0x3000;
    multiply->eval();
    tfp->dump(ticks++);
    EXPECT_EQ(multiply->c, 0x4800);
}

TEST_F(multiplyTestbench, negfourtimesneg4) { //-4*-4
    multiply->a = 0x8000;
    multiply->b = 0x8000;
    multiply->eval();
    tfp->dump(ticks++);
    EXPECT_EQ(multiply->c, 0x7FFF);
}

TEST_F(multiplyTestbench, twotimestwoClipped) { //2 * 2 = 4
    multiply->a = 0x4000;
    multiply->b = 0x4000;
    multiply->eval();
    tfp->dump(ticks++);
    EXPECT_EQ(multiply->c, 0x7FFF);
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}