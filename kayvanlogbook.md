## 22 May 2025
Went over the research provided by my team and started implementing an LBM solver in verilog. Currently have only added the RAM and some basic setup to the top level file, however made a few key discoveries about the memory. The PYNQ has 140 blocks of 36 Kbit block ram, which leaves us with 5.04 Mbits of BRAM. This means we can't store each cell as it's own RAM as we are limited to a total of 140 blocks, it also means our resolution is limited by our BRAM. We are currently using the lattice boltzmann method with 9 directions per cell, also known as D2Q9, along with 16 bit fixed point words. This means our total memory usage is given by the following:
$$resolution*9*16 = memory$$
$$\therefore resolution<\frac{5.04*10^6}{144} = 35000$$
There are methods to decrease our memory usage by only using chunks of memory at a time, however for now we will stick with the straightforward method of just intializing 9 blocks of RAM, one for each direction.
## 23 May 2025
Implemented the streaming stage, in our implementation we assume the boundaries of the simulation simply absorb the particles, so my code reflects that by not writing anything when a cell points to a boundary. The code is currently in system verilog and needs to be translated over to verilog, it's mostly converted now I just need to change all the logic signals to reg and wires. Also found an equation of the framerate as a function of the clock frequency and the number of cycles used to calculate each cell. Our resolution is 300*100, we want the frequency to be 50Mhz, and the framerate to be at least 60.

$$(\frac{frequency}{cycles\ per\ cell*resolution}) = framerate$$
$$\therefore cycles\ per\ cell < \frac{50*10^6}{60*30000} = 27.8 $$
