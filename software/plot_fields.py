import numpy as np
import matplotlib.pyplot as plt
import matplotlib.animation as animation

# Set figure size similar to original Python LBM script
plt.rcParams["figure.figsize"] = (50, 3)

height = 32
width = 512
fps = 600
n_seconds = 15
n_frames = fps * n_seconds

# Load all frame data
frames = [np.loadtxt(f"frames/speed2_frame_{i:04d}.txt") for i in range(n_frames)]

# Normalize color scale across all frames
vmin = min(frame.min() for frame in frames)
vmax = max(frame.max() for frame in frames)

fig = plt.figure()
# im = plt.imshow(frames[0], cmap="plasma", origin="lower", aspect="auto", vmin=vmin, vmax=vmax)
im = plt.imshow(frames[0])
# plt.colorbar(im)
plt.title("Speed² (ux² + uy²)")

def animate_func(i):
    im.set_array(frames[i])
    return [im]

anim = animation.FuncAnimation(
    fig,
    animate_func,
    frames=n_frames,
    interval=1000 / fps,
    blit=True
)

# Save and show
anim.save("animation_speed2.mp4", writer=animation.FFMpegWriter(fps=fps))
# plt.show()
