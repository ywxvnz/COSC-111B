import serial
import time

ARDUINO_PORT = "COM10"  
BAUD_RATE = 9600

def print_menu():
    print("\nArduino LED Controller")
    print("[R] Red ON/OFF")
    print("[G] Green ON/OFF")
    print("[Y] Yellow ON/OFF")
    print("[A] All ON")
    print("[O] All OFF")
    print("[X] Exit")
    print()

def main():
    try:
        with serial.Serial(ARDUINO_PORT, BAUD_RATE, timeout=1) as ser:
            time.sleep(2) 

            while True:
                print_menu()
                choice = input("Enter choice: ").strip()

                if not choice:
                    continue

                cmd = choice[0].upper() 

                if cmd == "X":
                    print("Exiting program...")
                    break

                if cmd in ['R', 'G', 'Y', 'A', 'O']:
                    ser.write(cmd.encode()) 
                    time.sleep(0.1)

                    while ser.in_waiting > 0:
                        response = ser.readline().decode(errors="ignore").strip()
                        if response: 
                            print("Arduino:", response)

                else:
                    print("Invalid option.")

    except serial.SerialException: #catch serial port errors
        print("ERROR: Could not open serial port.")

if __name__ == "__main__": 
    main()
