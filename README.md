PCB badge for hillhacks.in
==========================

Designed in kicad 4.0.2

Based on Adafruit trinket and Digispark designs. Can use either Adafruit's 
trinket/gemma bootloader, or micronucleus(which digispark uses).
Reverse protection for USB and battery with schottky diodes(and supply 
selection also), no voltage regulator, Zener diodes are to clip D+/D- 
voltage level to within USB spec. 1.5k on D- is part of USB spec's Low 
speed USB detection.

![Hillhacks badge](front1.png)

Hillhacks logo is from header on site.

Design uses a footprint(pcb_USB-A) from Inversepath's Usbarmory kicad design https://github.com/inversepath/usbarmory/

Firmware
========

Bootloader: Please follow [these instructions](https://learn.adafruit.com/introducing-trinket/repairing-bootloader) for
installing Adafruit Trinket bootloader onto your badge. This allows you to upload 'sletches' to the badge without an external programmer.

Arduino IDE: Set up arduino IDE to work with your badge from [here](https://learn.adafruit.com/introducing-trinket/setting-up-with-arduino-ide).

Hardware
========

Please see [Schematic.pdf](Schematic.pdf) for schematic. Pin PB0(D0 for arduino) is
connected to push button. PB1(D1) is connected to LED.

NOTE: The button footprint is rotated by 90 degrees by mistake, so you need to bend the button
leads so they can be fit the PCB roated. Also, the battery holder pins need to be bent out a bit
to fit the PCB.

Example code
============

Please see [/examples/HillhacksBadge.ino](/examples/HillhacksBadge.ino) for Mitch's example sketch.

