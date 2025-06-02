#include "test_bench.h"

unsigned int ticks = 0;

class RAMTestbench : public Testbench {
protected:
    Vdut* RAM;

    void initializeInputs() override {
        RAM = top.get();
        RAM->addr = 0;
        RAM->data_in = 0;
        RAM->clk = 0;
        RAM->write_en = 0;
    }
};

TEST_F(RAMTestbench, CanItCompile){
    runSimulation(10);
    EXPECT_GE(RAM->data_out, 0);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}