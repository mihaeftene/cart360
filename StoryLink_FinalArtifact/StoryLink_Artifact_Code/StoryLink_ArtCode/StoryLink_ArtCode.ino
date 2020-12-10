/*********************************************************
This is a library for the MPR121 12-channel Capacitive touch sensor

Designed specifically to work with the MPR121 Breakout in the Adafruit shop 
  ----> https://www.adafruit.com/products/

These sensors use I2C communicate, at least 2 pins are required 
to interface

Adafruit invests time and resources providing this open source code, 
please support Adafruit and open-source hardware by purchasing 
products from Adafruit!

Written by Limor Fried/Ladyada for Adafruit Industries.  
BSD license, all text above must be included in any redistribution
**********************************************************/

#include <Wire.h>
#include "Adafruit_MPR121.h"

#ifndef _BV
#define _BV(bit) (1 << (bit)) 
#endif

// You can have up to 4 on one i2c bus but one is enough for testing!
Adafruit_MPR121 cap = Adafruit_MPR121();

// Keeps track of the last pins touched
// so we know when buttons are 'released'
uint16_t lasttouched = 0;
uint16_t currtouched = 0;

// Tilt Sensor code for Robojax.com
#define TILT 2 // pin 2 for front-left sensor
#define LED 8 // pin 3 for front-right sensor
#define LEDPIN 3 //pin 3 of the Arduino

void setup() {
  Serial.begin(9600);

  while (!Serial) { // needed to keep leonardo/micro from starting too fast!
    delay(10);
  }
  
  Serial.println("Adafruit MPR121 Capacitive Touch sensor test"); 
  
  // Default address is 0x5A, if tied to 3.3V its 0x5B
  // If tied to SDA its 0x5C and if SCL then 0x5D
  if (!cap.begin(0x5A)) {
    Serial.println("MPR121 not found, check wiring?");
    while (1);
  }
  Serial.println("MPR121 found!");

  pinMode(LEDPIN, OUTPUT); 
 
  pinMode(TILT, INPUT);//define tilt input pin input pin
  pinMode(LED,OUTPUT);// define LED pint  pin as output
}

void loop() {
 tiltMode();
 storiesListener();
}


void storiesListener(){
  // Get the currently touched pads
  currtouched = cap.touched();
  
  for (uint8_t i=0; i<12; i++) {
    // it if *is* touched and *wasnt* touched before, alert!
    if ((currtouched & _BV(i)) && !(lasttouched & _BV(i)) ) {

      switch(i) {
        case 1:
        Serial.print(i); Serial.println(" touched");
        digitalWrite (LEDPIN, HIGH); //if the pin 0 is touched light up the LED
        delay(1000);
        break;
        case 4:
        Serial.print(i); Serial.println(" touched");
        break;
        case 6:
        Serial.print(i); Serial.println(" touched");
        break;
        case 10:
        Serial.print(i); Serial.println(" touched");
        break;
        }
      
      //Serial.print(i); Serial.println(" touched");
    }
    // if it *was* touched and now *isnt*, alert!
    if (!(currtouched & _BV(i)) && (lasttouched & _BV(i)) ) {
      switch(i) {
        case 1:
        Serial.print(i); Serial.println(" non touched");
        digitalWrite (LEDPIN, LOW);
        break;
        case 4:
        Serial.print(i); Serial.println("  non touched");
        break;
        case 6:
        Serial.print(i); Serial.println("  non touched");
        break;
        case 10:
        Serial.print(i); Serial.println("  non touched");
        break;
        }
      //Serial.print(i); Serial.println(" released");
    }
  }

  // reset our state
  lasttouched = currtouched;

  
}

void tiltMode()
{
 // Tilt Sensor code for Robojax.com
  int TILT_SENSED = digitalRead(TILT);// read TILT sensor

  // if tilt is sensed
  if( TILT_SENSED ==LOW)
  {
    digitalWrite(LED,LOW);// set the LED pin HIGH and buzzer will buzz
   // Serial.println("none");
    noTone(LED);
  }else{
    digitalWrite(LED,HIGH); // Set the LED pin LOW to turn it OFF or buzzer OFF
    tone(LED,450);
    //Serial.println("Tilt detected");
  }
  delay(200);  
  }
