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
    datapoint = []
    theta = ArduinoSerial.readline()
    phi = ArduinoSerial.readline()
    r = ArduinoSerial.readline()

    x = r*cos(phi)*cos(theta)
    y = r*cos(phi)*sin(theta)
    z = r*sin(phi)

    #add filtering here

    datapoint.append([x,y,z])
    for i in datapoint:
        print(i)
