import numpy as np
import matplotlib.pyplot as plt

def distance(x1, y1, x2, y2):
    return np.sqrt((x2 - x1)**2 + (y2 - y1)**2)

def main():
    # Grid and simulation settings
    Nx, Ny = 300, 100
    Nt = 100000
    tau = 0.53
    u0 = 0.1  # Inlet velocity
    plot_every = 1000

    # Lattice parameters for D2Q9
    NL = 9
    cxs = np.array([0, 1, 0, -1,  0, 1, -1, -1,  1])
    cys = np.array([0, 0, 1,  0, -1, 1,  1, -1, -1])
    weights = np.array([4/9] + [1/9]*4 + [1/36]*4)
    bounce_back = [0, 3, 4, 1, 2, 7, 8, 5, 6]

    # Initialize fluid variables
    rho = np.ones((Ny, Nx))
    ux = np.full((Ny, Nx), u0)
    uy = np.zeros((Ny, Nx))

    # Initialize f using equilibrium
    F = np.zeros((Ny, Nx, NL))
    for i, cx, cy, w in zip(range(NL), cxs, cys, weights):
        cu = cx * ux + cy * uy
        F[:, :, i] = rho * w * (1 + 3*cu + 4.5*cu**2 - 1.5*(ux**2 + uy**2))

    # Create cylinder obstacle
    cylinder = np.full((Ny, Nx), False)
    for y in range(Ny):
        for x in range(Nx):
            if distance(Nx//4, Ny//2, x, y) < 20:
                cylinder[y, x] = True

    # Visualization setup
    plt.figure(figsize=(8, 3))

    for it in range(Nt):
        print(f"Step {it}")

        # Streaming
        for i, cx, cy in zip(range(NL), cxs, cys):
            F[:, :, i] = np.roll(F[:, :, i], shift=cx, axis=1)
            F[:, :, i] = np.roll(F[:, :, i], shift=cy, axis=0)

        # Bounce-back at cylinder
        F[cylinder, :] = F[cylinder, :][:, bounce_back]

        # Inlet: reimpose equilibrium
        rho[:, 0] = 1.0
        ux[:, 0] = u0
        uy[:, 0] = 0.0
        for i, cx, cy, w in zip(range(NL), cxs, cys, weights):
            cu = cx * ux[:, 0] + cy * uy[:, 0]
            F[:, 0, i] = rho[:, 0] * w * (1 + 3*cu + 4.5*cu**2 - 1.5*(ux[:, 0]**2 + uy[:, 0]**2))

        # Outlet: copy from previous column
        F[:, -1, :] = F[:, -2, :]

        # Compute macroscopic variables
        rho = np.sum(F, axis=2)
        ux = np.sum(F * cxs[None, None, :], axis=2) / rho
        uy = np.sum(F * cys[None, None, :], axis=2) / rho

        ux[cylinder] = 0
        uy[cylinder] = 0

        # Collision (BGK relaxation)
        Feq = np.zeros_like(F)
        for i, cx, cy, w in zip(range(NL), cxs, cys, weights):
            cu = cx * ux + cy * uy
            Feq[:, :, i] = rho * w * (1 + 3*cu + 4.5*cu**2 - 1.5*(ux**2 + uy**2))
        F += -(1.0 / tau) * (F - Feq)

        # Plot
        if it % plot_every == 0:
            plt.imshow(np.sqrt(ux**2 + uy**2), cmap="inferno")
            plt.title(f"Velocity magnitude at step {it}")
            plt.axis("off")
            plt.pause(0.01)
            plt.cla()

    plt.show()

if __name__ == "__main__":
    main()
