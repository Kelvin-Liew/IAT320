const int buttonPin = 10;
const int ledPin = 9;

int buttonState = 0;

#include "pitches.h"

// notes in the melody:
int melody[] = {

  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {

  4, 8, 8, 4, 4, 4, 4, 4
};

void setup() {

  pinMode(buttonPin,INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);

  digitalWrite(ledPin, HIGH);
  delay(1000);
  digitalWrite(ledPin, LOW);
  delay(1000);
  Serial.begin(9600);

  // iterate over the notes of the melody:
//
//  for (int thisNote = 0; thisNote < 8; thisNote++) {
//
//    // to calculate the note duration, take one second divided by the note type.
//
//    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
//
//    int noteDuration = 1000 / noteDurations[thisNote];
//
//    tone(12, melody[thisNote], noteDuration);
//
//    // to distinguish the notes, set a minimum time between them.
//
//    // the note's duration + 30% seems to work well:
//
//    int pauseBetweenNotes = noteDuration * 1.30;
//
//    delay(pauseBetweenNotes);
//
//    // stop the tone playing:
//
//    noTone(12);
//
//  }
}

void loop() {

  bool buttonState = digitalRead(buttonPin);
  Serial.println(buttonState);

  digitalWrite(ledPin, !buttonState);

if (buttonState == 0){
  for (int thisNote = 0; thisNote < 8; thisNote++) {

    // to calculate the note duration, take one second divided by the note type.

    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.

    int noteDuration = 1000 / noteDurations[thisNote];

    tone(12, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.

    // the note's duration + 30% seems to work well:

    int pauseBetweenNotes = noteDuration * 1.30;

    delay(pauseBetweenNotes);

    // stop the tone playing:

    noTone(12);

  }
  // no need to repeat the melody.
}

}
