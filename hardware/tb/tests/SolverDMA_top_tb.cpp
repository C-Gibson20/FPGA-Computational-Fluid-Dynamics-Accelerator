#include "base_testbench.h"
#include <gtest/gtest.h>

unsigned int ticks = 0;

class DMATB : public BaseTestbench {
protected:
    Vdut* s;
    
    void initializeInputs() override {
        s = top.get();
        s->u_x = 0;
        s->u_y = 0;
        s->rho = 0;
        s->u_squared = 0;
        s->in_collision_state = 0;
        s->collider_ready = 1;
        s->m00_axis_aclk = 0;
        s->m00_axis_aresetn = 1;
        s->m00_axis_tready = 0;
        s->m00_axis_aclk = 1;

    }

    void runSimulation(int cycles = 1)
    {
        for (int i = 0; i < cycles; i++)
        {
            for (int m00_axis_aclk = 0; m00_axis_aclk < 2; m00_axis_aclk++)
            {
                top->eval();
#ifndef __APPLE__
                tfp->dump(2 * ticks + m00_axis_aclk);
#endif
                top->m00_axis_aclk = !top->m00_axis_aclk;
            }
            ticks++;

            if (Verilated::gotFinish())
            {
                exit(0);
            }
        }
    }

};

TEST_F(DMATB, TestDataLoad) {

    runSimulation(2);
    for(int i = 1; i< 10; i++){
        
        s->in_collision_state = 1;
        // s->collider_ready = 1;
        s->u_x = i*2;
        s->u_y = i*3;
        s->rho = i*4;
        s->u_squared = i*5;
        runSimulation(1);

    }
    s->in_collision_state = 0;
    runSimulation(1);
    EXPECT_EQ(s->m00_axis_tvalid, 1);
    EXPECT_EQ(s->m00_axis_tdata, 0x0004000500020003);
    runSimulation(2);
    s->m00_axis_tready = 1;
    runSimulation(3);
    s->m00_axis_tready = 0;
    runSimulation(10);
    s->m00_axis_tready = 1;
    runSimulation(2);
    s->m00_axis_tready = 0;

    // EXPECT_EQ(top->m00_axis_tlast, 1);
    runSimulation(5); // test data load again (should deny)
    for(int i = 1; i< 10; i++){
        s->in_collision_state = 1;
        // s->collider_ready = 1;
        s->u_x = 100*2;
        s->u_y = 100*3;
        s->rho = 100*4;
        s->u_squared = 100*5;
        runSimulation(1);
    }
    s->in_collision_state = 1;
    runSimulation(1);
    s->m00_axis_tready = 1;
    runSimulation(10);
    runSimulation(2500);
    
    

}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}