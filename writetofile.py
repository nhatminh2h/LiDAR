import serial
import numpy as np
from math import cos, sin,radians, pi


#Arduino port here
port = 'com3'
ArduinoSerial = serial.Serial(port, 115200)#serial port object

#data arrays
#theta, phi, r = ([0] for i in rannge(3))#RAW data in polar
#x, y , z = ([0] for i in range(3))#3D coordinate
f = open("datafile.txt","w+")

def format(f):
    return "%.0f" %f

while (1):
    temp_t = int((ArduinoSerial.readline().decode("utf-8")))
    temp_p = 135 - int(ArduinoSerial.readline().decode("utf-8"))#adjusting for v_angle offset
    temp_r = int(ArduinoSerial.readline().decode("utf-8"))

    x = ((temp_r*cos(radians(temp_p))*cos(radians(temp_t))))
    y = ((temp_r*cos(radians(temp_p))*sin(radians(temp_t))))
    z = ((temp_r*sin(radians(temp_p))))

    x = format(x)
    y = format(y)
    z = format(z)

    f.write(str(x))
    f.write(",")
    f.write(str(y))
    f.write(",")
    f.write(str(z))
    f.write("\n")
