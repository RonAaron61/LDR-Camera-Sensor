# LDR-Camera-Sensor
Making an 8x8 pixel camera sensor using LDR Photoresistor as the sensor

This project is inspired by some other projects
- [digiObscura by Sean Hodgins](https://hackaday.com/2019/12/30/image-sensor-from-discrete-parts-delivers-glorious-1-kilopixel-images/)
- [Photocell-camera by EmergentComplexity](https://github.com/EmergentComplexity/photocell-camera)

## Design

The components used are Photoresistor, 10kΩ resistor array, cd4051be de/multiplexer, and diode

<img src="assets/image/Schematic.png" width=700></img>

One cd4051be is used to inject 5V into each row of the photoresist, while the second cd4051be reads the voltage on each column that is connected to the voltage divider, so by using only 2 cd4051be it can be used to read each array

<img src="assets/image/PCB.png" width=700></img>

<img src="assets/image/ResultPCB.jpg" width=700></img>

## Results

Example result

<img src="assets/image/result_1.png" width=700></img>
