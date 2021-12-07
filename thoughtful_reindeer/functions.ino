

void buttonTimer(){
    ledTimer.start();

    Serial.println("led button on");
    strip.setBrightness(255); 
    strip.fill(strip.Color(0,0,255));

    strip.show();   // Send the updated pixel colors to the hardware.
}

void expiredLED(){
  
  if(ledTimer.expired()){ 

    Serial.println("ledtimer expired");
    // strip.setBrightness(0); 

    // strip.clear();//initial light
    // strip.show();   // Send the updated pixel colors to the hardware.
    // ledTimer.stop();
  }


}

void checker(){
static float brightnessLvl = 0;
//   if( (checkButton() && upThresHit())|| (checkButton()&&lowThresHit()) ){
//      strip.setBrightness(255); 
//   strip.fill(strip.Color(255,0,0));
//     strip.show();   // Send the updated pixel colors to the hardware.
//   ledTimer.start();
// Serial.println("all hit");
  // }else
  if(upThresHit()){

    brightnessLvl = map(currentGSR,gsrBaseline+(0.5*threshold),gsrBaseline+(2*threshold),0,100);
    strip.setBrightness(brightnessLvl);
    strip.fill(strip.Color(255,0,0));
    strip.show();       
    ledTimer.start();
    Serial.println("uphit");
    strip2.setBrightness(0);
    strip2.show();


  }else if(lowThresHit()){

    brightnessLvl = map(currentGSR,gsrBaseline-(0.25*threshold),gsrBaseline-(2.25*threshold),0,100);
    strip.setBrightness(brightnessLvl);
    strip.fill(strip.Color(255,0,0));
    strip.show();
    ledTimer.start();
    Serial.println("low hit");
    // strip2.setBrightness(0);
        strip.setBrightness(brightnessLvl);
    strip.fill(strip.Color(255,0,0));

    strip2.show();

  
  }else if(upUpthresHit()){

    brightnessLvl = map(currentGSR,gsrBaseline-(threshold*.25),gsrBaseline-(2.25*threshold),0,100);
    strip2.setBrightness(brightnessLvl);
    strip2.fill(strip2.Color(255,0,0));
    strip2.show();
    ledTimer.start();
    Serial.println("upup hit");
    strip.setBrightness(brightnessLvl);
    strip.fill(strip.Color(255,0,0));
    strip.show();


  } else{
    strip.setBrightness(00);
    strip.fill(strip.Color(0,0,0));
    strip.show();
    strip2.setBrightness(00);
    strip2.fill(strip2.Color(0,0,0));
    strip2.show();

  }
  // else if(checkButton()){
    
  //   buttonTimer();
  //   Serial.println("button");
  // }
  
}
