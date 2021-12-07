#include <Adafruit_NeoPixel.h>

#include <Timemark.h>

const int GSR = A0;
const int buttonPin = A5;
const int primaryLED = A6;
const int secondaryLED = A7;
// const int musclePin = A2;

Adafruit_NeoPixel strip(1, secondaryLED);
Adafruit_NeoPixel strip2(1, primaryLED);


int gsrValue = 0;
int currentGSR;
int gsrBaseline = 0;
float threshold = 50;

bool avgSet = false;

Timemark ledTimer(5000);
Timemark initialiser(10000);


void setup() {
  Serial.begin(9600);
  pinMode(buttonPin, INPUT);
  pinMode(primaryLED, OUTPUT);

  initialiser.start();
  // pinMode(secondaryLED, OUTPUT);
    strip.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)

    strip.clear();
    strip.show();            // Turn OFF all pixels ASAP

    strip2.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)

    strip2.clear();
    strip2.show();            // Turn OFF all pixels ASAP


}

void loop() {
  static float brightnessLvl= 0;

  if(!avgSet){

    setAverage();
  }else if (avgSet) {
    currentGSR = gsrRead();
    checker();
    // expiredLED();
  }
}

void setAverage() {
  static int framecount = 0;
  static float currValue = 0;
    strip.setBrightness(100);
    strip2.setBrightness(100);
    strip.fill(strip.Color(0,0,255)); //initial light
    strip2.fill(strip2.Color(0,0,255)); //initial light
    strip2.show();
    strip.show();

  if (!initialiser.expired()) {
    currValue += gsrRead();
    framecount++;
  } else {
    currValue /= framecount;
    gsrBaseline = currValue;
    avgSet = true;
    initialiser.stop();
  }

}
