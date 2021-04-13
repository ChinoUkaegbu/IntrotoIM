/*This is the Production Assignment for Week 12
  "Piano Player"
  Chinonyerem Ukaegbu
  13 April, 2021
*/

import processing.serial.*;
Serial port;

String note; // represents the notes played by the piano keys

void setup() {
  size(805, 440);

  println("Available serial ports:");
  println(Serial.list());

  port = new Serial(this, Serial.list()[0], 9600);
} 

void draw() {
  background(255, 255, 255);
  
  // draws piano interface
  
  line(0, 0, width, 0);
  fill(0, 0, 0);
  rect(90, 0, 50, 250);
  rect(205, 0, 50, 250);
  rect(435, 0, 50, 250);
  rect(550, 0, 50, 250);
  rect(665, 0, 50, 250);
  strokeWeight(1.5);
  for (int i = 1; i < 7; i++) {
    line(i*115, 0, i*115, height);
  }
}

// plays each note when the respective piano key is clicked

void mousePressed() {

    if (mouseX > 0 && mouseX < 115) {
      note = "C";
    }

    if (mouseX > 115 && mouseX < 230) {
      note = "D";
    }

    if (mouseX > 230 && mouseX < 345) {
      note = "E";
    }

    if (mouseX > 345 && mouseX < 460) {
      note = "F";
    }

    if (mouseX > 460 && mouseX < 575) {
      note = "G";
    }

    if (mouseX > 575 && mouseX < 690) {
      note = "A";
    }

    if (mouseX > 690 && mouseX < 805) {
      note = "B";
    }

    if ( mouseX > 90 && mouseX < 140 && mouseY > 0 && mouseY < 250) {
      note = "C#";
    }

    if ( mouseX > 205 && mouseX < 255 && mouseY > 0 && mouseY < 250) {
      note = "D#";
    }

    if ( mouseX > 435 && mouseX < 485 && mouseY > 0 && mouseY < 250) {
      note = "F#";
    }

    if ( mouseX > 550 && mouseX < 600 && mouseY > 0 && mouseY < 250) {
      note = "G#";
    }

    if ( mouseX > 665 && mouseX < 715 && mouseY > 0 && mouseY < 250) {
      note = "A#";
    }
    port.write(note);
}
