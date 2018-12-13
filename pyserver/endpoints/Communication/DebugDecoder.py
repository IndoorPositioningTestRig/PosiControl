from endpoints.Communication.Message import Message
import struct
from typing import List


class DataPoint:
    def __init__(self, setpoint: int=0, output: int=0, encoder: int=0, time: int =0):
        self.setpoint = setpoint
        self.output = output
        self.encoder = encoder
        self.time = time
        self.index = 0

    def to_string(self):
        return "setpoint: {}, output: {}, encoder: {}"\
            .format(self.setpoint, self.output, self.encoder)

    def add(self, num: int):
        if self.index == 0:
            self.setpoint = num
        elif self.index == 1:
            self.output = num
        elif self.index == 2:
            self.encoder = num
        else:
            self.time = num

        self.index += 1
        return self.index > 3

    def to_dict(self):
        return {
            "setpoint": self.setpoint,
            "output": self.output,
            "encoder": self.encoder,
            "time": self.time
        }


def decode_int16(message: Message) -> List[DataPoint]:
    data_list = []
    datapoint = DataPoint()
    for num in struct.iter_unpack('<h', message.data):
        if datapoint.add(num[0]):
            data_list.append(datapoint)
            datapoint = DataPoint()

    return data_list
