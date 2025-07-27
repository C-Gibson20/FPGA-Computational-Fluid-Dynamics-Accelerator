# FPGA Computational Fluid Dynamics Accelerator

**Imperial College London – Electronic and Information Engineering (MEng) Year 2 Final Project**<br>
**Group Members**: Charlotte Gibson, Jeremy Tan, Nishant Kidangan Mathew, Lily Martin, Kayvan Faghani

📄 [Technical Report (PDF)](./EE2_Mathematics_Accelerator-Report.pdf)

[Watch demo video](https://private-user-images.githubusercontent.com/117122578/471208525-a9407964-9750-40e9-ab45-67df105a56d4.mp4?jwt=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3NTM2MjQyODYsIm5iZiI6MTc1MzYyMzk4NiwicGF0aCI6Ii8xMTcxMjI1NzgvNDcxMjA4NTI1LWE5NDA3OTY0LTk3NTAtNDBlOS1hYjQ1LTY3ZGYxMDVhNTZkNC5tcDQ_WC1BbXotQWxnb3JpdGhtPUFXUzQtSE1BQy1TSEEyNTYmWC1BbXotQ3JlZGVudGlhbD1BS0lBVkNPRFlMU0E1M1BRSzRaQSUyRjIwMjUwNzI3JTJGdXMtZWFzdC0xJTJGczMlMkZhd3M0X3JlcXVlc3QmWC1BbXotRGF0ZT0yMDI1MDcyN1QxMzQ2MjZaJlgtQW16LUV4cGlyZXM9MzAwJlgtQW16LVNpZ25hdHVyZT1jOWNmZTM2ODJlMGRkMDk5NWUwNTlmMmY1ZDhhNTkzMTBiNzhkMWU4M2UyZGZkZTA4NWNhYzlmN2I5ZTYwN2YwJlgtQW16LVNpZ25lZEhlYWRlcnM9aG9zdCJ9.GJ1gjtk4DmiCQrbARzFIA5PJvyX7UArsPwDpKKqwzSs)

<br>

## Project Overview

The EE2 Mathematics Accelerator is an interactive, real-time **2D Computational Fluid Dynamics simulator** implemented on a **PYNQ-Z1 FPGA** platform. 

The implementation meets the EE2 brief to:
* Visualise a mathematical function in real time.
* Use parallel FPGA computation to accelerate simulation.
* Provide a compelling UI to enhance educational value.

<br>

## Key Features

* **FPGA-accelerated LBM solver** with scalable parallelism and fixed-point pipelining.
* **Custom DMA-based cache system** for high-resolution grids (300×100+).
* **Unity frontend** with compute shaders and dynamic UI for live visualisation.
* **Interactive Python drawing app** embedded within Unity for custom barrier design.
* **TCP networking architecture** to decouple computation from rendering in real time.

<br>

## System Architecture

### 1. **FPGA Backend** – *PYNQ-Z1 (Zynq 7020 SoC)*

#### LBM Solver (Verilog)

* Implements D2Q9 model: 2D lattice with 9 velocity vectors.
* Modular state machine with stream → boundary → bounce → collide pipeline.
* Parallel processing cores controlled via central FSM.
* Dual-BRAM architecture (18 total) for safe multi-timestep computation.

#### Collider Design

* Fully pipelined, 21-stage fixed-point implementation (Q3.13).
* Newton-Raphson reciprocal for division-free computation of 1/ρ.
* Avoids hardware square roots; offloaded to host-side GPU.

#### Memory & Cache System

* BRAM constrained: designed DDR caching via AXI-DMA.
* Custom `BRAM_ctlr` and `DDR_writer` Verilog modules:

  * Stream lattice data from BRAM → DDR → BRAM
  * Frame buffer managed with frame\_ready signals and streaming protocol.

#### Performance

* Clock Frequency: 100 MHz (pipelined), 10 MHz (non-pipelined baseline)
* Computation time per 50×50 frame: 0.00013s (\~10× speedup vs Python)

### 2. **Host-Side Frontend** – *Unity (C#)*

#### Rendering Engine

* GPU-based rendering using HLSL compute shaders.
* Visualises:

  * **Density** via heatmap.
  * **Velocity Magnitude** and streamlines via RK2 integration.
  * **Vorticity** with iso-contours (∂uy/∂x − ∂ux/∂y).
* Textures and buffers updated asynchronously for low-latency visual fidelity.

#### UI & Controls

* Real-time control over render modes, colour normalisation, streamline count.
* Interactive panels implemented using Unity UXML/USS.
* Tooltip hover shows per-cell fluid values.

#### Performance

* Stable 60 FPS rendering; GPU offloads all post-processing.
* Lock-free circular buffer decouples data reception and visualisation.
* Memory usage optimised via GC and buffer tuning.

### 3. **Drawing Tool** – *Python (Pygame)*

* Allows users to draw, move, and delete barriers on a 50×50 or scaled canvas.
* Barrier updates streamed to FPGA via TCP (push model).
* Shapes include circles, rectangles, polygons, and freeform drawing.
* Handles mouse interpolation to avoid simulation artifacts from gaps.

#### Integration:

* Embedded as a native Win32 child window inside Unity using `SetParent()`.
* Bitstreamed 2500-bit barrier array written via AxiGPIO.
* Custom IP ensures synchronisation with simulation pipeline.

### 4. **Communication Pipeline**

#### FPGA → PS Interface

* AXI DMA (S2MM) streams per-frame data (ρ, |u|², ux, uy).
* Custom AXI streaming master IP ensures AXI protocol compliance.

#### PS → Host Interface

* TCP-based transmission from PYNQ to Unity over Ethernet.
* Binary 8-byte packets per cell, streamed in row-major order.
* Push-only, asynchronous receive → avoids polling latency.

#### Protocol Format:

| Field | Bytes |
| ----- | ----- |
| ρ     | 2     |
| u^2   | 2     |
| ux    | 2     |
| uy    | 2     |

<br>

## Performance Summary

| Metric                    | Value                            |
| ------------------------- | -------------------------------- |
| Grid Resolution           | 300 × 100                        |
| Computation (50×50 frame) | 0.00013s (FPGA)                  |
| Python/Numpy (same frame) | 0.00098s                         |
| Full pipeline latency     | 0.00224s (FPGA + Unity)          |
| TCP Throughput            | \~126 FPS (300×100)              |

<br>

## Testing & Verification

* Verilog modules verified via **Verilator + GTKWave** testbenches.
* FPGA outputs validated against a Python LBM reference implementation.
* Unity visualisations benchmarked via Unity Profiler; memory and GC tuned.
* Drawing tool evaluated through user studies; refinements included dragging and labels.

<br>

## Academic Context

This project was developed as part of the **Year 2 Electronic Design Project** for the MEng in Electronic and Information Engineering course at **Imperial College London**. It exemplifies real-world integration of:

* Digital logic design (Verilog)
* Hardware/software co-design (FPGA + host)
* Real-time networking and protocol design
* GPU rendering and interaction design
* Agile project methodology (5-week sprint-based delivery)

<br>

## Contributors

| Name                        | Role                                            |
| --------------------------- | ----------------------------------------------- |
| **Nishant Kidangan Mathew** | FPGA implementation, cache system               |
| **Lily Martin**             | Drawing software, integration                   |
| **Jeremy Tan**              | Collider, LBM debugging, testbenches            |
| **Kayvan Faghani**          | LBM solver development, system architecture     |
| **Charlotte Gibson**        | Unity frontend, shader programming, cache logic |

<br>

## Repository Structure

```bash
├── fpga/                 # Verilog: LBM Solver, Cache, DMA, AXI IPs
├── unity_frontend/       # Unity project: TCP Client, Shaders, UI
├── drawing_tool/         # Python barrier designer using Pygame
├── notebooks/            # Jupyter notebooks for PYNQ control & config
├── report/               # Final PDF report
└── README.md             # This file
```
