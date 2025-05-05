# Basic macropad w Arduino
This 3x3 macropad was built to keep my most used Fusion 360 shortcuts within easy reach. The rotary encoder is programmed to control zoom in and out, while its push-button function is set to "undo" (CTRL+Z).
This is not the final version. I'm already planning an upgraded model with more keys and multiple profiles but this prototype has already proven to be very useful in my personal projects.
No custom PCB was used in this build. All switches are wired directly to an Arduino, as shown in the photo below. The enclosure was fully designed and 3D printed by me, and it can be found here: (add link)

# Components:
- 1x Arduino Pro Micro
- 9x Cerry MX (no RGB light)
- 1x Encoder KY-040

# Schematic:
![Schema del Macropad](Schematic.jpg)

#Complete Wiring Summary:

# Cherry MX:
- Cherry MX Pin 8
- Cherry MX Pin 9
- Cherry MX Pin 10
- Cherry MX Pin 5
- Cherry MX Pin 6
- Cherry MX Pin 7
- Cherry MX Pin 2
- Cherry MX Pin 3
- Cherry MX Pin 4

# Encoder:
- GND
- VCC
- SW Pin 15
- DT Pin 14
- CLK Pin 16
