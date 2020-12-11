
#include <ISD1700.h>

// This code has been borrowed from http://www.arduino.cc/cgi-bin/yabb2/YaBB.pl?num=1234149784

ISD1700 chip(10); // Initialize chipcorder with
                  // SS at Arduino's digital pin 10
                  
//control the ISD1700 with an Arduino Programmingly
void setup()
{
  Serial.begin(9600);
  Serial.println("Sketch is starting up");
}

void loop()
{
  char c;

  if(Serial.available())
  {
    /* Power Up */
    chip.pu();
    c = Serial.read();
    switch(c)
    {
       case 'A':
         Serial.println(chip.rd_apc(), BIN);
         break;
       case 'Y': //if Y is pressed the recorder should play
         chip.play();
         break;
       case 'P':
         chip.stop();
         break;
       case 'E': //if E is pressed the recorder should erase
         chip.erase();
         break;
       case 'R': //if R is pressed the recorder should record
         chip.rec();
         break;
       case 'F': //if R is pressed the recorder should forward
         chip.fwd();
         break;
       case 'Z':
         chip.g_erase();
         break;
       case 'I':
         Serial.println(chip.devid(), BIN);
         break;
    }
    Serial.print("Status---> ");
    Serial.print(chip.CMD_ERR()? "CMD_ERR ": " ");
    Serial.print(chip.PU()? "PU ": " ");
    Serial.print(chip.RDY()? "RDY ": "Not_RDY");
    Serial.println();
    delay(1000);
  }
}

//this was a code initiative but unfortunately it still doesn't work. The circuits sends data to the Arduino but the serial monitor has issues showing data.
