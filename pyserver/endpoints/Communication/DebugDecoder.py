from endpoints.Communication.Message import Message
import struct
from typing import List


class DataPoint:
    def __init__(self, setpoint: int, output: int, encoder: int):
        self.setpoint = setpoint
        self.output = output
        self.encoder = encoder

    def to_string(self):
        return "setpoint: {}, output: {}, encoder: {}"\
            .format(self.setpoint, self.output, self.encoder)


def decode(message: Message) -> List[DataPoint]:
    data: tuple = struct.unpack("<H", message.data)
    data_list = []
    for i in range(0, len(data), 3):
        datapoint = DataPoint(data[i], data[i+1], data[i+2])
        data_list.append(datapoint)
        print(datapoint.to_string())
    return data_list
