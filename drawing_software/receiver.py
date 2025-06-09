import socket
import numpy as np
from pynq import MMIO, Overlay

HOST = '192.168.2.99'
PORT = 9090

overlay = Overlay('project_1.bit')
overlay.download()

#choose address on vivado address editor
mmio = MMIO()

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.bind((HOST, PORT))
    s.listen()
    conn, addr = s.accept
    with conn:
        while True:
            data = conn.recv(79)
            if not data:
                break
            conn.sendall(data)
    gpio.write(data)
conn.close()
sock.close()
