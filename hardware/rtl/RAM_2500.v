`timescale 1ns / 1ps

module RAM_2500 #(
    parameter DATA_WIDTH = 16,        // Default data width
    parameter ADDRESS_WIDTH = 12     // 2^12 = 4096 > 2500
)(
    input wire clk,
    input wire [ADDRESS_WIDTH-1:0] addr,
    input wire [DATA_WIDTH-1:0] data_in,
    input wire write_en,
    output reg [DATA_WIDTH-1:0] data_out
);

    // Memory declaration (2500 words)
    reg [DATA_WIDTH-1:0] mem [0:2499];
    initial
        $readmemh("ram.mem", mem, 0, 2499);

    // Read operation with 1-cycle latency
    always @(posedge clk) begin
        if (write_en) begin
            // Write operation
            if (addr < 2500) begin
                mem[addr] <= data_in;
            end
            // Read-during-write behavior: new data appears on next cycle
            data_out <= data_in;
        end else begin
            // Normal read operation
            if (addr < 2500) begin
                data_out <= mem[addr];
            end else begin
                data_out <= 'bx;  // Undefined when out of range
            end
        end
    end

endmodule
