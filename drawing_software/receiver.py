import socket
import numpy as np
from pynq import Overlay

ol = Overlay()

HOST = '192.168.2.99'
PORT = 9005

overlay = Overlay('project_1.bit')
AXI = ol.axi_gpio_0.channel1

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.bind((HOST, PORT))
    s.listen()
    conn, addr = s.accept()
    count = 0
    with conn:
        while True:
            data = conn.recv(2)
            count = count + 1
    address = count
    AXI.write((1 << 31) | (address << 16) | data)
conn.close()
s.close()
