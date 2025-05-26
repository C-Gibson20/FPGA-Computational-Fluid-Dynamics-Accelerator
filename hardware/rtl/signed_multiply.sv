module signed_multiply(
    input wire signed [15:0] a,
    input wire signed [15:0] b,
    output wire signed [15:0] out,
)

    wire signed [31:0] mult_out;
    assign mult_out = a*b;
    assign out = {mult_out[31],mult_out[27:13]};

endmodule