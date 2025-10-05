# Source Files
## main.c
Initializes ports and constructs HID report that will be serialized and sent to computer to be interpretted 
by programs.

## tusb_config.h
Project-Specific Configuration Header for tsub to what features and device classes to include. For 
this it enables only the HID class and device mode.

## usb_descriptors.c
tusb complient .c file for defining USB descriptors and callbacks needed for pico2 to appear as 
a USB HID controller when connected to any given computer. Establishes 5 different controls: throttle,
breaks, steering, and 10 buttons(up to 16 though).
