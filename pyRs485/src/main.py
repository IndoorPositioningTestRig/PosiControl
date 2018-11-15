import sys
from Communication.Communication import Communication

PORT = "/dev/ttyS0"
RS485_SWITCH = 18

# Write and read are inverted compared to the Arduino
RS485_READ = 0
RS485_WRITE = 1


def read_loop(communication: Communication, once=False):
    print("reading...")

    count = 0
    while True:
        read = communication.read_line()
        print("read: " + str(read) + " " + str(count))
        sys.stdout.flush()
        count += 1
        if once:
            return


def write_loop(communication: Communication, once=False):
    count = 0
    while True:
        print("Writing... " + str(count))
        communication.write(b"Hello World", 1, 1)
        sys.stdout.flush()
        count += 1
        if once:
            return


def main():
    communication = Communication()
    communication.setup()

    once = False
    read = False
    for arg in sys.argv:
        if arg.lower() == "read":
            read = True
        elif arg.lower() == "once":
            once = True

    if read:
        read_loop(communication, once)
    else:
        write_loop(communication, once)


if __name__ == "__main__":
    main()
