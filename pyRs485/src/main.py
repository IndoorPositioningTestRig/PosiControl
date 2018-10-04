import serial
import serial.rs485

PORT: str = "com6"


def main():
    try:
        ser = serial.Serial(port=PORT)
    except serial.SerialException:
        print("Failed to open port: " + PORT)
        return

    if not ser.is_open():
        print("Serial port: " + PORT + " is not open")
        return
    ser.rs485_mode = serial.rs485.RS485Settings()
    ser.write(b'hello')


if __name__ == "__main__":
    main()
