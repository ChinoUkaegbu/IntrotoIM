/*
This is the Production Assignment for Week 1
 Chinonyerem Ukaegbu
 Self Portrait
 25 January, 2021
 */

size(1000, 800);

//Background

background(12, 20, 69);
fill(255, 255, 255);
stroke(192, 192, 192);
ellipse(100, 100, 5, 5);
ellipse(212, 312, 5, 5);
ellipse(900, 200, 5, 5);
ellipse(900, 670, 5, 5);
ellipse(500, 500, 5, 5);
ellipse(950, 1, 5, 5);
ellipse(550, 20, 5, 5);
ellipse(400, 700, 5, 5);
ellipse(10, 600, 5, 5);
ellipse(780, 780, 5, 5);
ellipse(600, 200, 5, 5);
ellipse(500, 300, 5, 5);
ellipse(700, 500, 5, 5);
ellipse(150, 500, 5, 5);
ellipse(350, 150, 5, 5);
ellipse(210, 700, 5, 5);

//Hair

fill(0);
stroke(0);
ellipse(550, 500, 300, 500);
ellipse(450, 500, 300, 500);

//Neck

fill(141, 85, 46);
stroke(121, 85, 46);
strokeWeight(3);
triangle(500, 600, 352, 685, 648, 685);

//Face

fill(141, 85, 46);
stroke(121, 85, 46);
strokeWeight(3);
ellipse(500, 450, 290, 320);

//Front hair

fill(0);
stroke(0);
arc(400, 298, 100, 100, radians(0), radians(120));
arc(550, 290, 200, 100, radians(30), radians(210));

//Eyes

fill(255, 255, 255);
stroke(0);
arc(575, 390, 75, 90, radians(0), radians(180), CHORD);
arc(425, 390, 75, 90, radians(0), radians(180), CHORD);
fill(0);
ellipse(575, 413, 48, 42);
ellipse(425, 413, 48, 42);
fill(255, 255, 255);
stroke(255, 255, 255);
strokeWeight(10);
point(430, 400);
point(580, 400);

//Nose

noFill();
stroke(0);
strokeWeight(5);
arc(485, 470, 60, 70, radians(300), radians(360));
arc(508, 470, 15, 10, radians(0), radians(180));

//Mouth

fill(255, 255, 255);
stroke(0);
arc(494, 520, 100, 120, radians(0), radians(165), CHORD);

//Earrings

fill(255, 215, 0);
stroke(255, 210, 0);
ellipse(360, 500, 15, 15);
ellipse(640, 500, 15, 15);

//Shirt

fill(128, 0, 32);
stroke(120, 0, 32);
strokeWeight(5);
rect(450, 630, 100, 170);
