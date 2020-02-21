The LiDAR program consists of two components:
  - Arduino. Basic controls:
      + Controlling two servos to sweep a semi-hemisphere.
  - Python. Data collection & presetation:
      + 3D graph plotter: Live plotting Python script. The data is polled from the LiDAR and plotted live.
      Currently very unstable.
      + writetofile: Receive data from the Arduino and write them in a .txt file(csv format).
      + plotfromfile: Plot data from a file on a 3D scatter graph.
