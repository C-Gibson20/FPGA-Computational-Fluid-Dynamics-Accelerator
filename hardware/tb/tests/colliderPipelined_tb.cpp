#include "test_bench.h"

unsigned int ticks = 0;

class ColliderPipelinedTestbench : public Testbench {
protected:
    Vdut* ColliderPipelined;
    
    void initializeInputs() override {
        ColliderPipelined = top.get();
    }
};

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}