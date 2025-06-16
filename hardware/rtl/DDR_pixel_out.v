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
    parameter  ADDRESS_WIDTH             = 12
    //parameter  C_m00_axis_tdata_WIDTH    = 144
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
    
    output reg [11:0] write_addr,

    // Ports of Axi Master Bus Interface M00_AXIS
    input wire  m00_axis_aclk,
    input wire  m00_axis_aresetn,
    input wire  m00_axis_tvalid,
    input wire [144-1 : 0] m00_axis_tdata,
    input wire [(144/8)-1 : 0] m00_axis_tstrb,
    input wire  m00_axis_tlast,
    output reg  m00_axis_tready
);
    
    //iterate through all 2500 pixels
    reg [143:0] input_data;
    reg [1:0] current_state;
    reg [1:0] next_state;

    //states
    localparam IDLE     = 2'd0;
    localparam SEND       = 2'd1;

    always @(posedge m00_axis_aclk or negedge m00_axis_aresetn) begin
        if (!m00_axis_aresetn) current_state <= IDLE;
        else current_state <= next_state;
    end

////////////////////////////////////////////////////////////////////////////

    //set flags etc here
    always @* begin
        m00_axis_tready = (current_state == SEND);
    end


//////////////////////////////////////////////////////////////////////////////

    //states
    always @* begin
        next_state = current_state;
        case(current_state)
            IDLE: if (m00_axis_tvalid) next_state = SEND;
            
            //FILL_DATA: if (m00_axis_tvalid && m00_axis_tready) next_state = SEND;
        
            SEND: begin
                next_state = (m00_axis_tlast) ? IDLE : SEND;
            end
        
            default: ;
        endcase
    end

/////////////////////////////////////////////////////////////////

    always @(posedge m00_axis_aclk or negedge m00_axis_aresetn) begin
        if (!m00_axis_aresetn) begin
            write_addr <= 0;
        end   
        else begin 
            case(current_state) 
                IDLE: write_addr <= 0;

                SEND: begin
                    if (m00_axis_tvalid && m00_axis_tready) begin
                        n1      <= m00_axis_tdata[15:0];
                        null1   <= m00_axis_tdata[31:16];
                        ne1     <= m00_axis_tdata[47:32];
                        e1      <= m00_axis_tdata[63:48];
                        se1     <= m00_axis_tdata[79:64];
                        s1      <= m00_axis_tdata[95:80];
                        sw1     <= m00_axis_tdata[111:96];
                        w1      <= m00_axis_tdata[127:112];
                        nw1     <= m00_axis_tdata[143:128];

                        write_addr <= write_addr + 1;
                    end
                end

                default: ;
            endcase
        end
    end
endmodule

