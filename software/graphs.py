import matplotlib.pyplot as plt
import numpy as np

# Data
metrics = ['Avg Transfer Time (s)', 'Max Theoretical FPS', 'Skipped Frames @120FPS']
gpio_values = [0.191763162, 5.21476591, 24]
dma_values = [0.001, 1000, 0]
y_labels = ['Transfer Time (s)', 'FPS', 'Skipped Frames']

# Create figure with 3 subplots side by side
fig, axes = plt.subplots(1, 3, figsize=(14, 5), sharex=False)

# Bar settings
bar_width = 0.4
x = np.arange(2)
methods = ['GPIO', 'DMA']
colors = ['tab:orange', 'tab:blue']

for i, ax in enumerate(axes):
    bars = ax.bar(x, [gpio_values[i], dma_values[i]], color=colors, width=bar_width)
    
    # Label axes
    ax.set_title(metrics[i])
    ax.set_ylabel(y_labels[i])
    ax.set_xticks(x)
    ax.set_xticklabels(methods)
    
    # Add some space above the tallest bar
    max_val = max(gpio_values[i], dma_values[i])
    ax.set_ylim(0, max_val * 1.2 if max_val != 0 else 1)

    # Annotate bar values
    for bar in bars:
        height = bar.get_height()
        ax.annotate(f'{height:.3f}',
                    xy=(bar.get_x() + bar.get_width() / 2, height),
                    xytext=(0, 3),  # offset
                    textcoords="offset points",
                    ha='center', va='bottom', fontsize=9)

# Overall layout
fig.suptitle('AXI-GPIO vs AXI-DMA Performance Comparison', fontsize=14, y=1.05)
fig.tight_layout()

plt.show()
