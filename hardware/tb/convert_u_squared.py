import numpy as np

INPUT_FILE = "u_squared_log.txt"
OUTPUT_FILE = "u_squared_pretty.txt"
WIDTH = 15
HEIGHT = 15
CELLS_PER_FRAME = WIDTH * HEIGHT

# Load raw Q3.13 values from Verilator
with open(INPUT_FILE, "r") as f:
    raw_values = [int(line.strip()) for line in f if line.strip()]

# Convert Q3.13 to float
float_values = [val / 8192.0 for val in raw_values]

# Split into frames
num_frames = len(float_values) // CELLS_PER_FRAME
frames = [
    float_values[i * CELLS_PER_FRAME : (i + 1) * CELLS_PER_FRAME]
    for i in range(num_frames)
]

# Save readable text output
with open(OUTPUT_FILE, "w") as f:
    for frame_idx, frame in enumerate(frames):
        f.write(f"===== Frame {frame_idx} =====\n")
        for y in range(HEIGHT):
            row = frame[y * WIDTH : (y + 1) * WIDTH]
            f.write(" ".join(f"{val:6.3f}" for val in row) + "\n")
        f.write("\n")

print(f"✅ Converted {num_frames} frames of size {WIDTH}×{HEIGHT}. Output saved to {OUTPUT_FILE}")
