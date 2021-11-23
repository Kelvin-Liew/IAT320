#include <iostream>
#include <algorithm>
// using namespace std;
#ifdef __AVR__
#include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif
#include <Adafruit_CircuitPlayground.h>
#include <Wire.h>
#include <SPI.h>
#define NUM_PIXELS    5
#include "0pitches.h"

// PINS
const int trigPinR = A3;
const int echoPinR = A2;
const int trigPinL = A4;
const int echoPinL = A5;
const int motL = A6;
const int motR = A7;

// Arrays
int combo1[] = {1,2,2};
int combo2[] = {2,1,1}; 
int combo3[] = {1,1,2};
int combo4[] = {2,2,1}; 
int combo5[] = {1,2,1};
int combo6[] = {2,1,2};

int ranCombos[6] = {1,2,3,4,5,6}; 
int currCombo[3];
int performedCombo[3] ={0,0,0};

// INTS
int currentPunch = 0;
// BOOLEANS

boolean COMPLETED =false;

boolean punchL = false, punchR = false;
float distanceL = 0 , distanceR = 0;

void setup(){
  memcpy(currCombo, combo1, 3); 
  Serial.begin (9600);        //set up a serial connection with the computer
  CircuitPlayground.begin();

  // strip.begin();

  pinMode(trigPinL, OUTPUT);
  pinMode(echoPinL, INPUT);


  pinMode(trigPinR, OUTPUT);
  pinMode(echoPinR, INPUT);

  // pinMode(ledExt, OUTPUT);
  pinMode(motL, OUTPUT);

  pinMode(motR, OUTPUT);
  
//  dualMotorOn(); //run motor on both hands to make user aware of it
//  helloTone();
//  countDown();
  randomizer(); 

}

void loop() {

//    analogWrite(A7, 150);
//  analogWrite(motR, 150);
//  
//  motorOn(A1);
//  motorOn(A7);
//  Serial.print("LEFT:_");
//  Serial.print(distanceL);     //print the distance that was measured
//  Serial.println(" in");      //print units after the distance
//
//  Serial.print("RIGHT:_");
//  Serial.print(distanceR);     //print the distance that was measured
//  Serial.println(" in");      //print units after the distance
//
//
//  distanceL = getDistance(trigPinL,echoPinL); //left glove distance
//  distanceR = getDistance(trigPinR,echoPinR); //right glove distance
//
//  punchDetection(distanceL,motL,1,punchL); //left punch Detection
//  punchDetection(distanceR,motR,2,punchR); //right punch Detection

  //checking if combo has exceeded 3
  // then detects if combo performed is the same as prescribed
  //if yes, then
//  combFinDetection();

}
