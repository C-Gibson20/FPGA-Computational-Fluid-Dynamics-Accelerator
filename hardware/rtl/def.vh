`ifndef DEF
`define DEF

`define DATA_WIDTH 16
`define BLOCK_HEIGHT 25
`define BLOCK_WIDTH 25
`define BLOCK_DEPTH `BLOCK_HEIGHT * `BLOCK_WIDTH
`define HEIGHT 50
`define WIDTH 50
`define DEPTH `HEIGHT * `WIDTH
`define ADDRESS_WIDTH 13 // ≈ 11.3 → rounded up to 12
`define FIXED_ONE 16'sh2000
`define FIXED_ONE_9TH 16'sh038e
`define FIXED_ONE_36TH 16'sh00e4
`define RAM_READ_WAIT 2
`define RAMS_TO_ACCESS 2 

`endif
