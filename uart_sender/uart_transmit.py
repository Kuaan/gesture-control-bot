import serial
import time

ser = serial.Serial('COM3', 115200)  #### Setting the COM port depenced on your ESP32 

def send_command(cmd: str):
    ser.write(f"{cmd}\n".encode())
    print(f"Sent: {cmd}")

if __name__ == "__main__":
    while True:
        cmd = input("Enter command (f = forward, s = stop): ")
        send_command(cmd)

