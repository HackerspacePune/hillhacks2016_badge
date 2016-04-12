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

The badge comes with [micronuleus](https://github.com/micronucleus/micronucleus) 
bootloader(and required fuses programmed. 
(Warning: incorrect fuses can make attiny chip no longer programmable with 
non HVSP ISP programmers like Atmel mkII, or arduino as ISP).

Hardware
========

Reset pin is enabled in this, this is so that you can use an ISP programmer without 
the bootloader, but for example digispark board comes with Reset pin disabled,
which means you can use it as an I/O pin.

Please see [Schematic.pdf](Schematic.pdf) for schematic. Pin PB0(D0 for arduino) is
connected to push button. PB1(D1) is connected to LED.

Writing programs
================

Another option(more flexible but probably more setup steps) is [https://github.com/sudar/Arduino-Makefile](https://github.com/sudar/Arduino-Makefile), 
you will need to set up `micronuclues` commandline to upload the generated hex file.

To use arduino IDE to program this, please follow [digispark wiki](https://digistump.com/wiki/digispark/tutorials/connecting)

TODO
====
Upload digispark bootloader(uses older micronucleus version) to repo for digispark/arduinoIDE compatibility.
