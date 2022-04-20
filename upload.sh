#!/bin/sh

# avrdude: safemode: Fuses OK (E:FF, H:FF, L:6A)
# https://www.engbedded.com/fusecalc/

# Upload

HEXFILE="/tmp/Deviot/water_level_t13/.pio/build/attiny13a/firmware.hex"
avrdude -v -p t13 -c usbasp -P usb -B 32 -U flash:w:$HEXFILE:i
