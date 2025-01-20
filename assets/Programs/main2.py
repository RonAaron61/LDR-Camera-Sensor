import numpy as np
from matplotlib import pyplot as plt
import serial
import keyboard

# Setup Serial Communication
try:
    ser = serial.Serial('COM9', 115200, timeout=1)  # Add a timeout to avoid indefinite blocking
    print("Connected!")
except:
    print("Please check the COM port")
    exit()

# Initialize Data and Plot
arr = np.zeros((8, 8))  # Initialize an 8x8 grid with zeros
plt.ion()  # Turn on interactive mode
fig, ax = plt.subplots()
heatmap = ax.matshow(arr, cmap='viridis')  # Create the heatmap
plt.colorbar(heatmap)

# Main Loop
try:
    while True:
        result = []  # Clear the result array for new data
        while True:
            ser_data = ser.readline().decode().strip()  # Read and decode serial data
            if ser_data == "Done":  # End of data signal
                break
            if ser_data.isdigit():  # Ensure data is numeric
                result.append(int(ser_data))
        
        if len(result) == 64:  # Only update the plot if the data is complete
            arr = np.reshape(result, (8, 8))  # Reshape to 8x8
            heatmap.set_data(arr)  # Update the heatmap data
            heatmap.set_clim(vmin=np.min(arr), vmax=np.max(arr))  # Update color limits
            plt.pause(0.01)  # Pause to keep the figure responsive
        
        if keyboard.is_pressed('q'):  # Exit the loop on 'q' press
            print("Loop terminated by user.")
            break

except Exception as e:
    print(f"Error: {e}")

finally:
    ser.close()  # Close the serial connection
    plt.ioff()  # Turn off interactive mode
    plt.show()  # Show the final figure
