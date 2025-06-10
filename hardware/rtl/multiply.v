module multiply (
    input wire signed [15:0] a,
    input wire signed [15:0] b,
    output wire signed [15:0] c
);
    wire signed [31:0] c_int = a * b;
    assign c = c_int >>> 13;

endmodule
