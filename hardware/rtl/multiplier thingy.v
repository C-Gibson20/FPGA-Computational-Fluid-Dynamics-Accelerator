module Q313Mult (
    input wire signed [15:0] in1,
    input wire signed [15:0] in2,
    output reg signed [15:0] res
);

wire signed [31:0] intermediate;
wire signed sign;
wire signed [2:0] overflow;

assign intermediate = in1*in2;
assign sign = intermediate[31];
assign overflow = intermediate[30:28];
// 26 + 3 - 1 = 28
always @* begin
    if(|overflow && !sign) begin
        res = 16'h7fff;
    end
    else if (|overflow && sign) begin
        res = 16'h8000;
    end
    else if (!|overflow && sign) begin
        res = -(intermediate >> 13);
    end
    else if (!|overflow && !sign) begin
        res = intermediate >> 13;
    end

end

endmodule