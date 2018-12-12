import serial
import serial.rs485
from serial.rs485 import RS485
import wiringpi
import json
from endpoints.Communication.Message import Message
from endpoints.Communication import DebugDecoder

PORT = "/dev/ttyS0"
RS485_SWITCH = 18

# Write and read are inverted compared to the Arduino
RS485_READ = 0
RS485_WRITE = 1

RS485_UNINITIALIZED = 2

SENDER_NUM = 55

START_INT = 0x80
START_BYTE = b"\x80"


def validate_type(msg_type: int):
    return 0 < msg_type < 4


class Communication:
    REQUEST = 1
    COMMAND = 2
    RESPONSE = 3

    def __init__(self):
        self.state = RS485_UNINITIALIZED
        self.ser = RS485(timeout=5000)

    def set_mode(self, mode=RS485_READ):
        if mode is RS485_WRITE:
            self.state = RS485_WRITE
            wiringpi.digitalWrite(RS485_SWITCH, RS485_WRITE)
        else:
            self.state = RS485_READ
            wiringpi.digitalWrite(RS485_SWITCH, RS485_READ)

    def write_json(self, data: dict, target: int, message_type: int):
        data_str = json.dumps(data)
        self.write(bytes(data_str, "utf-8"), target, message_type)

    def write(self, data: bytes, target: int, message_type: int):
        # Add 5, because there are 5 fields in the header
        length = len(data) + 5
        # Build the header and message
        header = bytes([START_INT, SENDER_NUM, target, message_type, length])
        message = header + data
        print("sending: " + str(message) + " len: " + str(length) + " actual: " + str(
            len(message)))

        if self.state is RS485_UNINITIALIZED:
            raise Exception("rs485 communication Not initialised")

        if self.state is not RS485_WRITE:
            self.set_mode(RS485_WRITE)

        self.ser.write(message)

    def read(self):
        read = self.ser.read()
        if read == START_BYTE:
            message = Message()
            # Build the the header
            header = self.ser.read(4)
            message.sender = int(header[0])
            message.target = int(header[1])
            message.message_type = int(header[2])
            message.length = int(header[3])

            if message.length > 0:
                # Read the message content
                message.data = self.ser.read(message.length - 5)
                # message.data += content.decode('utf-8')

            return DebugDecoder.decode(message)

    def read_line(self):
        if self.state is RS485_UNINITIALIZED:
            raise Exception("rs485 communication Not initialised")

        if self.state is not RS485_READ:
            self.set_mode(RS485_READ)

        return self.ser.readline()

    def setup(self):
        wiringpi.wiringPiSetupGpio()
        wiringpi.pinMode(RS485_SWITCH, wiringpi.OUTPUT)

        try:
            self.ser = RS485(port=PORT)
        except serial.SerialException:
            print("Failed to open port: " + PORT)
            return False

        if not self.ser.is_open:
            print("Serial port: " + PORT + " is not open")
            return False

        self.ser.rs485_mode = serial.rs485.RS485Settings()
        self.set_mode(RS485_READ)
        return True
