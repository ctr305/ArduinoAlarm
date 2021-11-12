# ArduinoAlarm
Arduino countdown alarm for SimulIDE

The included program drives an Arduino Uno circuit with a ten second countdown that signifies when a buzzer alarm will activate. In order to deactivate it, the correct password must be inputed into a keyboard plugged into the board before the countdown finishes.

The components used in the SimulIDE project are the following:
- Arduino Uno board.
- 16x2 LCD Display Hd44780
- 4x3 Numeric Keypad
- SoundOut (Buzzer)
- 5V constant power source
- Red LED
- 470 Ohm resistor
- Relay

The program depends on the following external libraries:
- [LiquidCrystal](https://github.com/arduino-libraries/LiquidCrystal)
- [Keypad](https://github.com/Chris--A/Keypad)

The included SimulIDE file includes a prebuilt circuit meant for use with this sketch.

![Image of the ciruit](https://github.com/ctr305/ArduinoAlarm/blob/main/QW8rQnm3pL.png?raw=true)


**_WARNING_: This program has _NOT_ been tested with a phisical Arduino board and is only meant for use inside SimulIDE, use at your own risk.**
