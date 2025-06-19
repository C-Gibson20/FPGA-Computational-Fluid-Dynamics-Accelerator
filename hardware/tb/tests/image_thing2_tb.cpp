#include "test_bench.h"

unsigned int ticks = 0;

class ImageThingTestbench : public Testbench {
protected:
    void initializeInputs() override {
        top->addr_din = 0;
    }
};

TEST_F(ImageThingTestbench, CheckSomeShit){
    runSimulation(100);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}