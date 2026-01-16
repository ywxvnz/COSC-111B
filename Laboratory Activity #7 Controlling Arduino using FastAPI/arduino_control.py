from fastapi import FastAPI
import serial
import time

SERIAL_PORT = "COM3"
BAUD_RATE = 9600

arduino = serial.Serial(SERIAL_PORT, BAUD_RATE, timeout=1)
time.sleep(2)

app = FastAPI(title="Arduino LED Control API")

def send_to_arduino(data: str):
    arduino.write(data.encode())
    time.sleep(0.1)

@app.get("/led/{color}")
def control_led(color: str):
    color = color.lower()

    if color == "red":
        send_to_arduino("1")
        return {"status": "Red LED toggled"}
    elif color == "green":
        send_to_arduino("2")
        return {"status": "Green LED toggled"}
    elif color == "blue":
        send_to_arduino("3")
        return {"status": "Blue LED toggled"}
    else:
        return {"error": "Invalid color. Use red, green, or blue."}

@app.get("/led/on")
def led_on():
    send_to_arduino("1")
    send_to_arduino("2")
    send_to_arduino("3")
    return {"status": "All LEDs turned ON"}

@app.get("/led/off")
def led_off():
    send_to_arduino("1")
    send_to_arduino("2")
    send_to_arduino("3")
    return {"status": "All LEDs turned OFF"}
