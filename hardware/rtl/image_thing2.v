`include "def.vh"

module image_thing2 #(
    parameter NUM_BLOCKS = 3,
    parameter BLOCK_SIZE = 2500
) (
    input wire [31:0] addr_din,
    input wire clk,
    output reg [2499:0] dout,
    output reg ram_addr, 
    output reg ram_wen, 
    output reg [15:0] ram_din,
    input reg [15:0] ram_dout,
    input wire chunk_transfer_ready,
    // this will use a RAM [2499:0] din and dout
);

assign ram_addr = addr_din[30:16];
assign ram_din = addr_din[15:0];  
// assign ram_wen = 1;
assign ram_wen = addr_din[31]; // MSB is WEN

// this won't have the same nice behaviour as the double buffered

localparam FILL_DATA = 1'd0;
localparam OUT_RAM = 1'd1;

reg [15:0] block_num;
reg [15:0] index; // index within a given block

reg current_state, next_state;

always @(posedge clk) begin
    current_state <= next_state;
end

// next state
always @* begin
    case (current_state)
        FILL_DATA : begin
            if(ram_wen) next_state = FILL_DATA;
            else next_state = OUT_RAM;
        end 
        OUT_RAM : begin
            if(index == BLOCK_SIZE && block_num == NUM_BLOCKS) 
                next_state = FILL_DATA;
            else
                next_state = OUT_RAM;
        end
        default: next_state = current_state;
    endcase
end

// behav

always @(posedge clk) begin
    if(current_state == FILL_DATA && next_state == OUT_RAM) begin
        block_num <= 0;
        index <= 0;
    end
    
end


/// posedge detector ///////////
reg sig_dly; 
wire pe_ctr; //posedge of chunk transfer ready
always @(posedge clk) begin
    sig_dly <= chunk_transfer_ready; 
end
assign pe_ctr = chunk_transfer_ready & ~sig_dly;

always @(posedge clk) begin
    if(pe_ctr) block_num <= block_num + 1;
end




// get chunk
endmodule
