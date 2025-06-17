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


module DDR_pixel_out#(
    parameter  DATA_WIDTH                = 16,
    parameter  DEPTH                     = 2500,
    parameter  ADDRESS_WIDTH             = 12,
    parameter  C_M00_AXIS_TDATA_WIDTH    = 144
)(
    //take data of all 9 directions for each pixel at a time
    output reg [15:0] n1,
    output reg [15:0] null1,
    output reg [15:0] ne1,
    output reg [15:0] e1,
    output reg [15:0] se1,
    output reg [15:0] s1,
    output reg [15:0] sw1,
    output reg [15:0] w1,
    output reg [15:0] nw1,
    output reg wen, 

    output reg [11:0] write_addr,

    // Ports of Axi Master Bus Interface M00_AXIS
    input wire  m00_axis_aclk,
    input wire  m00_axis_aresetn,
    input wire  m00_axis_tvalid,
    input wire [C_M00_AXIS_TDATA_WIDTH-1 : 0] m00_axis_tdata,
    input wire [(C_M00_AXIS_TDATA_WIDTH/8)-1 : 0] m00_axis_tstrb, // ignore thiss...
    input wire  m00_axis_tlast,
    output reg  m00_axis_tready
);
    
    //iterate through all 2500 pixels
    reg [C_M00_AXIS_TDATA_WIDTH -1:0] input_data;
    reg [1:0] current_state;
    reg [1:0] next_state;

    always @* begin // combinational
        m00_axis_tready = m00_axis_tvalid;

        n1    = m00_axis_tdata[15:0];
        null1 = m00_axis_tdata[31:16];
        ne1   = m00_axis_tdata[47:32];
        e1    = m00_axis_tdata[63:48];
        se1   = m00_axis_tdata[79:64];
        s1    = m00_axis_tdata[95:80];
        sw1   = m00_axis_tdata[111:96];
        w1    = m00_axis_tdata[127:112];
        nw1   = m00_axis_tdata[143:128];
        wen  =  m00_axis_tvalid;

    end

    always @(posedge m00_axis_aclk or negedge m00_axis_aresetn) begin

        if(!m00_axis_aresetn) begin
            write_addr <= 0;
        end
        else begin
            if(m00_axis_tready) begin
                write_addr <= write_addr + 1;
            end
            if(m00_axis_tlast) begin
                write_addr <= 0;
            end
        end
    end
endmodule