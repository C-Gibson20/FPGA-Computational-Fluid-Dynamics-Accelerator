import socket
import numpy as np
from pynq import Overlay

ol = Overlay()

HOST = '192.168.2.99'
PORT = 9005

overlay = Overlay('project_1.bit')
AXI = ol.axi_gpio_0.channel1
AXI_READY = ol.axi_gpio0.channel1

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
    AXI.write(data)
    AXI_READY.write(1)
conn.close()
s.close()
