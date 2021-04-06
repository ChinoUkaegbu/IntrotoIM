
#include "pitches.h"
#include "songs.h"

const int BLUELED = 10;
const int YELLOWLED = 9;
const int REDLED = 8;
/*This is the Production Assignment for Week 11
  "Limitless"
  Chinonyerem Ukaegbu
  6 April, 2021
*/

const int LDR = A0;
const int buzzer = A1;
const int BUTTON = A2;
int tempo;


int sensorValue;
int sensorLow = 1023;
int sensorHigh = 0;

String choice;
String songchoice;
int integer_songchoice = 0;
int integer_choice = 0;

// MISCELLANEOUS
int buttonState;
int lastButtonState;
int buttonPushCounter;


void setup() {
  Serial.begin(9600);
  Serial.println("Welcome to Limitless")
  Serial.println("Would you like to:");
  Serial.println("1 - Create music or");
  Serial.println("2 - Listen to music");
  while (Serial.available() == 0) {}
  choice = Serial.readString();
  choice.trim();
  Serial.println(choice);
  Serial.println();

  integer_choice = choice.toInt(); //typecasts the choice from a string to an integer
  if (integer_choice == 2) {
    Serial.println("Great! Now pick a song");
    Serial.println("1 - We Wish You A Merry Chrtistmas");
    Serial.println("2 - Never Gonna Give You Up");
    Serial.println("3 - Pink Panther Theme Song");
    while (Serial.available() == 0) {}
    songchoice = Serial.readString();
    songchoice.trim();

    Serial.println();

    integer_songchoice = songchoice.toInt(); //typecasts the amount of water from a string to an integer
  }
  while (millis() < 5000) {
    sensorValue = analogRead(LDR);
    if (sensorValue > sensorHigh) {
      sensorHigh = sensorValue;
    }
    if (sensorValue < sensorLow) {
      sensorLow = sensorValue;
    }
  }

  pinMode(BLUELED, OUTPUT);
  pinMode(YELLOWLED, OUTPUT);
  pinMode(REDLED, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(LDR, INPUT);
  pinMode(BUTTON, INPUT);

}

void loop() {


  if (integer_choice == 1) {
    int sensorValue = analogRead(LDR);

    float pitch = map(sensorValue, sensorLow, sensorHigh, 55, 900);
    if (pitch < 60.205 ) {
      pitch = 55; // A
    }
    if (pitch >= 60.205 && pitch < 69.415) {
      pitch = 65.41; // C
    }
    if (pitch >= 69.415 && pitch < 77.915) {
      pitch = 73.42; // D
    }
    if (pitch >= 77.915 && pitch < 90.205) {
      pitch = 82.41; // E
    }
    if (pitch >= 90.205 && pitch < 104) {
      pitch = 98; // G
    }
    if (pitch >= 104 && pitch < 120.405) {
      pitch = 110; // A
    }
    if (pitch >= 120.405 && pitch < 138.82) {
      pitch = 130.81; // C
    }
    if (pitch >= 138.82 && pitch < 155.82) {
      pitch = 146.83; // D
    }
    if (pitch >= 155.82 && pitch < 180.405) {
      pitch = 164.81; // E
    }
    if (pitch >= 180.405 && pitch < 208) {
      pitch = 196; // G
    }
    if (pitch >= 208 && pitch < 240.815) {
      pitch = 220; // A
    }
    if (pitch >= 240.815 && pitch < 277.645) {
      pitch = 261.63; // C
    }
    if (pitch >= 277.645 && pitch < 311.645) {
      pitch = 293.66; // D
    }
    if (pitch >= 311.645 && pitch < 360.815) {
      pitch = 329.63; // E
    }
    if (pitch >= 360.815 && pitch < 416) {
      pitch = 392; // G
    }
    if (pitch >= 416 && pitch < 481.625) {
      pitch = 440; // A
    }
    if (pitch >= 481.625 && pitch < 555.29) {
      pitch = 523.25; // C
    }
    if (pitch >= 555.29 && pitch < 623.29) {
      pitch = 587.33; // D
    }
    if (pitch >= 623.29 && pitch < 721.62) {
      pitch = 659.25; // E
    }
    if (pitch >= 721.62 && pitch < 831.995) {
      pitch = 783.99; // G
    }
    if (pitch >= 831.995 && pitch <= 880) {
      pitch = 880; // A
    }
    if (pitch > 880) {
      pitch = 0;
    }
    tone(buzzer, pitch, 109);
    delay(110);
    tone(buzzer, 55, 24);
    delay(25);
    tone(buzzer, 880, 24);
    delay(25);
  }

  if (integer_choice == 2) {
    digitalWrite(BLUELED, HIGH);

    if (integer_songchoice == 1) {
      digitalWrite(BLUELED, HIGH);
      digitalWrite(YELLOWLED, LOW);
      digitalWrite(REDLED, LOW);

      play_christmas();
      noTone(buzzer);

    }
    if (integer_songchoice == 2) {
      digitalWrite(BLUELED, LOW);
      digitalWrite(YELLOWLED, HIGH);
      digitalWrite(REDLED, LOW);

      play_rickroll();
    }
    if (integer_songchoice == 3) {
      digitalWrite(BLUELED, LOW);
      digitalWrite(YELLOWLED, LOW);
      digitalWrite(REDLED, HIGH);

      play_pinkpanther();
    }
  }
}


void play_christmas() {
  tempo = 140;
  int notes = sizeof(christmas) / sizeof(christmas[0]) / 2;

  // this calculates the duration of a whole note in ms
  int wholenote = (60000 * 4) / tempo;

  int divider = 0, noteDuration = 0;
  for (int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2) {

    // calculates the duration of each note
    divider = christmas[thisNote + 1];
    if (divider > 0) {
      // regular note, just proceed
      noteDuration = (wholenote) / divider;
    } else if (divider < 0) {
      // dotted notes are represented with negative durations!!
      noteDuration = (wholenote) / abs(divider);
      noteDuration *= 1.5; // increases the duration in half for dotted notes
    }

    // we only play the note for 90% of the duration, leaving 10% as a pause
    tone(buzzer, christmas[thisNote], noteDuration * 0.9);

    // Wait for the specief duration before playing the next note.
    delay(noteDuration);

    // stop the waveform generation before the next note.
    noTone(buzzer);
  }
}

void play_rickroll() {
  tempo = 114;
  int notes = sizeof(rickroll) / sizeof(rickroll[0]) / 2;

  // this calculates the duration of a whole note in ms
  int wholenote = (60000 * 4) / tempo;

  int divider = 0, noteDuration = 0;
  for (int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2) {

    // calculates the duration of each note
    divider = rickroll[thisNote + 1];
    if (divider > 0) {
      // regular note, just proceed
      noteDuration = (wholenote) / divider;
    } else if (divider < 0) {
      // dotted notes are represented with negative durations!!
      noteDuration = (wholenote) / abs(divider);
      noteDuration *= 1.5; // increases the duration in half for dotted notes
    }

    // we only play the note for 90% of the duration, leaving 10% as a pause
    tone(buzzer, rickroll[thisNote], noteDuration * 0.9);

    // Wait for the specief duration before playing the next note.
    delay(noteDuration);

    // stop the waveform generation before the next note.
    noTone(buzzer);
  }
}

void play_pinkpanther() {
  tempo = 160;
  int notes = sizeof(pinkpanther) / sizeof(pinkpanther[0]) / 2;

  // this calculates the duration of a whole note in ms
  int wholenote = (60000 * 4) / tempo;

  int divider = 0, noteDuration = 0;
  for (int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2) {

    // calculates the duration of each note
    divider = pinkpanther[thisNote + 1];
    if (divider > 0) {
      // regular note, just proceed
      noteDuration = (wholenote) / divider;
    } else if (divider < 0) {
      // dotted notes are represented with negative durations!!
      noteDuration = (wholenote) / abs(divider);
      noteDuration *= 1.5; // increases the duration in half for dotted notes
    }

    // we only play the note for 90% of the duration, leaving 10% as a pause
    tone(buzzer, pinkpanther[thisNote], noteDuration * 0.9);

    // Wait for the specief duration before playing the next note.
    delay(noteDuration);

    // stop the waveform generation before the next note.
    noTone(buzzer);
  }
}
