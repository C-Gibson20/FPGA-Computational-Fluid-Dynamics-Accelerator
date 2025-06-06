import socket
import numpy as np
import os
import time

HOST = '192.168.1.65'
PORT = 9005
INPUT_PATH = r"C:\Year 2\PROJECT\output.txt"  
MAX_RETRIES = 3
RETRY_DELAY = 2  

def validate_file(filepath):
    """Check if file exists and is readable"""
    if not os.path.exists(filepath):
        raise FileNotFoundError(f"File not found: {filepath}")
    if not os.access(filepath, os.R_OK):
        raise PermissionError(f"No read permissions for file: {filepath}")

def send_data(sock, filepath):
    """Send file data over socket"""
    try:
        with open(filepath, 'rb') as f:
            data = f.read()
            print(f"Read {len(data)} bytes from {filepath}")
            
            filename = os.path.basename(filepath)
            sock.sendall(filename.encode('utf-8'))
            time.sleep(0.1)  
            
            sock.sendall(data)
            print(f"Sent {len(data)} bytes to {HOST}:{PORT}")
            
    except Exception as e:
        print(f"Error sending file: {e}")
        raise

def main():
    try:
        validate_file(INPUT_PATH)
        print(f"File validated: {INPUT_PATH}")
    except Exception as e:
        print(f"File validation failed: {e}")
        return

    # Socket connection with retries
    for attempt in range(MAX_RETRIES):
        try:
            with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
                print(f"Attempt {attempt + 1}/{MAX_RETRIES}: Connecting to {HOST}:{PORT}...")
                s.settimeout(10)  
                s.connect((HOST, PORT))
                print("Connection established")
                
                send_data(s, INPUT_PATH)
                break  # Success - exit retry loop
                
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
        print(f"Failed to connect after {MAX_RETRIES} attempts")

if __name__ == "__main__":
    main()