#include "test_bench.h"
#include <fstream>

unsigned int ticks = 0;

class TopJeremyTestbench : public Testbench {
protected:
    std::ofstream logFile;

    void initializeInputs() override {
        top->clk = 1;
        top->rst = 0;
        top->en  = 1;
        top->step = 1000;
        top->omega = 0x4000; // 2.0 in Q3.13
        top->init_c0    = 0x0E02;
        top->init_cn    = 0x0381;
        top->init_cne   = 0x012F;
        top->init_ce    = 0x04BB;
        top->init_cse   = 0x012F;
        top->init_cs    = 0x0381;
        top->init_csw   = 0x00A6;
        top->init_cw    = 0x0298;
        top->init_cnw   = 0x00A6;


        logFile.open("u_squared_log.txt");
        if (!logFile.is_open()) {
            std::cerr << "Failed to open u_squared_log.txt" << std::endl;
            exit(EXIT_FAILURE);
        }
    }

    // ✅ override runSimulation in this subclass
    void runSimulation(int cycles) {
        for (int i = 0; i < cycles; i++) {
            if(i == 2)
            { 
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

            // ✅ Log u_squared when valid
            if (top->collider_ready && top->in_collision_state) {
                logFile << int16_t(top->u_squared) << "\n";
            }

            if (Verilated::gotFinish()) {
                break;
            }
        }

        logFile.close();
    }
};

TEST_F(TopJeremyTestbench, LogUSquaredOnly) {
    runSimulation(1000);  // enough cycles for 1000 steps

    // Run Python script to convert the log
    int status = std::system("python3 convert_u_squared.py");
    if (status != 0) {
        std::cerr << "❌ Failed to run convert_u_squared.py\n";
    } else {
        std::cout << "✅ Log converted by convert_u_squared.py\n";
    }
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}