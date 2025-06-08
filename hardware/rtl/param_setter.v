`include "def.vh"
module param_setter (
    input wire [31:0] GPIOi, // 16 MSB: pick which value to write, 16 LSB: value

    output reg [`DATA_WIDTH-1:0] omega,
    output reg [`DATA_WIDTH-1:0] init_c0,
    output reg [`DATA_WIDTH-1:0] init_cn,
    output reg [`DATA_WIDTH-1:0] init_cne,
    output reg [`DATA_WIDTH-1:0] init_ce,
    output reg [`DATA_WIDTH-1:0] init_cse,
    output reg [`DATA_WIDTH-1:0] init_cs,
    output reg [`DATA_WIDTH-1:0] init_csw,
    output reg [`DATA_WIDTH-1:0] init_cw,
    output reg [`DATA_WIDTH-1:0] init_cnw,

    input wire clk
);

    localparam n_omega =      16'd0;
    localparam n_init_c0 =    16'd1;
    localparam n_init_cn =    16'd2;
    localparam n_init_cne =   16'd3;
    localparam n_init_ce =    16'd4;
    localparam n_init_cse =   16'd5;
    localparam n_init_cs =    16'd6;
    localparam n_init_csw =   16'd7;
    localparam n_init_cw =    16'd8;
    localparam n_init_cnw =   16'd9;

    always @(posedge clk) begin
        case (GPIOi[31:16])
            n_omega:     omega     <= GPIOi[`DATA_WIDTH-1:0];
            n_init_c0:   init_c0   <= GPIOi[`DATA_WIDTH-1:0];
            n_init_cn:   init_cn   <= GPIOi[`DATA_WIDTH-1:0];
            n_init_cne:  init_cne  <= GPIOi[`DATA_WIDTH-1:0];
            n_init_ce:   init_ce   <= GPIOi[`DATA_WIDTH-1:0];
            n_init_cse:  init_cse  <= GPIOi[`DATA_WIDTH-1:0];
            n_init_cs:   init_cs   <= GPIOi[`DATA_WIDTH-1:0];
            n_init_csw:  init_csw  <= GPIOi[`DATA_WIDTH-1:0];
            n_init_cw:   init_cw   <= GPIOi[`DATA_WIDTH-1:0];
            n_init_cnw:  init_cnw  <= GPIOi[`DATA_WIDTH-1:0];
            default: ; // No action for undefined indices
        endcase
    end

endmodule