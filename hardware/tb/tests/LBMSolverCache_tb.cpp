#include "test_bench.h"

unsigned int ticks = 0;

class LBMSolverCacheTestbench : public Testbench {
protected:
    Vdut* LBMSolverCache;

        void initializeInputs() override {
        LBMSolverCache = top.get();  
        LBMSolverCache->clk = 1;
        LBMSolverCache->chunk_compute_ready = 1;
        LBMSolverCache->rst = 0;
        LBMSolverCache->en  = 1;
        LBMSolverCache->step = 0;
        LBMSolverCache->omega = 0x4000; // 2.0 in Q3.13, tau=0.5
        LBMSolverCache->step = 10000;

    }
};

TEST_F(LBMSolverCacheTestbench, BarriersBounce) {
    runSimulation(1);
    LBMSolverCache->rst = 1;
    runSimulation(7502);
    EXPECT_GE(LBMSolverCache->testing_cs_n_data_in,0x11);
}

// TEST_F(LBMSolverCacheTestbench, BarriersZero) {
//     LBMSolverCache->barriers[0]= 1;
//     LBMSolverCache->rst = 1;
//     runSimulation(10002);
//     EXPECT_GE(LBMSolverCache->testing_cs_n_data_in,0x0);
// }

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
