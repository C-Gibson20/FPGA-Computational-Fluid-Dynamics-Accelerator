def float_to_q313_int(x):
    return int(round(x * 8192)) & 0xFFFF  # simulate 16-bit wraparound

def q313_to_float(x):
    return x / 8192.0


directions = {
    'rest':   (0, 0, 0),         # 1/3

    # Face-centered (6)
    'xp':     (1, 0, 0),         # 1/18
    'xn':     (-1, 0, 0),
    'yp':     (0, 1, 0),
    'yn':     (0, -1, 0),
    'zp':     (0, 0, 1),
    'zn':     (0, 0, -1),

    # Edge-centered (12)
    'xpyp':   (1, 1, 0),         # 1/36
    'xpyn':   (1, -1, 0),
    'xnyp':   (-1, 1, 0),
    'xnyn':   (-1, -1, 0),

    'xpzp':   (1, 0, 1),
    'xpzn':   (1, 0, -1),
    'xnzp':   (-1, 0, 1),
    'xnzn':   (-1, 0, -1),

    'ypzp':   (0, 1, 1),
    'ypzn':   (0, 1, -1),
    'ynzp':   (0, -1, 1),
    'ynzn':   (0, -1, -1)
}

weights = {
    'rest':  1/3,
    'xp':    1/18, 'xn':   1/18, 'yp':   1/18, 'yn':   1/18, 'zp':   1/18, 'zn':   1/18,
    'xpyp':  1/36, 'xpyn': 1/36, 'xnyp': 1/36, 'xnyn': 1/36,
    'xpzp':  1/36, 'xpzn': 1/36, 'xnzp': 1/36, 'xnzn': 1/36,
    'ypzp':  1/36, 'ypzn': 1/36, 'ynzp': 1/36, 'ynzn': 1/36
}

f_i_int = {
    'rest':  0x0E00,  # ~0.4375

    # Face-centered directions (±x, ±y, ±z)
    'xp':    0x0380,  # ~0.1094
    'xn':    0x0380,
    'yp':    0x0370,
    'yn':    0x0370,
    'zp':    0x0390,
    'zn':    0x0390,

    # Diagonal directions in XY plane
    'xpyp':  0x00D0,  # ~0.1016
    'xpyn':  0x00D0,
    'xnyp':  0x00C8,
    'xnyn':  0x00C8,

    # Diagonal directions in XZ plane
    'xpzp':  0x00E0,
    'xpzn':  0x00E0,
    'xnzp':  0x00D8,
    'xnzn':  0x00D8,

    # Diagonal directions in YZ plane
    'ypzp':  0x00E8,
    'ypzn':  0x00E8,
    'ynzp':  0x00D5,
    'ynzn':  0x00D5
}

f_i = {k: q313_to_float(v) for k, v in f_i_int.items()}
rho = sum(f_i.values())

u_x = sum(f_i[k] * directions[k][0] for k in f_i) / rho
u_y = sum(f_i[k] * directions[k][1] for k in f_i) / rho
u_z = sum(f_i[k] * directions[k][2] for k in f_i) / rho

omega = 2.0  # tau = 0.5

data = {}

for k in f_i:
    e = directions[k]
    fi = f_i[k]

    eu = e[0]*u_x + e[1]*u_y + e[2]*u_z
    uu = u_x**2 + u_y**2 + u_z**2
    poly = 1 + 3 * eu + 4.5 * eu**2 - 1.5 * uu
    feq = weights[k] * rho * poly
    fnew = fi + omega * (feq - fi)

    data[k] = {
        'f_i_int': f_i_int[k],
        'eu_int': float_to_q313_int(eu),
        'uu_int': float_to_q313_int(uu),
        'poly_int': float_to_q313_int(poly),
        'f_eq_int': float_to_q313_int(feq),
        'f_new_int': float_to_q313_int(fnew)
    }

print("Direction | f_i_int | eu_int | uu_int | poly_int | f_eq_int | f_new_int")
print("------------------------------------------------------------------------")
for k in data:
    d = data[k]
    print(f"{k:<9}| {d['f_i_int']:8} | {d['eu_int']:7} | {d['uu_int']:7} | {d['poly_int']:9} |"
          f" {d['f_eq_int']:9} | {d['f_new_int']:10}")

print("\nMacroscopic velocities:")
print(f"u_x = {u_x:.6f} ({float_to_q313_int(u_x)} in Q3.13)")
print(f"u_y = {u_y:.6f} ({float_to_q313_int(u_y)} in Q3.13)")
print(f"u_z = {u_z:.6f} ({float_to_q313_int(u_z)} in Q3.13)")
