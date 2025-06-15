import pygame
import socket
import time
import numpy as np
from PIL import Image

def save(canvas):
    timestamp = int(time.time())
    file_name_orig = f"canvas_{timestamp}.png"
    pygame.image.save(canvas, file_name_orig)

    img = Image.open(file_name_orig).convert("L").resize((50, 50), Image.LANCZOS)
    img.save("50x50img.png")

    binary_array = (np.array(img) < 128).astype(np.uint8).flatten()
    packed_bits = np.packbits(binary_array)

    file_name_bin = f"{timestamp}_data.bin"
    with open(file_name_bin, "wb") as f:
        f.write(packed_bits.tobytes())

    return packed_bits.tobytes()

def send(canvas, HOST, PORT, MAX_RETRIES=3, RETRY_DELAY=2):
    data = save(canvas)

    for attempt in range(MAX_RETRIES):
        try:
            with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
                print(f"Attempt {attempt + 1}: Connecting to {HOST}:{PORT}...")
                s.settimeout(10)
                s.connect((HOST, PORT))
                s.sendall(data)
                print(f"Sent {len(data)} bytes")
                break
        except socket.timeout:
            print("Connection timed out")
        except ConnectionRefusedError:
            print("Connection refused - is the server running?")
        except Exception as e:
            print(f"Connection error: {e}")
        
        if attempt < MAX_RETRIES - 1:
            print(f"Retrying in {RETRY_DELAY} seconds...")
            time.sleep(RETRY_DELAY)
    else:
        print("Failed to connect after retries")
