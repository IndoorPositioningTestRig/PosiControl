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
    communication.setup()

    read = False
    for arg in sys.argv:
        if arg.lower() == "read":
            read = True

    if read:
        read_loop(communication)
    else:
        write_loop(communication)


if __name__ == "__main__":
    main()
