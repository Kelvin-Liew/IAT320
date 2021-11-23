
static void helloTone(){

CircuitPlayground.playTone(NOTE_C4, 250);
CircuitPlayground.playTone(NOTE_G3, 125);
CircuitPlayground.playTone(NOTE_G3, 125);
CircuitPlayground.playTone(NOTE_A3, 250);
CircuitPlayground.playTone(NOTE_G3, 250);
CircuitPlayground.playTone(0, 250);
CircuitPlayground.playTone(NOTE_B3, 250);
CircuitPlayground.playTone(NOTE_C4, 250);
//delay(1000);

}

static void countDown(){

  //GET READY SOUND
  CircuitPlayground.playTone(NOTE_B3, 350);
//  delay(200);
  CircuitPlayground.playTone(NOTE_B3, 350);
//  delay(200);
  CircuitPlayground.playTone(NOTE_B3, 350);
//  delay(200);
  CircuitPlayground.playTone(NOTE_G5, 1000);
//  delay(3000);

}

static void combo_LRR() {
  //LEFT HAND 1-2
  //light on for left
  CircuitPlayground.playTone(NOTE_D4, 250);
  CircuitPlayground.playTone(NOTE_G3, 250);
  CircuitPlayground.playTone(NOTE_G3, 250);
//  delay(1000);
}

static void combo_RLL() {
  //RIGHT HAND 1-2
  CircuitPlayground.playTone(NOTE_G3, 250);
  CircuitPlayground.playTone(NOTE_D4, 250);
  CircuitPlayground.playTone(NOTE_D4, 250);
//  delay(1000);
}

static void combo_LLR() {
  //LEFT HAND 1-1-2
  //light on for left
  CircuitPlayground.playTone(NOTE_D4, 250);
  CircuitPlayground.playTone(NOTE_D4, 250);
  CircuitPlayground.playTone(NOTE_G3, 250);
//  delay(1000);
}

static void combo_RRL() {
  //RIGHT HAND 1-1-2
  CircuitPlayground.playTone(NOTE_G3, 250);
  CircuitPlayground.playTone(NOTE_G3, 250);
  CircuitPlayground.playTone(NOTE_D4, 250);
//  delay(1000);
}

static void combo_LRL() {
  //LEFT HAND 1-2-1
  //light on for left
  CircuitPlayground.playTone(NOTE_D4, 250);
  CircuitPlayground.playTone(NOTE_G3, 250);
  CircuitPlayground.playTone(NOTE_D4, 500);
//  delay(1000);
}

static void combo_RLR() {
  //RIGHT HAND 1-2-1
  CircuitPlayground.playTone(NOTE_G3, 250);
  CircuitPlayground.playTone(NOTE_D4, 250);
  CircuitPlayground.playTone(NOTE_G3, 500);
//  delay(1000);
}

static void correct() {
CircuitPlayground.playTone(NOTE_B3, 250);
CircuitPlayground.playTone(NOTE_C4, 250);
  CircuitPlayground.playTone(NOTE_B3, 250);
CircuitPlayground.playTone(NOTE_C4, 250);
//    delay(1000);
}

static void incorrect() {
CircuitPlayground.playTone(NOTE_G3, 125);
CircuitPlayground.playTone(NOTE_A3, 250);
CircuitPlayground.playTone(NOTE_G3, 125);
CircuitPlayground.playTone(NOTE_A3, 250);
//    delay(1000);
}
