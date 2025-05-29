#include "test_bench.h"

unsigned int ticks = 0;

class CounterTestbench : public Testbench {
protected:
    Vdut* counter;

    void initializeInputs() override {
        counter = top.get();  
        counter->clk = 1;
        counter->rst = 0;
        counter->en  = 1;
    }
};

TEST_F(CounterTestbench, CountsToNineAndPauses) {
    runSimulation(10);
    EXPECT_GE(counter->count, 0);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}