#include "test_bench.h"

unsigned int ticks = 0;

class BRAMCtrlTestbench : public Testbench {
protected:
    Vdut* BRAMCtrl;
    
    void initializeInpues() override {
        BRAMCtrl->rst = 0;
    }
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}