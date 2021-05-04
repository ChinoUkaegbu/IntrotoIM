/*This is the Final Project
  "Piano Player 2.0"
  Chinonyerem Ukaegbu
  30 April, 2021
*/

#include "pitches.h"


const int buzzer = 8;

// LEDs
const int BLUELED = 7;
const int REDLED = 6;
const int GREENLED = 5;
const int BLUESWITCH = A1;

String note; // the note read from the piano in Processing
int song;
int pos = 0; // keeps track of what part of the song the player is on
int tracker = 0;


// LEARNER MODE FUNCTIONS

void checkLittleLamb() {


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

  else if (pos == 25) { // last note
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


void checkThousandYears() {


  if (pos == 0 || pos == 2 || pos == 3 || pos == 9 || pos == 11 || pos == 12 || pos == 14 || pos == 22 || pos == 30) {
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

  else if (pos == 1 || pos == 4 || pos == 6 || pos == 10 || pos == 13 || pos == 16) {
    if (note == "F") {
      digitalWrite(BLUELED, HIGH);
      digitalWrite(REDLED, LOW);
      pos++;
    }
    else {
      digitalWrite(BLUELED, LOW);
      digitalWrite(REDLED, HIGH);
    }
  }

  else if (pos == 5 || pos == 15 || pos == 23 || pos == 24) {
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

  else if (pos == 7 || pos == 17 || pos == 20 || pos == 26 || pos == 28) {
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

  else if (pos == 8 || pos == 18 || pos == 19 || pos == 25 || pos == 27) {
    if (note == "A#") {
      digitalWrite(BLUELED, HIGH);
      digitalWrite(REDLED, LOW);
      pos++;
    }
    else {
      digitalWrite(BLUELED, LOW);
      digitalWrite(REDLED, HIGH);
    }
  }

  else if (pos == 21 || pos == 29) {
    if (note == "D#") {
      digitalWrite(BLUELED, HIGH);
      digitalWrite(REDLED, LOW);
      pos++;
    }
    else {
      digitalWrite(BLUELED, LOW);
      digitalWrite(REDLED, HIGH);
    }
  }

  else if (pos == 31) { // last note
    if (note == "F") {
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

void checkWillow() {


  if (pos == 0 || pos == 9 || pos == 19 || pos == 28 || pos == 32) {
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

  else if (pos == 1 || pos == 7 || pos == 10 || pos == 18 || pos == 20 || pos == 26 || pos == 30 || pos == 33 || pos == 34) {
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

  else if (pos == 2 || pos == 4 || pos == 5 || pos == 6 || pos == 8 || pos == 11 || pos == 13 || pos == 14 || pos == 17 || pos == 21 || pos == 23 || pos == 24 || pos == 25 || pos == 27 || pos == 29 || pos == 31 || pos == 35) {
    if (note == "A") {
      digitalWrite(BLUELED, HIGH);
      digitalWrite(REDLED, LOW);
      pos++;
    }
    else {
      digitalWrite(BLUELED, LOW);
      digitalWrite(REDLED, HIGH);
    }
  }

  else if (pos == 3 || pos == 12 || pos == 16 || pos == 22) {
    if (note == "B") {
      digitalWrite(BLUELED, HIGH);
      digitalWrite(REDLED, LOW);
      pos++;
    }
    else {
      digitalWrite(BLUELED, LOW);
      digitalWrite(REDLED, HIGH);
    }
  }

  else if (pos == 15) {
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

  else if (pos == 36) { // last note
    if (note == "E") {
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


// EXPERT MODE FUNCTIONS

void checkLittleLambExpert() {


  if (pos == 0 || pos == 4 || pos == 5 || pos == 6 || pos == 10 || pos == 13 || pos == 17 || pos == 18 || pos == 19 || pos == 23) {
    if (note == "E") {
      pos++;
    }
    else {
      tracker++;
    }
  }

  else if (pos == 1 || pos == 3 || pos == 7 || pos == 8 || pos == 9 || pos == 14 || pos == 16 || pos == 21 || pos == 22 || pos == 24) {
    if (note == "D") {
      pos++;
    }
    else {
      tracker++;
    }
  }

  else if (pos == 2 || pos == 15 || pos == 20) {
    if (note == "C") {
      pos++;
    }
    else {
      tracker++;
    }
  }

  else if (pos == 11 || pos == 12) {
    if (note == "G") {
      pos++;
    }
    else {
      tracker++;;
    }
  }

  else if (pos == 25) { // last note
    if (tracker == 0) {
      digitalWrite(BLUELED, HIGH);
      digitalWrite(REDLED, LOW);
      digitalWrite(GREENLED, HIGH);
    }
    else {
      tracker++;
      digitalWrite(BLUELED, LOW);
      digitalWrite(REDLED, HIGH);
      digitalWrite(GREENLED, LOW);
    }
  }
}


void checkThousandYearsExpert() {


  if (pos == 0 || pos == 2 || pos == 3 || pos == 9 || pos == 11 || pos == 12 || pos == 14 || pos == 22 || pos == 30) {
    if (note == "D") {
      pos++;
    }
    else {
      tracker++;
    }
  }

  else if (pos == 1 || pos == 4 || pos == 6 || pos == 10 || pos == 13 || pos == 16) {
    if (note == "F") {
      pos++;
    }
    else {
      tracker++;
    }
  }

  else if (pos == 5 || pos == 15 || pos == 23 || pos == 24) {
    if (note == "G") {
      pos++;
    }
    else {
      tracker++;
    }
  }

  else if (pos == 7 || pos == 17 || pos == 20 || pos == 26 || pos == 28) {
    if (note == "C") {
      pos++;
    }
    else {
      tracker++;
    }
  }

  else if (pos == 8 || pos == 18 || pos == 19 || pos == 25 || pos == 27) {
    if (note == "A#") {
      pos++;
    }
    else {
      tracker++;
    }
  }

  else if (pos == 21 || pos == 29) {
    if (note == "D#") {
      pos++;
    }
    else {
      tracker++;
    }
  }

  else if (pos == 31) { // last note
    if (tracker == 0) {
      digitalWrite(BLUELED, HIGH);
      digitalWrite(REDLED, LOW);
      digitalWrite(GREENLED, HIGH);
    }
    else {
      tracker++;
      digitalWrite(BLUELED, LOW);
      digitalWrite(REDLED, HIGH);
      digitalWrite(GREENLED, LOW);
    }
  }
}

void checkWillowExpert() {


  if (pos == 0 || pos == 9 || pos == 19 || pos == 28 || pos == 32) {
    if (note == "E") {
      pos++;
    }
    else {
      tracker++;
    }
  }

  else if (pos == 1 || pos == 7 || pos == 10 || pos == 18 || pos == 20 || pos == 26 || pos == 30 || pos == 33 || pos == 34) {
    if (note == "G") {
      pos++;
    }
    else {
      tracker++;
    }
  }

  else if (pos == 2 || pos == 4 || pos == 5 || pos == 6 || pos == 8 || pos == 11 || pos == 13 || pos == 14 || pos == 17 || pos == 21 || pos == 23 || pos == 24 || pos == 25 || pos == 27 || pos == 29 || pos == 31 || pos == 35) {
    if (note == "A") {
      pos++;
    }
    else {
      tracker++;
    }
  }

  else if (pos == 3 || pos == 12 || pos == 16 || pos == 22) {
    if (note == "B") {
      pos++;
    }
    else {
      tracker++;
    }
  }

  else if (pos == 15) {
    if (note == "C") {
      pos++;
    }
    else {
      tracker++;
    }
  }

  else if (pos == 36) { // last note
    if (tracker == 0) {
      digitalWrite(BLUELED, HIGH);
      digitalWrite(REDLED, LOW);
      digitalWrite(GREENLED, HIGH);
    }
    else {
      tracker++;
      digitalWrite(BLUELED, LOW);
      digitalWrite(REDLED, HIGH);
      digitalWrite(GREENLED, LOW);
    }
  }
}

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
    song = Serial.parseInt();
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
    
    if (song == 1) {
      checkLittleLamb();
    }
    if (song == 2) {
      checkThousandYears();
    }
    if (song == 3) {
      checkWillow();
    }
    if (song == 4) {
      checkLittleLambExpert();
    }
    if (song == 5) {
      checkThousandYearsExpert();
    }
    if (song == 6) {
      checkWillowExpert();
    }
  }
}
