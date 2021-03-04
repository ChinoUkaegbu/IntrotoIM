class Square {
  int c;
  
  float x;
  
  float y;
  
  float extent;
  
  float half_extent;
  
  Square() {
    c = color(255, 255, 255);
    x = random(0, 1200);
    y = 0;
    extent = 20;
    half_extent = extent / 2;
  }
  
  void fall() {
    y += 5;
  }
  
  void display() {
    fill(c);
    noStroke();
    square(x, y, extent);
  }
  
  void disappear() {
    c = color(255, 255, 255, 0);
  }
  
  void reset(){
    c = color(255, 255, 255);
    x = random(0, 1200);
    y = 0;
    extent = 20;
    half_extent = extent / 2;
  }
  
    void fillers(){
    c = color(255, 255, 255);
    x = random(0, 1200);
    y = 400;
    extent = 20;
    half_extent = extent / 2;
  }
  
}
