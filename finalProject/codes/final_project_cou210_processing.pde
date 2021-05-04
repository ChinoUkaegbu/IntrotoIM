PImage start_menu;
PImage level_menu;
PImage song_menu;
PImage instructions_menu;
PImage credits_menu;
int stage = 0;
int option = 0;
int choose_mode;
int song;


/*This is the Final Project
 "Piano Player 2.0"
 Chinonyerem Ukaegbu
 30 April, 2021
 */

import processing.serial.*;
Serial port;

String note; // represents the notes played by the piano keys

void setup() {
  size(805, 440);

  start_menu = loadImage("C:/Users/Chinonyerem/Desktop/music_player_pro/start_menu.png");
  level_menu = loadImage("C:/Users/Chinonyerem/Desktop/music_player_pro/level_menu.png");
  song_menu = loadImage("C:/Users/Chinonyerem/Desktop/music_player_pro/song_menu.png");
  instructions_menu = loadImage("C:/Users/Chinonyerem/Desktop/music_player_pro/instructions_menu.png");
  credits_menu = loadImage("C:/Users/Chinonyerem/Desktop/music_player_pro/credits_menu.png");

  println("Available serial ports:");
  println(Serial.list());

  port = new Serial(this, Serial.list()[0], 9600);
} 

void draw() {


  if (stage == 0) {
    image(start_menu, 0, 0);
  }
  if (option == 2) {
    image(instructions_menu, 0, 0);
  }
  if (option == 3) {
    image(credits_menu, 0, 0);
  }
  if (stage == 1) {
    //background(0,0,0);
    image(level_menu, 0, 0);
  }

  if (choose_mode == 1) {
    image(song_menu, 0, 0);
  }

  if (song == 1 || song == 2 || song == 3 || song == 4 || song == 5 || song == 6) {
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
}

// plays each note when the respective piano key is clicked

void mousePressed() {
  if (song == 1 || song == 2 || song == 3 || song == 4 || song == 5 || song == 6) {

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
    port.write(song + note);
  }
}

void mouseClicked() {
  if (stage == 0) {
    if ( mouseX > 544 && mouseY > 75 && mouseX < 771 && mouseY < 145) { // start
      option = 1;
      stage = 1;
    }
    if ( mouseX > 544 && mouseY > 194 && mouseX < 771 && mouseY < 264) { // instructions
      option = 2;
    }
    if ( mouseX > 544 && mouseY > 315 && mouseX < 771 && mouseY < 385) { // credits
      option = 3;
    }
  } else if (option == 2) {
    stage = 0;
   
  } else if (option == 3) {
    stage = 0;
  }
  
  if (stage == 1) {
    if ( mouseX > 89 && mouseY > 43 && mouseX < 317 && mouseY < 113) {
      choose_mode = 1;
    }
    if ( mouseX > 474 && mouseY > 43 && mouseX < 702 && mouseY < 114) {
      choose_mode = 2;
    }
  }

  if (choose_mode == 1) {
    if ( mouseX > 45 && mouseY > 148 && mouseX < 348 && mouseY < 232) {
      song = 1;
    }
    if ( mouseX > 439 && mouseY > 148 && mouseX < 743 && mouseY < 232) {
      song = 2;
    }
    if ( mouseX > 240 && mouseY > 295 && mouseX < 546 && mouseY < 365) {
      song = 3;
    }
  }
  
  if (choose_mode == 2) {
    if ( mouseX > 45 && mouseY > 148 && mouseX < 348 && mouseY < 232) {
      song = 4;
    }
    if ( mouseX > 439 && mouseY > 148 && mouseX < 743 && mouseY < 232) {
      song = 5;
    }
    if ( mouseX > 240 && mouseY > 295 && mouseX < 546 && mouseY < 365) {
      song = 6;
    }
  }
}
