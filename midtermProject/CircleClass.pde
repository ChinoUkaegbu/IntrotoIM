class Circle {
  int c;

  float x;

  float y;

  float diameter;

  float radius;

  int[] y_values = new int[] { -50, -100, -150, -200 };

  Circle() {
    c = color(255, 255, 255);
    x = random(0, 1200);
    diameter = 20;
    radius = diameter / 2;
    y = 0;
  }

  void fall() {
    y += 5;
  }

  void display() {
    fill(c);
    noStroke();
    circle(x, y, diameter);
  }

  void disappear() {
    c = color(255, 255, 255, 0);
  }
  
  void reset(){
    c = color(255, 255, 255);
    x = random(0, 1200);
    diameter = 20;
    radius = diameter / 2;
    y = 0;
  }
  
  void fillers(){
    c = color(255, 255, 255);
    x = random(0, 1200);
    diameter = 20;
    radius = diameter / 2;
    y = 250;
  }
  
}
