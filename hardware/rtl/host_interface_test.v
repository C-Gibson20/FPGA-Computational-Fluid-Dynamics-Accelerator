`timescale 1ps / 1ps
`include "def.vh"

module tb_host_interface();

// Parameters
parameter CLK_PERIOD = 2;  // 100 MHz clock
parameter DATA_WIDTH = `DATA_WIDTH;  // From your defines

// Testbench Signals
reg clk;
reg rst_n;
reg [DATA_WIDTH-1:0] GPIOi;
reg collider_ready;
reg [DATA_WIDTH-1:0] u_x;
reg [DATA_WIDTH-1:0] u_y;
reg [DATA_WIDTH-1:0] rho;

wire [DATA_WIDTH-1:0] GPIOux;
wire [DATA_WIDTH-1:0] GPIOuy;
wire [DATA_WIDTH-1:0] GPIOrho;

// Instantiate DUT
host_interface dut (
    .clk(clk),
    .rst(rst_n),
    .GPIOi(GPIOi),
    .collider_ready(collider_ready),
    .in_collision_state(collider_ready),
    .u_x(u_x),
    .u_y(u_y),
    .rho(rho),
    .GPIOux(GPIOux),
    .GPIOuy(GPIOuy),
    .GPIOrho(GPIOrho)
);

// Clock generation
initial begin
    clk = 0;
    forever #(CLK_PERIOD/2) clk = ~clk;
end

// Reset generation
initial begin
    rst_n = 1;
    #4 rst_n = 0;
end
integer i;
// Main test sequence
initial begin
    // Initialize all inputs
    GPIOi = 0;
    collider_ready = 0;
    u_x = 0;
    u_y = 0;
    rho = 0;
    
    // Wait for reset to complete
    @(negedge rst_n);
    #10;
    
    
    // Test Case 1: Basic data feed
    $display("Test Case 1: Basic data feed");
    collider_ready = 1;
    
    for (i = 0; i < 10; i = i + 1) begin
        u_x = i;
        u_y = i*2;
        rho = i*3;
        #(CLK_PERIOD);
        
        $display("Cycle %0d: u_x=%h, u_y=%h, rho=%h", 
                 i, u_x, u_y, rho);
    end
    collider_ready = 0;
    #10;
    
    // Test Case 2: GPIO readback
    $display("\nTest Case 2: GPIO readback");
    GPIOi[DATA_WIDTH-1] = 1;  // Enable read
    GPIOi[8:0] = 2;           // Select element 2
    
    #(CLK_PERIOD*3);
    $display("Readback: GPIOux=%h, GPIOuy=%h, GPIOrho=%h",
             GPIOux, GPIOuy, GPIOrho);
    
    // Test Case 3: Simultaneous feed and read
    $display("\nTest Case 3: Simultaneous operations");
    collider_ready = 1;
    u_x = 16'hAAAA;
    u_y = 16'hBBBB;
    rho = 16'hCCCC;
    
    GPIOi[8:0] = 5;  // Select different element
    
    #(CLK_PERIOD*2);
    $display("During feed: GPIOux=%h, GPIOuy=%h, GPIOrho=%h",
             GPIOux, GPIOuy, GPIOrho);
    
    // End simulation
    #100;
    $display("\nSimulation completed");
    $finish;
end

// Monitoring
//always @(posedge clk) begin
//    $display("Time %0t: GPIOi=%h, ready=%b, outputs: ux=%h, uy=%h, rho=%h",
//             $time, GPIOi, collider_ready, GPIOux, GPIOuy, GPIOrho);
//end

endmodule