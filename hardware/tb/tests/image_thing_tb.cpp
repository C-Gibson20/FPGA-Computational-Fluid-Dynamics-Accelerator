#include "base_testbench.h"
#include "test_bench.h"
#include <fstream>

unsigned int ticks = 0;


class ImageThingTestbench : public BaseTestbench {
protected:

    void initializeInputs() override {
        //// input wire clk,
        //// input wire next_img,
        //// input wire in_collision_state,
        //// input wire axi_ready, //axi has written the next 32 bits
        //// input wire [31:0] data_in, //complete img ready
        //// output reg data_valid,
        //// output reg [2499:0] data_out

        top->clk = 0;
        

        
    }

 
    void runSimulation(int cycles) {
        for (int i = 0; i < cycles; i++) {
            if(i == 400){
                top->rst = 1;
            }
            for (int clk = 0; clk < 2; clk++) {
                top->eval();
#ifndef __APPLE__
                tfp->dump(2 * ticks + clk);
#endif
                top->clk = !top->clk;
            }
            ticks++;


            if (Verilated::gotFinish()) {
                break;
            }
        }

        logFile.close();
    }
};


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}