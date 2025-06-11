#include "test_bench.h"
#include <fstream>

unsigned int ticks = 0;


class ImageThingTestbench : public Testbench {
protected:
    void initializeInputs() override {
        top->din = 0;
    }

    // void initializeInputs() override {
    //     //// input wire clk,
    //     //// input wire next_img,
    //     //// input wire in_collision_state,
    //     //// input wire axi_ready, //axi has written the next 32 bits
    //     //// input wire [31:0] data_in, //complete img ready
    //     //// output reg data_valid,
    //     //// output reg [2499:0] data_out

    //     top->clk = 0;
    //     top->din = 0;
    //     top->addr_push = 0;
        
    // }

 
//     void runSimulation(int cycles) {
//         for (int i = 0; i < cycles; i++) {
//             for (int clk = 0; clk < 2; clk++) {
//                 top->eval();
// #ifndef __APPLE__
//                 tfp->dump(2 * ticks + clk);
// #endif
//                 top->clk = !top->clk;
//             }

//             ticks++;

//             if (Verilated::gotFinish()) {
//                 break;
//             }
//         }

//     }
};

TEST_F(ImageThingTestbench, CheckSomeShit){
    // for(int i = 0; i<7;i++){
    //     runSimulation(3);
    //     top->addr_push = i;
    //     top->din = 100*i;
    // }
    // top->addr_push = 1<< 31;
    // runSimulation(3);

    // for(int i = 0; i<7;i++){
    //     runSimulation(3);
    //     top->addr_push = i;
    //     top->din = 3*i;
    // }


}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}