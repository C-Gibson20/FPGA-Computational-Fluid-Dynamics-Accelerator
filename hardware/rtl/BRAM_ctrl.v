// once fill data is high keep reading zero
// then when m00_axis_tready is high send the zero data bit
// begin read request cycle

`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: me
// Engineer: me
// 
// Create Date: 27.05.2025 16:26:15
// Design Name: 
// Module Name: BRAM_addr_gen
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module BRAM_ctrl#(
    parameter  DATA_WIDTH                = 16,
    parameter  DEPTH                     = 2500,
    parameter  ADDRESS_WIDTH             = 12
    //parameter  C_m00_axis_tdata_WIDTH    = 144
)(
    //received from LBMsolver when its inputting data into BRAMs
    input wire chunk_transfer_ready,
    //take data of all 9 directions for each pixel at a time
    input wire [15:0] n1,
    input wire [15:0] null1,
    input wire [15:0] ne1,
    input wire [15:0] e1,
    input wire [15:0] se1,
    input wire [15:0] s1,
    input wire [15:0] sw1,
    input wire [15:0] w1,
    input wire [15:0] nw1,
    
    output reg [11:0] read_addr,

    // Ports of Axi Master Bus Interface M00_AXIS
    input wire  m00_axis_aclk,
    input wire  m00_axis_aresetn,
    input wire  m00_axis_tready,
    output reg  m00_axis_tvalid,
    output wire [144-1 : 0] m00_axis_tdata,
    output wire [(144/8)-1 : 0] m00_axis_tstrb,
    output reg  m00_axis_tlast
    
);
    
    //iterate through all 2500 pixels
    reg [143:0] output_data;
    reg current_state, next_state;
    reg [ADDRESS_WIDTH-1:0] count;

    //states
    localparam IDLE         = 1'd0;
    localparam READ_WAIT    = 1'd1;

    assign m00_axis_tstrb = {18{1'b1}};

    always @(posedge m00_axis_aclk or negedge m00_axis_aresetn) begin
        if (!m00_axis_aresetn) begin
            current_state <= IDLE;
            read_addr <= 0;
        end
        else begin
            current_state <= next_state;
        end
    end
////////////////////////////////////////////////////////////////////////////

    //set flags etc here
    always @* begin
        m00_axis_tvalid = 1'b0;
        m00_axis_tlast = 1'b0;

    end

//////////////////////////////////////////////////////////////////////////////

    //states
    always @* begin
        next_state = current_state;
        if(current_state == IDLE) begin
            if(chunk_transfer_ready) next_state = READ_WAIT;
        end

        if(current_state == READ_WAIT) begin
            // send only if tready is high
            if(count == DEPTH+1 ) next_state = IDLE;
            else next_state = READ_WAIT;
        end
    end

/////////////////////////////////////////////////////////////////

    // switching logic
    always @(posedge m00_axis_aclk or negedge m00_axis_aresetn) begin

        if(current_state == IDLE) begin
            count <= 1; // set count 1 higher to give correct value on state transition
        end

        if(current_state == READ_WAIT) begin
            // the output data is hardwired to be RAM out
            // 
            if(m00_axis_tready && chunk_transfer_ready) count <= count + 1;
            if(count == DEPTH+1) count <= 0;
        end
    end

//////////// output logic ////////////


always @* begin
    read_addr = 0;
    m00_axis_tvalid = 0;
    m00_axis_tlast = 0;

    if (!m00_axis_aresetn) read_addr = 0;
    else begin
        if(current_state == IDLE) begin
            if (m00_axis_tlast) begin
                read_addr =0; // 
            end
        end
        if(current_state == READ_WAIT) begin
            m00_axis_tvalid = 1;
            // set tvalid to high. use count as read addr. 
            // if(m00_ax?is_tready)
            read_addr = count;
            if(count == DEPTH+1) begin
                m00_axis_tlast = 1;
            end      
            if(!chunk_transfer_ready) begin
                m00_axis_tvalid = 0;
            end
        end
    end 
end
assign m00_axis_tdata = {null1, n1, ne1, e1, se1, s1, sw1, w1, nw1};

endmodule
