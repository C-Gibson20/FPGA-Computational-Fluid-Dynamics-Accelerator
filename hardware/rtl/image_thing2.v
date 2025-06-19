`include "def.vh"

module image_thing2 (
    input wire [31:0] addr_din,
    input wire clk,
    output reg [`DEPTH-1:0] dout
);

reg [`DEPTH-1:0] buffer;
wire send_img;
wire [15:0] addr;
wire [15:0] din;
assign send_img = addr_din[31];
assign addr = addr_din[30:16];
assign din = addr_din[15:0];


always @(posedge clk) begin
    if(send_img) begin
        dout <= buffer;
    end
    buffer[addr +: 16] <= din;
end
    
endmodule
