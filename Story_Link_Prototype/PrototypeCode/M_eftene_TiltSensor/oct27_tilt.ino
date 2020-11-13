
 /*
 * This is the Arduino code for  Tilt sensor that detects tilt and
 * Turns ON a buzzer or you can control a motor or servo or any other action,

 * Watch the video https://youtu.be/46Z-6MVxKnc

 *  * 
* Arduino Code for Tilt Sensor
* Written by Ahmad Nejrabi for Robojax.com
* on Jan 16, 2018 at 21:04 in Ajax, Ontario, Canada
 * Permission granted to share this code given that this
 * note is kept with the code.
 * Disclaimer: this code is "AS IS" and for educational purpose only.
 * 
 /*


What it does?
this module has 3 pins, VCC which is connected to 5v, 
GNG which is connected to GNG of Arduino.
DO (data out) which is connected to pin 2.
From 8 of Arduino, when tilt is detectec, you can stop a 
motor, move a servo or turn an LED on indicating tilt.

 */
  // Tilt Sensor code for Robojax.com
#define TILT 2 // pin 2 for front-left sensor
#define LED 8 // pin 3 for front-right sensor


void setup() {
  Serial.begin(9600);
  Serial.println("Robojax Tilt Test");
  pinMode(TILT, INPUT);//define Data input pin input pin
  pinMode(LED,OUTPUT);// define LED pint  pin as output
}

void loop() {
    // Tilt Sensor code for Robojax.com
  int TILT_SENSED = digitalRead(TILT);// read TILT sensor

  // if tilt is sensed
  if( TILT_SENSED ==LOW)
  {
    digitalWrite(LED,HIGH);// set the LED pin HIGH and buzzer will buzz
    Serial.println("Tilt detected");
  }else{
    digitalWrite(LED,LOW); // Set the LED pin LOW to turn it OFF or buzzer OFF
    Serial.println("Normal");
  }

  delay(200);
}
