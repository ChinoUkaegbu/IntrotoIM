/*This is the Production Assignment for Week 12
  "Piano Player"
  Chinonyerem Ukaegbu
  13 April, 2021
*/

#include "pitches.h"

const int buzzer = 8;

// LEDs
const int BLUELED = 7;
const int REDLED = 6;
const int GREENLED = 5;

String note; // the note read from the piano in Processing
int pos = 0; // keeps track of what part of the song the player is on


void setup() {
  // initialize the serial communication:
  Serial.begin(9600);

  // initialize the buzzers and LEDs as output:
  pinMode(buzzer, OUTPUT);
  pinMode(BLUELED, OUTPUT);
  pinMode(REDLED, OUTPUT);
  pinMode(GREENLED, OUTPUT);

}

void loop() {

  // check if data has been sent from the computer:
  if (Serial.available()) {
    // read the note that was played:
    note = Serial.readString();
    note.trim();  // removes trailing characters

   // converts the notes clicked in Processing to music notes that are defined
   
    if (note == "C") {
      tone(buzzer, C, 100);
    }
    if (note == "C#") {
      tone(buzzer, CS, 100);
    }
    if (note == "D") {
      tone(buzzer, D, 100);
    }
    if (note == "D#") {
      tone(buzzer, DS, 100);
    }
    if (note == "E") {
      tone(buzzer, E, 100);
    }
    if (note == "F") {
      tone(buzzer, F, 100);
    }
    if (note == "F#") {
      tone(buzzer, FS, 100);
    }
    if (note == "G") {
      tone(buzzer, G, 100);
    }
    if (note == "G#") {
      tone(buzzer, GS, 100);
    }
    if (note == "A") {
      tone(buzzer, A, 100);
    }
    if (note == "A#") {
      tone(buzzer, AS, 100);
    }
    if (note == "B") {
      tone(buzzer, B, 100);
    }
    playNotes();
  }
}

void playNotes() {


  if (pos == 0 || pos == 4 || pos == 5 || pos == 6 || pos == 10 || pos == 13 || pos == 17 || pos == 18 || pos == 19 || pos == 23) {
    if (note == "E") {
      digitalWrite(BLUELED, HIGH);
      digitalWrite(REDLED, LOW);
      pos++;
    }
    else {
      digitalWrite(BLUELED, LOW);
      digitalWrite(REDLED, HIGH);
    }
  }

  else if (pos == 1 || pos == 3 || pos == 7 || pos == 8 || pos == 9 || pos == 14 || pos == 16 || pos == 21 || pos == 22 || pos == 24) {
    if (note == "D") {
      digitalWrite(BLUELED, HIGH);
      digitalWrite(REDLED, LOW);
      pos++;
    }
    else {
      digitalWrite(BLUELED, LOW);
      digitalWrite(REDLED, HIGH);
    }
  }

  else if (pos == 2 || pos == 15 || pos == 20) {
    if (note == "C") {
      digitalWrite(BLUELED, HIGH);
      digitalWrite(REDLED, LOW);
      pos++;
    }
    else {
      digitalWrite(BLUELED, LOW);
      digitalWrite(REDLED, HIGH);
    }
  }

  else if (pos == 11 || pos == 12) {
    if (note == "G") {
      digitalWrite(BLUELED, HIGH);
      digitalWrite(REDLED, LOW);
      pos++;
    }
    else {
      digitalWrite(BLUELED, LOW);
      digitalWrite(REDLED, HIGH);
    }
  }

  else if (pos == 25) {
    if (note == "C") {
      digitalWrite(BLUELED, HIGH);
      digitalWrite(REDLED, LOW);
      digitalWrite(GREENLED, HIGH);
    }
    else {
      digitalWrite(BLUELED, LOW);
      digitalWrite(REDLED, HIGH);
      digitalWrite(GREENLED, LOW);
    }
  }
}
