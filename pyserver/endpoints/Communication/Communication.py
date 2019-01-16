import serial
import serial.rs485
from serial.rs485 import RS485
import wiringpi
import json
from endpoints.Communication.Message import Message
from endpoints.Communication import DebugDecoder
from typing import Optional, List
from endpoints.Communication import PidDecoder


"""
 4 3
 1 2 
   8 5
   7 6
"""


PORT = "/dev/ttyS0"
RS485_SWITCH = 18

# Write and read are inverted compared to the Arduino
RS485_READ = 0
RS485_WRITE = 1

RS485_UNINITIALIZED = 2

SENDER_NUM = 55

START_INT = 0x80
START_BYTE = b"\x80"

SERIAL_TIMEOUT = 5


def validate_type(msg_type: int):
    return 0 < msg_type < 4


class Communication:
    REQUEST = 1
    COMMAND = 2
    RESPONSE = 3

    def __init__(self):
        self.state = RS485_UNINITIALIZED
        self.ser = RS485()

    def set_mode(self, mode=RS485_READ):
        if mode is RS485_WRITE:
            self.state = RS485_WRITE
            wiringpi.digitalWrite(RS485_SWITCH, RS485_WRITE)
        else:
            self.state = RS485_READ
            wiringpi.digitalWrite(RS485_SWITCH, RS485_READ)

    def flush(self):
        self.ser.flush()

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

    def read_pid(self) -> Optional[dict]:
        """ Read P I D values in the form of a dict """
        msg = self.read()
        if msg is None:
            return None
        return PidDecoder.decode_float(msg)

    def read_data_points(self) -> List[DebugDecoder.DataPoint]:
        """ Read dataPoints stored on an Arduino """
        print('decoding...')
        message = self.read(10)
        if message is None:
            return []

        decoded = DebugDecoder.decode_int16(message)
        print('done!')
        return decoded

    def read_str(self) -> Optional[str]:
        """ Read any string """
        message = self.read()
        if message is None:
            return None

        res_str = message.data.decode("utf-8")
        print('received str', res_str)
        return res_str

    def read(self, timeout=SERIAL_TIMEOUT) -> Optional[Message]:
        """ Read a raw message """
        print('reading')
        self.set_mode(RS485_READ)
        self.ser.timeout = timeout
        while True:
            bytes_read = self.ser.read()
            if bytes_read == START_BYTE:
                break
            elif bytes_read == b'':
                print("Failed to read!")
                return None
            else:
                print('read junk:', str(bytes_read))

        print('read', len(bytes_read))
        print(bytes_read)
        message = Message()
        # Build the the header
        header = self.ser.read(4)
        message.sender = int(header[0])
        message.target = int(header[1])
        message.message_type = int(header[2])
        message.length = int(header[3])
        print('reading message with len: ' + str(message.length))

        if message.length > 0:
            message.data = self.ser.read(message.length - 5)
        return message

    def read_line(self):
        """ Read a line of text """
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
