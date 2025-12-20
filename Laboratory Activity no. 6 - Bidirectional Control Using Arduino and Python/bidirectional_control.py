import serial
import time

ser = serial.Serial('COM4', 9600, timeout=1)
time.sleep(2)  

print("Listening to Arduino...")

while True:
    if ser.in_waiting:
        data = ser.readline().decode().strip().upper()

        if data == 'R':
            ser.write(b'1')
            print("Button 1 → Sent 1 (Red Toggle)")

        elif data == 'G':
            ser.write(b'2')
            print("Button 2 → Sent 2 (Green Toggle)")

        elif data == 'B':
            ser.write(b'3')
            print("Button 3 → Sent 3 (Blue Toggle)")