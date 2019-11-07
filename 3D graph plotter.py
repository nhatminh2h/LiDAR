import serial
from mpl_toolkits.mplot3d import Axes3D
import matplotlib.pyplot as plt
import numpy as np
from math import cos, sin,degrees

#Arduino port here
port = 'com3'
ArduinoSerial = serial.Serial(port, 9600)#serial port object

#plot setup
fig = plt.figure()
ax = plt.axes(projection="3d")
#plt.axis('off')

#data arrays
theta, phi, r = ([0] for i in range(3))#RAW data in polar
x, y , z = ([0] for i in range(3))#3D coordinate

def animate(i):
    graph_data = open('test.txt', 'r').read()
    lines = graph_data.split('\n')

while True:
    i=0
    theta[i] = (ArduinoSerial.readline().decode())#h_angle
    phi[i] = (ArduinoSerial.readline().decode())#v_angle
    r[i] = (ArduinoSerial.readline().decode())#distance

    temp_t = int(theta[i])
    temp_p = 135 - int(phi[i])#adjusting for v_angle offset
    temp_r = int(r[i])

    x[i] = int((temp_r*cos(degrees(temp_p))*cos(degrees(temp_t))))
    y[i] = int((temp_r*cos(degrees(temp_p))*sin(degrees(temp_t))))
    z[i] = int((temp_r*sin(degrees(temp_p))))

    #add filtering here
    print(x[i])
    print(y[i])
    print(z[i])
    ax.clear()
    ax.scatter(x,y,z)
    plt.show()
    i+= 1
