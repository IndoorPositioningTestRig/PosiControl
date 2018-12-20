from endpoints.Communication.Message import Message
import struct

VALUES = ["p", "i", "d"]


def decode_float(message: Message) -> dict:
    pid_dict = {}

    for num, i in struct.iter_unpack('<f', message.data):
        pid_dict[VALUES[i]] = num

    return pid_dict
