## 19 May 2025

### 🔍 CFD Research Summary

#### 📘 Overview
Began investigating **Computational Fluid Dynamics (CFD)** techniques suitable for **hardware acceleration** on an FPGA. The focus was on understanding the mathematical models that underpin fluid simulation, particularly the **Navier-Stokes equations**.

#### 🌊 Navier-Stokes Frameworks
The Navier-Stokes equations can be solved using two primary frameworks:

- **Lagrangian (Particle-Based)**  
  - Tracks individual particles as they move through space.
  - Requires computing interactions between particles (e.g., finding nearest neighbors).
  - **Computational Complexity:** Typically **O(n²)**, which is expensive and inefficient on FPGA due to limited parallel access patterns and memory bandwidth.

- **Eulerian (Grid-Based)**  
  - Solves fluid flow over a fixed spatial grid.
  - Better suited for **parallelization**, especially on FPGAs, due to its **local and structured memory access patterns**.

#### 💡 Selected Technique: Lattice Boltzmann Method (LBM)
- After evaluating different grid-based techniques, settled on the **Lattice Boltzmann Method** as the most appropriate for FPGA implementation.
- **Why LBM?**
  - It simplifies the Navier-Stokes equations into a **discrete lattice model** that uses **local, neighbor-only updates**, making it **highly parallelizable**.
  - Ideal for FPGAs as it avoids global memory access patterns and complex solvers.
  - Naturally maps well to hardware pipelines and supports **fixed-point arithmetic**, which is more resource-efficient than floating-point operations on FPGAs.

---

