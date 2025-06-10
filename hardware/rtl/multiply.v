module multiply (
    input wire signed [15:0] a,
    input wire signed [15:0] b,
    output wire signed [15:0] c
);

    wire signed [15:0] round = 1 <<< 12; //rounding values so mid values are rounded up (1 << (Q-1))

    wire signed [31:0] product = (a * b) + round;
    wire signed [15:0] shifted = product >>> 13;

    assign c = (product > 32'sh10000000) ? 16'sh7FFF :
               (product < 32'shf0000000) ? 16'sh8000 :
               shifted;

endmodule
