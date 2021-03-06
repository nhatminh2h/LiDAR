from mpl_toolkits.mplot3d import Axes3D
import matplotlib.pyplot as plt
from matplotlib import cm
import numpy as np
import pandas as pd
import os

fig = plt.figure()
ax = fig.add_subplot(111, projection = '3d')

print("Files in current directory: ")
for file in os.listdir(os.getcwd()):
    if file.endswith(".txt"):
        print(f'\t{file}')

print("\nEnter file to plot from: ")
readfile = input()

data = pd.read_csv(f'{readfile}.txt',sep=",", header=None)
data.columns = ['x','y','z']

#data = data[data.z != 0]
#can also add Normal distribution anomaly catcher

data = data[(abs(data.x) + abs(data.y) + abs(data.z)) > 9]
data = data[(abs(data.x) + abs(data.y) + abs(data.z)) < 800]

ax.scatter(data.x, data.y, data.z,s=2, marker='.', cmap='plasma', c =data.z)
ax.set_xlabel('x')
ax.set_ylabel('y')
ax.set_zlabel('z')

plt.show()
