import socket
import numpy as np
from pynq import Overlay

PORT = 9005
size = 2500

ol = Overlay('xxxxxxx.bit')
AXI = ol.imgxxxx.channel1

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.bind(('0.0.0.0', PORT))
    s.listen()
    conn, addr = s.accept()
    with conn:
        while True:
            data_buff = bytearray(conn.recv(np.ceil(size/8)))  
            for i in range(0, size, 2):
                word_bytes = data_buff[i:i+2]
                if len(word_bytes) < 2:
                    continue  # skip incomplete word
                word = int.from_bytes(word_bytes, byteorder='big') 
                AXI.write((0 << 31) | (i << 16) | word, 0xFFFFFFFF)
            AXI.write(1<<31,0x800000000) 
conn.close()
s.close()
