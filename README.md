## The LiDAR program consists of two components:

# Arduino
Mechanical controls & data collection:
* Controlling two servos to sweep a semi-hemisphere.
* Send polar coordinates based on servo angles and distance reading from the LiDAR.
      
# Python
Data collection & presetation:
* 3D graph plotter: Live plotting Python script. The data is polled from the LiDAR and plotted live.
Currently very unstable.
* writetofile: Receive data from the Arduino, convert from polar to Cartesian and write them in a .txt file(csv format).
* plotfromfile: Plot data(Cartesian) from a file on a 3D scatter graph.
