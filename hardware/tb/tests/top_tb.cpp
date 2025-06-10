#include "test_bench.h"
#include <fstream>

unsigned int ticks = 0;

class TopTestbench : public Testbench {
protected:
    std::ofstream logFile;

    void initializeInputs() override {
        top->clk = 1;
        top->rst = 1;
        top->en  = 1;
        top->step = 1000;
        top->omega = 0x3000; // 2.0 in Q3.13
        top->init_c0    = 0x0E38;
        top->init_cn    = 0x038E;
        top->init_cne   = 0x00EA;
        top->init_ce    = 0x03AA;
        top->init_cse   = 0x00EA;
        top->init_cs    = 0x038E;
        top->init_csw   = 0x00DD;
        top->init_cw    = 0x0373;
        top->init_cnw   = 0x00DD;

        logFile.open("u_squared_log.txt");
        if (!logFile.is_open()) {
            std::cerr << "Failed to open u_squared_log.txt" << std::endl;
            exit(EXIT_FAILURE);
        }
    }

    // ✅ override runSimulation in this subclass
    void runSimulation(int cycles) {
        for (int i = 0; i < cycles; i++) {
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

TEST_F(TopTestbench, LogUSquaredOnly) {
    runSimulation(10000);  // enough cycles for 1000 steps

    // Run Python script to convert the log
    int status = std::system("python3 convert_u_squared.py");
    if (status != 0) {
        std::cerr << "❌ Failed to run convert_u_squared.py\n";
    } else {
        std::cout << "✅ Log converted by convert_u_squared.py\n";
    }
}

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
// assuming `DEPTH` bits wide, i in [0..DEPTH-1]

// TEST_F(TopTestbench, kii) {

//     auto setBarrierBit = [&](int i) {
//         int word = i >> 5;        // divide by 32
//         int bit  = i &  31;       // mod 32
//         top->barriers.data()[word] |= (1U << bit);
//     };

//     for (int w = 0; w < (2500+31)/32; ++w) {
//         top->barriers.data()[w] = 0;
//     }

//     for (int i = 0; i < 2500; i++) {
//         bool isBarrier = (i < 50) || (i >= 2450) || (i % 50 == 0) || ((i+1) % 50 == 0);
//         if (isBarrier) {
//             std::cout << "Barrier at " << i << std::endl;
//             setBarrierBit(i);
//         }
//     }
//     runSimulation(80099);
//     EXPECT_EQ(top->testing_c0_data_in,0x0E38);
// }

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}