# RC-Arduino-Car-with-3D-model-and-print
RC Arduino Car with 3D model and print. Blender to design the car's shell, 3D printing to build it, and C++ to program the Arduino to
control the car's movement. The car will be operated through a Bluetooth app on an Android device. The schematics below were made in Fritzing. 

![car_sketch_backup_bb](https://github.com/somewordshere/RC-Arduino-Car-with-3D-model-and-print/assets/16988740/77f5f2a5-8ead-4b77-83f6-5bd2f073f1fb)

Arduino Uno R3 operates on 5V and has inputs of 7–12V. The optimal performance of the
L293N driver's 5V power supply. Arduino Uno R3 operates on 5V and has inputs of 7–12V. The optimal performance of the
L293N driver's 5V power supply. The nominal voltage of the 18650 battery is 3.7V, and the battery pack voltage of two 18650
batteries connected in series is 7.4V. Elements of the car ‘sit’ on top of it, connected by wires and
zip ties. All the non-jumper wires have been soldered together. 
The Bluetooth app sends an ASCII character to the Arduino. Arduino Uno then processes the character and controls the RC car's motors.

![PXL_20230607_100034593](https://github.com/somewordshere/RC-Arduino-Car-with-3D-model-and-print/assets/16988740/e454008d-41e1-4859-bda4-10ded2c14b84)


# Required:
- Arduino Uno R3 Board
- DC Motor 4x
- Motor Driver L298N x2
- Bluetooth module HC-06
- Li-ion battery 18650 x2
- LEDs + resistors 220 Ohm x4
- Buzzer
- Copper wires
- Solder and Soldering Iron

# Tools:
- Arduino IDE
- Blender
- [Bluetooth RC Car](play.google.com/store/apps/details?id=braulio.calle.bluetoothRCcontroller) - the app sends an ASCII character to the Arduino. Arduino Uno then processes the character and controls the RC car's motors.

# Model:
Blender was used to create the model and it was sent to 3rd party to print:

![5](https://github.com/somewordshere/RC-Arduino-Car-with-3D-model-and-print/assets/16988740/2c959de0-e90c-4299-ad9c-e47b2d2fc18f)

Model in slicing program
![1](https://github.com/somewordshere/RC-Arduino-Car-with-3D-model-and-print/assets/16988740/799fba3d-1ba6-476c-98a4-f3f11f60c3e7)

The final model looks like this:

![IMG_20230915_094008](https://github.com/somewordshere/RC-Arduino-Car-with-3D-model-and-print/assets/16988740/655a3113-46b0-48e5-876c-acc755999994)
