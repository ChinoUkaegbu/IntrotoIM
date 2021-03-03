
int gameScreen = 0;

int score = 1;

PImage photo;

Triangle[] triangles = new Triangle[1];

Square[] squares = new Square[1];

Circle[] circles = new Circle[4];

boolean random_checker;


void setup() {
  size(1200, 700);
  restart();
  int i;
  for (i = 0; i < triangles.length; i++)
    triangles[i] = new Triangle(); 
  for (i = 0; i < squares.length; i++)
    squares[i] = new Square(); 
  for (i = 0; i < circles.length; i++)
    circles[i] = new Circle(); 
  photo = loadImage("C:/Users/Chinonyerem/Desktop/background.jpg");
  if (photo == null)
    println("image failed to load");
}

void draw() {
  if (gameScreen == 0) {
    initScreen();
  } else if (gameScreen == 1) {
    gameScreen();
  } else if (gameScreen == 2) {
    gameOverScreen();
  } 
  println(mouseX, mouseY);
  println(score);
}

void initScreen() {
  background(0);
  textAlign(3);
  text("Click to start", (height / 2), (width / 2));
}

void mousePressed() {
  if (gameScreen == 0)
    startGame(); 
  if (gameScreen == 2)
    restart();
}

void startGame() {
  gameScreen = 1;
}

void gameScreen() {
  image(photo, 0, 0, 1200, 720);
  displayScore();
  int i;
  for (i = 0; i < triangles.length; i++) {
    triangles[i].display();
    triangles[i].fall();
    if ((triangles[i]).x1 >= (mouseX - 30) && (triangles[i]).y1 == 510 && (triangles[i]).x3 <= (mouseX + 50) && (triangles[i]).y3 == 510) {
      triangles[i].disappear();
      score -= 10;
      checkScore();
    }

    /*if (score <= 0) {
     triangles[i].reset();
     score = 1;
     gameScreen = 2;
     }*/
  } 
  for (i = 0; i < circles.length; i++) {
    circles[i].display();
    circles[i].fall();
    if ((circles[i]).x >= (mouseX - 30) && (circles[i]).y + (circles[i]).radius == 510 && (circles[i]).x <= (mouseX + 50)) {
      circles[i].disappear();
      score += 10;
      checkScore();
    }

    /*if (score <= 0) {
     circles[i].reset();
     score = 1;
     gameScreen = 2;
     }*/
  } 
  for (i = 0; i < squares.length; i++) {
    squares[i].display();
    squares[i].fall();
    if ((squares[i]).x - (squares[i]).half_extent >= (mouseX - 30) && (squares[i]).y + (squares[i]).half_extent == 510 && (squares[i]).x + (squares[i]).half_extent <= (mouseX + 50)) {
      squares[i].disappear();
      score -= 20;
      checkScore();
    }

    /*if (score <= 0) {
     squares[i].reset();
     score = 1;
     gameScreen = 2;
     }*/
  } 
  bowl();
}

void gameOverScreen() {
  background(0);
  textAlign(3);
  fill(255);
  textSize(30);
  text("Game Over", (height / 2), (width / 2 - 20));
  textSize(15);
  text("Click to Restart", (height / 2), (width / 2 + 10));
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
    restart();
  }
}

void restart() {
  gameScreen = 0;
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
