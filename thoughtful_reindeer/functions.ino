

void buttonTimer(){
    ledTimer.start();

    Serial.println("led button on");
    strip.setBrightness(255); 
    strip.fill(strip.Color(0,0,255)); //initial light

    strip.show();   // Send the updated pixel colors to the hardware.
}

void expiredLED(){
  
  if(ledTimer.expired()){ 

    Serial.println("ledtimer expired");
    strip.setBrightness(0); 

    strip.clear();//initial light
    strip.show();   // Send the updated pixel colors to the hardware.
    ledTimer.stop();
  }


}

void checker(){
static float brightnessLvl = 0;
  if( (checkButton() && upThresHit())|| (checkButton()&&lowThresHit()) ){
     strip.setBrightness(255); 
  strip.fill(strip.Color(255,0,0)); //initial light
    strip.show();   // Send the updated pixel colors to the hardware.
  ledTimer.start();
Serial.println("all hit");
  }else if(upThresHit()){

    brightnessLvl = map(currentGSR,gsrBaseline+(0.5*threshold),gsrBaseline+(2*threshold),0,100);
    strip.setBrightness(brightnessLvl);
    strip.fill(strip.Color(0,255,0));
    strip.show();       ledTimer.start();

Serial.println("uphit");
  }else if(lowThresHit()){

    brightnessLvl = map(currentGSR,gsrBaseline-(0.5*threshold),gsrBaseline-(2*threshold),0,100);
    strip.setBrightness(brightnessLvl);
    strip.fill(strip.Color(0,255,0)); //initial light
    strip.show();
        ledTimer.start();

  Serial.println("low hit");
  }else if(checkButton()){
    
    buttonTimer();
    Serial.println("button");
  }
  
}
