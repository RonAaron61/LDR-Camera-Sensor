import numpy as np
from matplotlib import pyplot as plt
import matplotlib.pylab as pylab
from time import sleep
import serial 
import keyboard

try:
    ser = serial.Serial('COM9', 115200)
    ser.close()
    ser.open()
    print("Connected!")
except:
    print("Please check the com")

arr = np.random.rand(8,8)
result = [0]*64
plt.ion()
fig, ax = plt.subplots()
ax.matshow(arr)

#plt.ylim(-0.5, 8.5) #to show no blank spaces
#plt.xlim(-0.5, 8.5) #to show no blank spaces

#plt.xticks(np.arange(0, 8),np.arange(1, 9)) #trick the ticks
#plt.yticks(np.arange(0, 8),np.arange(1, 9))

while True:
    x = 0
    while True:
        ser_data = ser.readline()
        ser_data = ser_data.decode().rstrip()
        if ser_data == "Done":
            break
        else:
            result[x] = int(ser_data)
            x += 1

    arr = np.reshape(result, (-1, 8))
    ax.matshow(arr)
    fig.canvas.flush_events()  # Flush the drawing queue 
    fig.canvas.draw()  # Update the canvas
      
    plt.show() 

    if keyboard.is_pressed('q'):
        print("Loop terminated by user.")
        break
