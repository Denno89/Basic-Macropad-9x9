# Basic macropad w Arduino
I built this 9x9 macropad as a simple DIY project to keep my most-used Fusion 360 shortcuts easily accessible. The rotary encoder is programmed to control zoom in and out, while pressing it acts as an "undo" function (CTRL+Z).
No PCB was used in this build — all switches are wired directly to the Arduino, as shown in the photo below. The enclosure for the electronics was fully designed and 3D printed by me. You can find the STL files here: (insert link).
Above, you'll find two Arduino code files. These are two completely different sketches:
- One is a basic sketch that only uses standard alphanumeric keys — just like the one I used for my own macropad, since Fusion 360 doesn’t require many complex key combinations.

- The other is a more advanced version that supports both alphanumeric keys and more complex macros, offering greater flexibility if you need to use multiple-key shortcuts or custom sequences.

The only downside of this project is that if you want to change the assigned keys, you'll need to modify the Arduino code and upload the updated sketch to the board.

# Components:
- 1x Arduino Pro Micro
- 9x Cerry MX (no RGB light)
- 1x Encoder KY-040

# Schematic:
![Schema del Macropad](Schematic.jpg)

# Complete Wiring Summary:

### Cherry MX:
- Pin 8
- Pin 9
- Pin 10
- Pin 5
- Pin 6
- Pin 7
- Pin 2
- Pin 3
- Pin 4

### Encoder:
- GND
- VCC
- SW Pin 15
- DT Pin 14
- CLK Pin 16
