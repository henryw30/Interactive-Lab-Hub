import serial
import time

ser = serial.Serial('/dev/ttyUSB0', 9600)
while True:
    try:
        message = input("Enter a message: ")
        #ser.write(b'sos') #arbitrary message
        ser.write(bytes(message, 'utf-8'))
        time.sleep(1.25)
    except KeyboardInterrupt:
        ser.close();
        break
