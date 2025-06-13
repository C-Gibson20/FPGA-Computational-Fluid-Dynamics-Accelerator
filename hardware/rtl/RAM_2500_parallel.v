`timescale 1ns / 1ps
`include "def.vh"

module RAM_2500_parallel #(
    parameter DATA_WIDTH = `DATA_WIDTH,        // Default data width
    parameter ADDRESS_WIDTH = `ADDRESS_WIDTH,     // 2^12 = 4096 > 2500
    parameter INIT_FILE = "ram0.mem",
    parameter RAMS_TO_ACCESS = `RAMS_TO_ACCESS
)(
    input wire clk,
    input wire [ADDRESS_WIDTH-1:0] addr,
    input wire [DATA_WIDTH*RAMS_TO_ACCESS-1:0] data_in,
    input wire write_en,
    output reg [DATA_WIDTH*RAMS_TO_ACCESS-1:0] data_out
);

    // Memory declaration (2500 words)
    reg [DATA_WIDTH-1:0] mem [0:`DEPTH-1];
    initial
        $readmemh(INIT_FILE, mem, 0, `DEPTH-1);

    // Read operation with 1-cycle latency
    always @(posedge clk) begin
        if (write_en) begin
            // Write operation
            if (addr < `DEPTH) begin
                for(int i = 0; i < `RAMS_TO_ACCESS; i++)
                begin
                    mem[addr+i] <= data_in;
                end
            end
            // Read-during-write behavior: new data appears on next cycle
            for(int i = 0; i < `RAMS_TO_ACCESS; i++)
            begin
                data_out[i*DATA_WIDTH+:DATA_WIDTH] <= mem[addr+i];
            end
        end else begin
            // Normal read operation
            if (addr < `DEPTH) begin
                for(int i = 0; i < `RAMS_TO_ACCESS; i++)
                begin
                    data_out[i*DATA_WIDTH+:DATA_WIDTH] <= mem[addr+i];
                end
            end else begin
                data_out <= 'bx;  // Undefined when out of range
            end
        end
    end

endmodule
