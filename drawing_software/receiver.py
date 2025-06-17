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
    with conn:
        while True:
            data_buff = bytearray(conn.recv(156))  
            for i in range(0, len(data_buff), 4):
                word_bytes = data_buff[i:i+4]
                if len(word_bytes) < 4:
                    continue  # skip incomplete word
                word = int.from_bytes(word_bytes, byteorder='big') 
                AXI.write((1 << 31) | (i << 16) | word) 
conn.close()
s.close()
