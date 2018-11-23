import sys
import json
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
        read = communication.read()
        if read is None:
            continue
        print("read: " + read + " " + str(count))
        sys.stdout.flush()
        count += 1
        if once:
            return


def write_loop(communication: Communication, once=False):
    count = 0
    while True:
        print("Writing... " + str(count))
        communication.write(bytes("hello world", "utf-8"), 1, 1)
        sys.stdout.flush()
        count += 1
        if once:
            return


def main():
    communication = Communication()
    communication.setup()

    while True:
        usr = input("\u001b[34;1m$\u001b[0m ").lower()
        if usr == "read":
            msg = communication.read()
            print("read: " + str(msg))
        elif usr == "write":
            msg = {}

            target = int(input("target? "))
            if target == 0:
                print("\u001b[32;1mBroadcasting\u001b[0m")

            what = input("what")
            if what == "setpoint":
                val = int(input("value? "))
                msg["command"] = "setPoint"
                msg["point"] = val
            elif what == "retract":
                amount = int(input("Amount? "))
                speed = int(input("Speed?"))
                msg["command"] = "retract"
                msg["amount"] = amount
                msg["speed"] = speed
            elif what == "feed":
                amount = int(input("Amount? "))
                speed = int(input("Speed?"))
                msg["command"] = "feed"
                msg["amount"] = amount
                msg["speed"] = speed
            elif what == "execute":
                msg["command"] = "execute"
            elif what == "reset encoder":
                msg["command"] = "resetEncoder"

            communication.write_json(msg, target, Communication.COMMAND)
        elif usr == "exit":
            return


if __name__ == "__main__":
    main()
