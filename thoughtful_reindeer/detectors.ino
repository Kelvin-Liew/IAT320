

float gsrRead() {

  long sum = 0;
  for (int i = 0; i < 25; i++)  //Average the 10 measurements to remove the glitch
  {
    gsrValue = analogRead(GSR);
    sum += gsrValue;
   delay(5);
  }
  float average = sum / 25;
     Serial.println(average);
  return average;
}

bool checkButton() {
  if (digitalRead(buttonPin)==HIGH) {
    Serial.println("bpresed");
    return true;
  }
    else return false;
}

bool upThresHit(){
  if(currentGSR>gsrBaseline+threshold && currentGSR<gsrBaseline+(threshold*2)){
    return true;
  }
    else return false;
}
bool upUpthresHit(){
  if(currentGSR>gsrBaseline+(threshold*2)){
    return true;
  }
    else return false;
}

bool lowThresHit(){
  if(currentGSR<gsrBaseline-threshold){
    return true;
  }
    else return false;
}
