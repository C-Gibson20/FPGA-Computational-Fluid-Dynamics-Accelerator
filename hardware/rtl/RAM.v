`include "def.sv"

module RAM #(
    parameter DATA_WIDTH = `DATA_WIDTH,
    parameter DEPTH = `DEPTH,
    parameter ADDRESS_WIDTH = `ADDRESS_WIDTH
) (
    input logic  [ADDRESS_WIDTH-1:0]    read_address, 
    input logic  [ADDRESS_WIDTH-1:0]    write_address,
    input logic  [DATA_WIDTH-1:0]       data_in,
    input logic                         clk,
    input logic                         write_en,
    output logic [DATA_WIDTH-1:0]       data_out
);

logic [DATA_WIDTH-1:0] ram_array [0:DEPTH-1];

always_ff @(posedge clk) begin
    if(write_en) begin
        ram_array[write_address] <= data_in;
    end
    data_out <= ram_array[read_address];
end

endmodule
