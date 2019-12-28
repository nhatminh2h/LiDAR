import serial
from mpl_toolkits.mplot3d import Axes3D
import matplotlib.pyplot as plt
import matplotlib.animation as animation
import numpy as np
from math import cos, sin,radians, pi

#Arduino port here
port = 'com3'
ArduinoSerial = serial.Serial(port, 115200)#serial port object

#data arrays
#theta, phi, r = ([0] for i in rannge(3))#RAW data in polar
#x, y , z = ([0] for i in range(3))#3D coordinate
x = [0]
y = [0]
z = [0]

def update_graph(num):

    temp_t = int((ArduinoSerial.readline().decode("utf-8")))
    temp_p = 135 - int(ArduinoSerial.readline().decode("utf-8"))#adjusting for v_angle offset
    temp_r = int(ArduinoSerial.readline().decode("utf-8"))

    x.append((temp_r*cos(radians(temp_p))*cos(radians(temp_t))))
    y.append((temp_r*cos(radians(temp_p))*sin(radians(temp_t))))
    z.append((temp_r*sin(radians(temp_p))))
    #add filtering here
    graph._offsets3d = (x,y,z)
    return graph

#plot setup
fig = plt.figure()
ax = fig.add_subplot(111, projection="3d")
graph = ax.scatter(x,y,z, c='b',marker='.')
#plt.axis('off')

ani = animation.FuncAnimation(fig, update_graph, frames=200, interval=20, blit=False)
plt.show()
