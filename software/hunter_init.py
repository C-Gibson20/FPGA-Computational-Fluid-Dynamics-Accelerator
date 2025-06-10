import numpy
import matplotlib.pyplot as plt
import matplotlib.animation as animation
from matplotlib import rc
plt.rcParams["figure.figsize"] = (50,3)

# Parameters
height = 50                     # grid height
width = 50                     # grid width
# viscosity = 0.002                # viscosity
# omega = 1./(3*viscosity + 0.5)   # relaxation parameter (a function of viscosity)
omega = 2.
u0 = 0.1                      # initial in-flow speed (eastward)
four9ths = 4./9.                 # a constant
one9th   = 1./9.                 # a constant
one36th  = 1./36.                # a constant

# Microscopic densities
n0  = numpy.zeros(height*width)  # Naught
nN  = numpy.zeros(height*width)  # North
nS  = numpy.zeros(height*width)  # South
nE  = numpy.zeros(height*width)  # East
nW  = numpy.zeros(height*width)  # West
nNW = numpy.zeros(height*width)  # Northwest
nNE = numpy.zeros(height*width)  # Northeast
nSE = numpy.zeros(height*width)  # Southeast
nSW = numpy.zeros(height*width)  # Southwest

# Barriers
bar = numpy.zeros(height*width)  # Barriers

# Macroscopic density and velocity
rho = numpy.zeros(height*width)    # Cell density
ux  = numpy.zeros(height*width)    # Cell x-velocity
uy  = numpy.zeros(height*width)    # Cell y-velocity
speed2 = numpy.zeros(height*width) # Cell squared velocity

def initialize(x1top, y1top, y1height, u0=u0):
    xcoord = 0
    ycoord = 0
    
    count = 0
    for i in range(height*width):
        n0[i] = four9ths* (1 - 1.5*(u0**2.))
        nN[i] = one9th  * (1 - 1.5*(u0**2.))
        nS[i] = one9th  * (1 - 1.5*(u0**2.))
        nE[i] = one9th  * (1 + 3*u0 + 4.5*(u0**2.) - 1.5*(u0**2.))
        nW[i] = one9th  * (1 - 3*u0 + 4.5*(u0**2.) - 1.5*(u0**2.))
        nNE[i]= one36th * (1 + 3*u0 + 4.5*(u0**2.) - 1.5*(u0**2.))
        nSE[i]= one36th * (1 + 3*u0 + 4.5*(u0**2.) - 1.5*(u0**2.))
        nNW[i]= one36th * (1 - 3*u0 + 4.5*(u0**2.) - 1.5*(u0**2.))
        nSW[i]= one36th * (1 - 3*u0 + 4.5*(u0**2.) - 1.5*(u0**2.))
        
        rho[i] =  n0[i] + nN[i] + nS[i] + nE[i] + nW[i] + nNE[i] + nSE[i] + nNW[i] + nSW[i]
        
        ux[i]  = (nE[i] + nNE[i] + nSE[i] - nW[i] - nNW[i] - nSW[i]) * (1-(rho[i]-1)+((rho[i]-1)**2.))
        uy[i]  = (nN[i] + nNE[i] + nNW[i] - nS[i] - nSE[i] - nSW[i]) * (1-(rho[i]-1)+((rho[i]-1)**2.))
        
        if (xcoord==x1top):
            if (ycoord >= y1top):
                if (ycoord < (y1top+y1height)):
                    count += 1
                    bar[ycoord*width + xcoord] = 1
        
        xcoord = (xcoord+1) if xcoord<(width-1) else 0
        ycoord = ycoord if (xcoord != 0) else (ycoord + 1)

# Frames per second, and number of seconds
fps = 60
nSeconds = 10

# First set up the figure, the axis, and the plot element we want to animate
fig = plt.figure( figsize=(20,5) )

# Initialize the barriers (occurs in previous section)
initialize(2, 2, 0)

def to_q313_hex(value):
    fixed_val = int(round(value * 8192)) & 0xFFFF  # wrap into 16-bit space
    return f"0x{fixed_val:04X}"


## making it easier for notebook
print(f"write_param(\"c0\"  , {to_q313_hex(n0[0])} )")
print(f"write_param(\"cn\"  , {to_q313_hex(nN[0])} )")
print(f"write_param(\"cs\"  , {to_q313_hex(nS[0])} )")
print(f"write_param(\"ce\"  , {to_q313_hex(nE[0])} )")
print(f"write_param(\"cw\"  , {to_q313_hex(nW[0])} )")
print(f"write_param(\"cne\" , {to_q313_hex(nNE[0])} )")
print(f"write_param(\"cse\" , {to_q313_hex(nSE[0])} )")
print(f"write_param(\"cnw\" , {to_q313_hex(nNW[0])} )")
print(f"write_param(\"csw\" , {to_q313_hex(nSW[0])} )")

