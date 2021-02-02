/*
This is the Production Assignment for Week 2
 Chinonyerem Ukaegbu
 "Psychedelic"
 2 February, 2021
 */

//Canvas size

void setup() {
  size(800, 800);
}

void draw() {

  //Background

  if ((mouseX<400)) {
    background(255, 0, 0);
  } else {
    background(255, 215, 0);
  }
  int rhombus =5;
  noFill();
  stroke(0);
  line(0, 0, 800, 800);
  while (rhombus < width) {
    rect(0, 0, rhombus, rhombus);
    rhombus = rhombus + 5;
  }


  //Circles 

  if ((mouseX<400)) {
    fill(150, 75, 0);
  } else {
    fill(100);
  }
  ellipse(200, 600, 200, 200);
  ellipse(600, 200, 200, 200);
  int diam = 40;
  if ((mouseX<400)) {
    fill(0, 0, 255);
  } else {
    fill(183, 110, 121);
  }
  while (diam<200) {
    ellipse(200, 600, diam, diam);
    ellipse(600, 200, diam, diam);
    diam = diam + 40;
  }


  //Arcs

  if ((mouseX<400)) {
    fill(255, 255, 0);
  } else {
    fill(128, 0, 32);
  }
  arc(0, 0, 310, 310, 0, 180);
  arc(800, 800, 310, 310, 0, 180);


  //Triangles

  if ((mouseX<400)) {
    fill(0, 139, 0);
  } else {
    fill(0, 0, 139);
  }
  triangle(109, 109, 179, 179, 109, 179);
  triangle(365, 365, 430, 430, 365, 430);
  triangle(620, 620, 690, 690, 620, 690);
  triangle(109, 109, 179, 109, 179, 179);
  triangle(365, 365, 430, 365, 430, 430);
  triangle(620, 620, 690, 620, 690, 690);


  //Squares

  if ((mouseX<400)) {
    fill(0, 0, 0);
  } else {
    fill(255, 255, 255);
  }
  frameRate(5);
  int square1_xcoordinate = int(random(0, 800));
  int square1_ycoordinate = int(random(0, 800));
  int square2_xcoordinate = int(random(0, 800));
  int square2_ycoordinate = int(random(0, 800));
  rect(square1_xcoordinate, square1_ycoordinate, 40, 40);
  rect(square2_xcoordinate, square2_ycoordinate, 40, 40);
  fill(173, 248, 2);
  rect(square1_xcoordinate, square1_ycoordinate, 20, 20);
  rect(square1_xcoordinate+20, square1_ycoordinate+20, 20, 20);
  fill(173, 248, 2);
  rect(square2_xcoordinate, square2_ycoordinate, 20, 20);
  rect(square2_xcoordinate+20, square2_ycoordinate+20, 20, 20);


  //Points

  if ((mouseX<400)) {
    fill(255, 255, 255);
  } else {
    fill(0, 0, 0);
  }
  int point1X = int(random(0, 800));
  int point1Y = int(random(0, 800));
  int point2X = int(random(0, 800));
  int point2Y = int(random(0, 800));
  int point3X = int(random(0, 800));
  int point3Y = int(random(0, 800));
  ellipse(point1X, point1Y, 20, 20);
  ellipse(point2X, point2Y, 20, 20);
  ellipse(point3X, point3Y, 20, 20);
}
