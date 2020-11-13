//learned from https://www.youtube.com/watch?v=aXS2b1hIyGA
#include <math.h>

int sensorOneR = 0;  //sensor one is 0
int touching = false; //you are not touch it
int touchingCount = 0; //count the touch 

void setup() {
  Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop() {
  int sensorValue = analogRead(sensorOneR); //read sensor One
  String amount = "Start Touch";

  //if the sensor value is more than 90 consider it as being touched so add +1 to the counter
  if (sensorValue > 90) {
    touching = true;
    touchingCount++; //add one to the count
  } else {
    touching = false;
    touchingCount = 0; //if not touching, reset
  }

  //if touch AND touch count is smaller than 20, then show "tap
  if (touching && touchingCount < 20) {
    amount = "Tap"; 
  //if its only "touch", show hold
  } else if (touching) { 
    amount = "Hold";
  }

  //sensor value is smaller than 90, print "not touched"
  if (sensorValue < 90) {
   //if the value is smaller than 120 show lightly touched
   Serial.println("Not touched");
  } else if (sensorValue < 120) {
    Serial.println("Lightly " + amount);
  //if the value is smaller than 160 show strongly touched
  } else if (sensorValue < 160) {
    Serial.println("Strongly " + amount);
   //if the value is smaller than 190 show hardly touched
  } else if (sensorValue < 190) {
    Serial.println("Hardly " + amount);
  }

}
