import struct

test = b"\xff\xff\xff\x80"

for num in struct.iter_unpack('<h', test):
    print(num[0])


# print(unpacked[2])


