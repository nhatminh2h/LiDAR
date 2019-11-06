from mpl_toolkits.mplot3d import Axes3D
import matplotlib.pyplot as plot
import numpy as np


fig = plot.figure()
ax = fig.add_subplot(111, projection='3d')
plot.axis('off')

x = [1,2,6,2,7,2,2,5,6]
y = [5,8,5,2,7,1,5,4,4]
z = [7,15,7,2,8,4,2,1,7]

ax.scatter(x,y,z)

plot.show(block=True)
