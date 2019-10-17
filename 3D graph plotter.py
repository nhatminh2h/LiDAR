import serial
import time
import matplotlib as plot
import numpy

#Arduino port here
port = 'com5'

ArduinoSerial = serial.Serial(port, 9600)#serial port opject
time.sleep(0.2)

while 1:
    i=0
    x,y,z = ([] for i in range(3))#make list for 
    x.append(ArduinoSerial.readline())
    y.append(ArduinoSerial.readline())
    z.append(ArduinoSerial.readline())
