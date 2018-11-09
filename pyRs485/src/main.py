import serial
import serial.rs485
from serial.rs485 import RS485
import sys
import wiringpi

PORT = "/dev/ttyS0"
RS485_SWITCH = 18


def read_loop(ser):
    count = 0
    wiringpi.digitalWrite(RS485_SWITCH, 0)
    while True:
        read = ser.read(1)
        print("read: " + str(read) + " " + str(count))
        sys.stdout.flush()
        count += 1


def write_loop(ser):
    count = 0
    wiringpi.digitalWrite(RS485_SWITCH, 1)
    if ser.writable():
        print("Writable!")
    else:
        print("Not writable...")

    while True:
        print("Writing... " + str(count))
        ser.write(b"Hello World")
        sys.stdout.flush()
        count += 1


def main():
    wiringpi.wiringPiSetupGpio()
    wiringpi.pinMode(RS485_SWITCH, wiringpi.OUTPUT)

    read = False
    for arg in sys.argv:
        if arg.lower() == "read":
            read = True

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
    if read:
        read_loop(ser)
    else:
        write_loop(ser)


if __name__ == "__main__":
    main()
