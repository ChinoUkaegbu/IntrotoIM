class Triangle {
  int c;

  float x1;

  float y1;

  float x2;

  float y2;

  float x3;

  float y3;

  Triangle() {
    c = color(255, 255, 255);
    x1 = random(0, 1200);
    x2 = x1 + 10;
    x3 = x1 + 20;
    y1 = 25;
    y2 = 0;
    y3 = 25;
  }

  void fall() {
    y1 += 5;
    y2 += 5;
    y3 += 5;
  }

  void display() {
    fill(c);
    noStroke();
    triangle(x1, y1, x2, y2, x3, y3);
  }

  void disappear() {
    c = color(255, 255, 255, 0);
  }

  void increase_speed() {
    y1 += 5;
    y2 += 5;
    y3 += 5;
  }
  
  void reset(){
    c = color(255, 255, 255);
    x1 = random(0, 1200);
    x2 = x1 + 10;
    x3 = x1 + 20;
    y1 = 25;
    y2 = 0;
    y3 = 25;
  }
}
