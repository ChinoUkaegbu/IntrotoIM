/*This is the Intro to IM Midterm
 Chinonyerem Ukaegbu
 Concept:
 Move the bowl along the screen to collect the falling objects
 The circles are worth 10 points and the squares are worth 20 points.
 Beware the triangles! Collecting them results in a deduction of 100 points.
 The game ends if your score falls below zero.
 Goodluck!
 4 March, 2021
 */

import processing.sound.*;
SoundFile backgroundMusic;
SoundFile winPoints1;
SoundFile winPoints2;
SoundFile losePoints;

int gameScreen = 0;

int score = 1;

PImage backgroundScreen;

PImage startScreen;

PImage endScreen;

PImage instructionsScreen;

Triangle[] triangles = new Triangle[5];

Square[] squares = new Square[5];

Circle[] circles = new Circle[4];

int alternator = 0;


void setup() {
  size(1200, 700);

  backgroundMusic = new SoundFile(this, "C:/Users/Chinonyerem/Desktop/midterm_game_legit/sugarcoat.mp3");
  backgroundMusic.loop();

  winPoints1 = new SoundFile(this, "C:/Users/Chinonyerem/Desktop/midterm_game_legit/winPoints1.wav");
  winPoints2 = new SoundFile(this, "C:/Users/Chinonyerem/Desktop/midterm_game_legit/winPoints2.wav");
  losePoints = new SoundFile(this, "C:/Users/Chinonyerem/Desktop/midterm_game_legit/losePoints.wav");

  int i;
  for (i = 0; i < triangles.length; i++)
    triangles[i] = new Triangle(); 
  for (i = 0; i < squares.length; i++)
    squares[i] = new Square(); 
  for (i = 0; i < circles.length; i++)
    circles[i] = new Circle(); 

  backgroundScreen = loadImage("C:/Users/Chinonyerem/Desktop/background.jpg");
  startScreen = loadImage("C:/Users/Chinonyerem/Desktop/midterm_game_legit/startscreen.png");
  endScreen = loadImage("C:/Users/Chinonyerem/Desktop/midterm_game_legit/endscreen.png");
  instructionsScreen = loadImage("C:/Users/Chinonyerem/Desktop/midterm_game_legit/instructionsscreen.png");

  restart();

  if (backgroundScreen == null)
    println("image failed to load");
}

void draw() {
  if (gameScreen == 0) {
    initScreen();
  } else if (gameScreen == 1) {
    instructScreen();
  } else if (gameScreen == 2) {
    gameScreen();
  } else if (gameScreen == 3) {
    gameOverScreen();
  }
}

void initScreen() { //this is the initial screen
  image(startScreen, 0, 0, 1200, 700);
}

void instructScreen() { //this is the screen with instructions
  image(instructionsScreen, 0, 0, 1200, 700);
}

void mouseClicked() {
  if (gameScreen == 0)
    instructGame();
  if (gameScreen == 1)
    startGame();
  if (gameScreen == 3)
    restart();
}


void startGame() {
  gameScreen = 2;
}
void instructGame() {
  gameScreen = 1;
}

void gameScreen() {
  image(backgroundScreen, 0, 0, 1200, 720);
  displayScore();
  int i;

  for (i = 0; i < triangles.length; i++) {
    checkScore();
    triangles[i].display();
    triangles[i].fall();
    if ((triangles[i]).x1 >= (mouseX - 30) && (triangles[i]).y1 == 510 && (triangles[i]).x3 <= (mouseX + 50) && (triangles[i]).y3 == 510) {
      triangles[i].disappear();
      losePoints.play();
      score -= 100;
    } else {
      if (triangles[i].y2 == height) {
        //triangles[i].reset();
        triangles[i].fillers();
      }
    }
  } 

  for (i = 0; i < circles.length; i++) {
    checkScore();
    circles[i].display();
    circles[i].fall();
    if ((circles[i]).x >= (mouseX - 30) && (circles[i]).y + (circles[i]).radius == 510 && (circles[i]).x <= (mouseX + 50)) {
      circles[i].disappear();
      winPoints1.play();
      score += 10;
    } else {
      if ((circles[i]).y - (circles[i]).radius == height) {
        alternator++;
        if (alternator%2 == 0) {
          circles[i].reset();
        } else {
          circles[i].fillers();
        }
      }
    }
  } 

  for (i = 0; i < squares.length; i++) {
    checkScore();
    squares[i].display();
    squares[i].fall();
    if ((squares[i]).x - (squares[i]).half_extent >= (mouseX - 30) && (squares[i]).y + (squares[i]).half_extent == 510 && (squares[i]).x + (squares[i]).half_extent <= (mouseX + 50)) {
      squares[i].disappear();
      winPoints2.play();
      score += 20;
    } else {
      if ((squares[i]).y - (squares[i].half_extent) == height) {
        squares[i].reset();
      }
    }
  } 

  bowl();
}

void gameOverScreen() {
  image(endScreen, 0, 0, 1200, 700);
}

void bowl() {
  fill(255, 255, 255);
  stroke(0);
  line(mouseX, 540, (mouseX + 20), 540);
  rect((mouseX - 1), 510, 21, 30);
  arc(mouseX, 510, 60, 60, radians(90), radians(180));
  arc((mouseX + 20), 510, 60, 60, radians(0), radians(90));
  line((mouseX - 30), 510, (mouseX + 50), 510);
}

void displayScore() {
  textAlign(3);
  text("Score: " + str(int(score) - 1), (height / 2), (width / 2));
}

void checkScore() {
  if (score<=0) {
    gameScreen = 3;
  }
}

void restart() {
  gameScreen = 0; 
  score = 1; 
  for (int i = 0; i < triangles.length; i++) {
    triangles[i].reset();
  }
  for (int i = 0; i < circles.length; i++) {
    circles[i].reset();
  }
  for (int i = 0; i < squares.length; i++) {
    squares[i].reset();
  }
}
