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


#include "Tpic6d595.h"

#define TPIC6D595_CS_PIN A4

Tpic6d595::Tpic6d595() {

  //Set the chip select pin to output and pull it high (disable)
  pinMode(TPIC6D595_CS_PIN, OUTPUT);
  digitalWrite(TPIC6D595_CS_PIN, HIGH);
  
  //Start SPI
  SPI.begin();
}
    
void Tpic6d595::refresh() {

    //Pull chip select low
    digitalWrite(TPIC6D595_CS_PIN, LOW);

    SPI.transfer(this->data);
 
    //Pull chip select high
    digitalWrite(TPIC6D595_CS_PIN, HIGH);
    
}

void Tpic6d595::flip(byte _address, boolean _state) {
    if (_state == true) { this->data |= (1<<_address); }
    else { this->data &= (0<<_address); }
}

