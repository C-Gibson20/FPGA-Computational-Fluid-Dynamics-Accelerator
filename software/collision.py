def float_to_q313_int(x):
    return int(round(x * 8192)) & 0xFFFF  # simulate 16-bit wraparound

def q313_to_float(x):
    return x / 8192.0

# Initial f_i values from testbench (Q3.13)
f_i_int = {
    # 'null': 0x0E38,
    # 'n':    0x038E,
    # 's':    0x038E,
    # 'e':    0x038E,
    # 'w':    0x038E,
    # 'ne':   0x0150,
    # 'se':   0x00E4,
    # 'sw':   0x0090,
    # 'nw':   0x00E4
    'null': 0x0E06,
    'n':    0x037F,
    's':    0x0385,
    'e':    0x04BB,
    'w':    0x0298,
    'ne':   0x012F,
    'se':   0x012F,
    'sw':   0x00A6,
    'nw':   0x00A6
}
f_i = {k: q313_to_float(v) for k, v in f_i_int.items()}

weights = {
    'null': 4/9, 'n': 1/9, 's': 1/9, 'e': 1/9, 'w': 1/9,
    'ne': 1/36, 'se': 1/36, 'sw': 1/36, 'nw': 1/36
}
directions = {
    'null': (0, 0), 'n': (0, 1), 's': (0, -1), 'e': (1, 0), 'w': (-1, 0),
    'ne': (1, 1), 'se': (1, -1), 'sw': (-1, -1), 'nw': (-1, 1)
}

# Macroscopic values
rho = sum(f_i.values())
rho_x1 = rho * (2 - rho)
x2 = (2 - rho) * (2 - rho_x1)
x3 = x2 * (2 - rho * x2)
u_x = (f_i['e'] + f_i['ne'] + f_i['se'] - f_i['w'] - f_i['nw'] - f_i['sw']) /rho
u_y = (f_i['n'] + f_i['ne'] + f_i['nw'] - f_i['s'] - f_i['se'] - f_i['sw']) /rho

omega = 2.0  # tau = 0.5

data = {}

for k in f_i:
    e_x, e_y = directions[k]
    fi_float = f_i[k]

    eu = e_x * u_x + e_y * u_y
    uu = u_x**2 + u_y**2
    poly = 1 + 3 * eu + 4.5 * eu**2 - 1.5 * uu
    feq_val = weights[k] * rho * poly
    fnew_val = fi_float + omega * (feq_val - fi_float)

    data[k] = {
        'f_i_int': f_i_int[k],
        'eu_int': float_to_q313_int(eu),
        'uu_int': float_to_q313_int(uu),
        'poly_int': float_to_q313_int(poly),
        'f_eq_int': float_to_q313_int(feq_val),
        'f_new_int': float_to_q313_int(fnew_val)
    }

# Print table
print("Direction | f_i_int | eu_int | uu_int | poly_int | f_eq_int | f_new_int")
print("------------------------------------------------------------------------")
for k in data:
    d = data[k]
    print(f"{k:<9}| {d['f_i_int']:8} | {d['eu_int']:7} | {d['uu_int']:7} | {d['poly_int']:9} |"
          f" {d['f_eq_int']:9} | {d['f_new_int']:10}")

print("\nMacroscopic velocities:")
print(f"u_x = {u_x:.6f} ({float_to_q313_int(u_x)} in Q3.13)")
print(f"u_y = {u_y:.6f} ({float_to_q313_int(u_y)} in Q3.13)")
u_y_squared = u_y * u_y
print(f"u_y^2 = {u_y_squared:.8f} ({float_to_q313_int(u_y_squared)} in Q3.13)")