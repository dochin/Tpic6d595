/*
TPIC6D595 Power Shift Register driver

Purpose: Driver for TPIC6D595

Copyright 2015 Jason Campbell, dochin@campound.org
Licensed under GPL v2 or later

Notes:
This is an SPI driver for a TPIC6D595 shift register but
would probably work for almost any 595 shift register (not tested).

You can either use the "flip" function to flip a single bit or
directly write bits to the "data" byte.  Once your data and bits
are where you want them, use "refresh" to write it out over SPI.

Don't forget to define the chip select in Tpic6d595.cpp

*/


#include "SPI.h" //This driver depends on the SPI library for hardware fast SPI
#include "Tpic6d595.h"

Tpic6d595 myShiftRegister; //Initialize driver

void setup() {

}

void loop() {

    for (byte i=0; i < 8; i++) {

        //Set the bit to true (drain on/pull low)
        myShiftRegister.flip (i, true);
        myShiftRegister.refresh();
        
        delay(100);
        
        //Set the bit to false (drain off/don't pull low)
        myShiftRegister.flip (i, false);
        myShiftRegister.refresh();

//  Alternate method of directly modifying the "data" byte
//        myShiftRegister.data |= (1<<i);
//        myShiftRegister.refresh();
//        myShiftRegister.data=0;
//        delay(100);
    }

}