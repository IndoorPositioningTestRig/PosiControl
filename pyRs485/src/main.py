import serial
import serial.rs485
from serial.rs485 import RS485
import sys
from Communication.Communication import Communication

PORT = "/dev/ttyS0"
RS485_SWITCH = 18

# Write and read are inverted compared to the Arduino
RS485_READ = 0
RS485_WRITE = 1


def read_loop(communication: Communication):
    print("reading...")

    count = 0
    while True:
        read = communication.read_line()
        print("read: " + str(read) + " " + str(count))
        sys.stdout.flush()
        count += 1


def write_loop(communication: Communication):
    count = 0
    while True:
        print("Writing... " + str(count))
        communication.write(b"Hello World", 1, 1)
        sys.stdout.flush()
        count += 1


def main():
    communication = Communication()

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
        read_loop(communication)
    else:
        write_loop(communication)


if __name__ == "__main__":
    main()
