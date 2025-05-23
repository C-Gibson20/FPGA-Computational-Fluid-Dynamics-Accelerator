#include "VLBMSolver.h"
#include "verilated.h"
#include "verilated_vcd_c.h"

int main(int argc, char **argv, char **env) {
    int i;
    int clk;

    Verilated::commandArgs(argc,argv);
    VLBMSolver* top = new VLBMSolver;
    Verilated:: traceEverOn(true);
    VerilatedVcdC* tfp = new VerilatedVcdC;

    top->trace (tfp,99);
    tfp->open ("counter.vcd");


    top->clk = 1;
    top->rst = 1;
    top->en = 0;

    int half = 1;
    for(i=0;i<1000;i++){
        for(clk=0;clk<2;clk++){
            tfp->dump (2*i+clk);
            top->rst = (half == 5);
            top->clk =!top->clk;
            top->eval ();
            half++;
        }
        //Right shifts each value 16,8, 4 and 0 respectively
        //This is then anded with F which is 16, to give us the
        //value of count for each digit
        //vbdHex(4,(int(top->count) >> 16 ) & 0xF);
        //vbdHex(3,(int(top->count) >> 8 ) & 0xF);
        //vbdHex(2,(int(top->count) >> 4 ) & 0xF);
        //vbdHex(1,(int(top->count)) & 0xF);      
        if(Verilated::gotFinish()) exit(0); 
    }
    tfp->close();
    exit(0);
}