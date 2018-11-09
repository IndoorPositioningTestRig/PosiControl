import serial
import serial.rs485
from serial.rs485 import RS485
import sys
import wiringpi

PORT = "/dev/ttyS0"


def main():
    wiringpi.wiringPiSetup()
    wiringpi.pinMode(18, wiringpi.OUTPUT)
    wiringpi.digitalWrite(18, wiringpi.LOW)

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
    print("Writing...")
    ser.read(1)
    sys.stdout.flush()


if __name__ == "__main__":
    main()
