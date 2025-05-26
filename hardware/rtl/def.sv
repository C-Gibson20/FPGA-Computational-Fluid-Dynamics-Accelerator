`ifndef DEF
`define DEF

`define DATA_WIDTH 16
`define HEIGHT 300
`define WIDTH 100
`define DEPTH (HEIGHT*WIDTH)
`define ADDRESS_WIDTH ($clog2(DEPTH))
`define FIXED_ONE 16'sh_2000
`define FIXED_ONE_9TH 16'sh_38e
`define FIXED_ONE_36TH 16'sh_e4

`endif
