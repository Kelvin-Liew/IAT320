// //check if distance is less than limit of respective gloves. 
// //add value corresponding to glove - 1 for left, 2 for right
// // to performedcombo array using the currentpunch showing place in combo.
// // then incrrease current punch to next place, and turn on motor 
void punchDetection(float distance, int motorPin, int number, boolean punchExtended) {
    String s = String(distance, 3);// 
//  Serial.println("punch extneded for " + s + ":" + punchExtended);
  
  if(distance > 22 && punchExtended){
    Serial.println("distance > 22 and punch extended");
    punchExtended= false;
  }
    if (distance < 11 && !punchExtended){
  performedCombo[currentPunch] = number;
  currentPunch++;  
  motorOn(motorPin);
  punchExtended = true;

  }
}

//motor on for half a sec
void motorOn(int motorPin) {
//  digitalWrite(motorPin, HIGH);
//  delay(500);
//  digitalWrite(motorPin, LOW);
analogWrite(motorPin,50);
}

// return float value of trig/echo pin set
float getDistance( int trig, int echo)
{
  //variable to store the time it takes for a ping to bounce off an object
  float echoTime;                   
  //variable to store the distance calculated from the echo time
  float calculatedDistance;         

  //send out an ultrasonic pulse that's 10ms long
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  echoTime = pulseIn(echo, HIGH);      //use the pulsein command to see how long it takes for the
  //pulse to bounce back to the sensor

  calculatedDistance = echoTime / 148.0;  //calculate the distance of the object that reflected the pulse (half the bounce time multiplied by the speed of sound)
  return calculatedDistance;              //send back the distance that was calculated

}

//motor on for half a sec
void dualMotorOn() {
  digitalWrite(motL, HIGH);
  digitalWrite(motR, HIGH);
  delay(500);
  digitalWrite(motR, LOW);
  digitalWrite(motL, LOW);

}
