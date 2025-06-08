#include "test_bench.h"

unsigned int ticks = 0;

class TopTestbench : public Testbench {
protected:

    void initializeInputs() override { 
        top->clk = 1;
        top->rst = 1;
        top->en  = 1;
        top->step = 1000;
        top->omega = 0x4000; // 2.0 in Q3.13, tau=0.5

    }
};

// TEST_F(TopTestbench, BarriersBounce) {
//     top->barriers |= (1 << 0); // set barrier[0] = 1
//     runSimulation(11);
//     EXPECT_GE(top->testing_cs_n_data_in,0x11);
// }

// TEST_F(TopTestbench, BarriersZero) {
//     top->barriers |= (1 << 0); // set barrier[0] = 1
//     runSimulation(14);
//     EXPECT_GE(top->testing_cs_n_data_in,0x0);
// }

// TEST_F(TopTestbench, idk) {
//     top->barriers = 0xF99F; 
//     runSimulation(4000);
// }

// TEST_F(TopTestbench, irdk) {
//     top->barriers = 0x0420; 
//     runSimulation(8000);
// }

TEST_F(TopTestbench, kii) {
    for(int i = 0; i < 2500; i++){
        if(i < 50 || i >= 2450 || i%50 || (i+1)%50){
            top->barriers[i] = 1;
        }
        else{
            top->barriers[i] = 0;
        }
    }
    runSimulation(8000);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}