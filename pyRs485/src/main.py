import serial
import serial.rs485
from serial.rs485 import RS485
import sys

PORT = "/dev/ttyS0"


def main():
    try:
        ser = RS485(port=PORT)
        # ser = serial.Serial(port=PORT)
    except serial.SerialException:
        print("Failed to open port: " + PORT)
        return
    if not ser.is_open:
        print("Serial port: " + PORT + " is not open")
        return
    ser.rs485_mode = serial.rs485.RS485Settings()
    count = 0
    while True:
        print("Writing... " + str(count))
        ser.write("Hello World")
        sys.stdout.flush()
        count += 1


if __name__ == "__main__":
    main()
