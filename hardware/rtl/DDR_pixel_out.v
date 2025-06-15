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


module DDR_pixel_out #(
    parameter DATA_WIDTH    = 16,
    parameter DEPTH         = 2500,
    parameter ADDRESS_WIDTH = 12
    // parameter C_m00_axis_tdata_WIDTH = 144
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
    
    output reg [11:0] read_addr,

    // AXI-Stream interface (M00_AXIS)
    input  wire                  m00_axis_aclk,
    input  wire                  m00_axis_aresetn,
    input  wire                  m00_axis_tvalid,
    input  wire [143:0]          m00_axis_tdata,
    input  wire                  m00_axis_tlast,
    output wire                  m00_axis_tready,
    output reg  [(144/8)-1:0]    m00_axis_tstrb
);

    
    //iterate through all 2500 pixels
    reg [143:0] input_data;
    reg [1:0] current_state;
    reg [1:0] next_state;
    reg [11:0] read_addr_count;

    //states
    localparam FILL_DATA    = 2'd0;
    localparam IDLE         = 2'd1;
    localparam SEND         = 2'd2;

    assign m00_axis_tstrb = {18{1'b1}};

    always @(posedge m00_axis_aclk or negedge m00_axis_aresetn) begin
        if (m00_axis_aresetn) begin
            current_state <= FILL_DATA;
            read_addr_count <= 0;
        end
        else begin
            current_state <= next_state;
        end

        case(current_state)
        FILL_DATA: begin
            input_data <= m00_axis_tdata;
        end
        
        SEND: begin
            n1      <= input_data[15:0];
            null1   <= input_data[31:16];
            ne1     <= input_data[47:32];
            e1      <= input_data[63:48];
            se1     <= input_data[79:64];
            s1      <= input_data[95:80];
            sw1     <= input_data[111:96];
            w1      <= input_data[127:112];
            nw1     <= input_data[143:128];
            read_addr <= read_addr_count;
            read_addr_count <= read_addr_count + 1;
        end
        
        default: ;
    endcase
    end
////////////////////////////////////////////////////////////////////////////

    //set flags etc here
    always @* begin
       case(current_state)
        FILL_DATA: begin
            m00_axis_tready = 1;
        end
        
        SEND: begin
            m00_axis_tready = 0;
        end

        default: ;
       endcase
    end


//////////////////////////////////////////////////////////////////////////////

    //states
    always @* begin
        case(current_state)
        FILL_DATA: begin
            // tready is high
            // tvalid is high
            next_state = SEND;
        end
        
        SEND: begin
            //tready is low
            next_state = FILL_DATA;
        end
        
        default: ;
    endcase
    end
endmodule
