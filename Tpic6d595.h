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

#ifndef Tpic6d595_h
  #define Tpic6d595_h
#endif

#include "Arduino.h"
#include "SPI.h"

#define TPIC6D595_CS_PIN A4

class Tpic6d595 {
  public:
    Tpic6d595();
 
    //function to write data to LEDs
    void refresh();
    
    //function to flip a bit
    void flip(byte _address, boolean _state);

    //bit data
    byte data;

};

