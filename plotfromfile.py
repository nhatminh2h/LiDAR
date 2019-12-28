from mpl_toolkits.mplot3d import Axes3D
import matplotlib.pyplot as plt
from matplotlib import cm
import numpy as np
import pandas as pd

fig = plt.figure()
ax = fig.add_subplot(111, projection = '3d')

data = pd.read_csv('datafile.txt',sep=",", header=None)
data.columns = ['x','y','z']
data = data[data.z != 0]
data = data[data.x < 300]
data = data[data.y < 400]
data = data[data.z < 300]




ax.scatter(data.x, data.y, data.z,s=2, marker='.', cmap=plt.get_cmap("plasma"))
ax.set_xlabel('x')
ax.set_ylabel('y')
ax.set_zlabel('z')

plt.show()
