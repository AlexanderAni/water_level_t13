#!/bin/sh

# avrdude: safemode: Fuses OK (E:FF, H:FF, L:6A)
# https://www.engbedded.com/fusecalc/

# Read Fuse
avrdude -v -p t13 -c usbasp -P usb -B 32 -U lfuse:r:-:i # MicroCore Slow
