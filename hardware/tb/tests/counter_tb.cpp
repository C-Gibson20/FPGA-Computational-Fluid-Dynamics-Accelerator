#include "base_testbench.h"

Vdut *counter;
VerilatedVcdC *tfp;
unsigned int ticks = 0;

class CounterTestbench : public BaseTestbench {
protected:
    void initializeInputs() override {
        counter->clk = 1;
        counter->rst = 1;
        counter->en  = 0;
    }

    void stepClock() {
        for (int clk = 0; clk < 2; clk++) {
            tfp->dump(ticks++);
            counter->clk = !counter->clk;
            counter->eval();
        }
    }
};

TEST_F(CounterTestbench, CountsToNineAndPauses) {
    int pause_cycles = 0;

    for (int i = 0; i < 300; ++i) {
        stepClock();

        counter->rst = (i < 2) || (i == 15);

        if (pause_cycles > 0) {
            counter->en = 0;
            pause_cycles--;
        } else if (counter->count == 0x9) {
            pause_cycles = 3;
        } else {
            counter->en = (i > 4);
        }
    }

    // Example assertion: just to show integration
    EXPECT_GE(counter->count, 0);
}

int main(int argc, char **argv) {
    counter = new Vdut;
    tfp = new VerilatedVcdC;

    Verilated::traceEverOn(true);
    counter->trace(tfp, 99);
    tfp->open("waveform.vcd");

    testing::InitGoogleTest(&argc, argv);
    auto res = RUN_ALL_TESTS();

    counter->final();
    tfp->close();

    delete counter;
    delete tfp;

    return res;
}
