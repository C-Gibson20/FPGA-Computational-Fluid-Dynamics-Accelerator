#include "base_testbench.h"

unsigned int ticks = 0;

class multiplyTestbench : public BaseTestbench {
protected:
    Vdut* multiply;

    void initializeInputs() override {
        multiply = top.get();
    }
};

TEST_F(multiplyTestbench, sqaure) {
    multiply->a = 0xFFFA;
    multiply->b = 0xFFFA;
    multiply->eval();
    tfp->dump(ticks++);
    EXPECT_EQ(multiply->c, 0);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}