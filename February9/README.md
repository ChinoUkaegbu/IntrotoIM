# Game Assignment - *Boundaries*

## Chinonyerem Ukaegbu


**Description**

The task was to create an art work or game using Processing in order to practice using the functions and objects we had learnt last class

**Inspiration**

I'm a big fan of puzzles - sudoku, crosswords, jigsaws, and the game I created was heavily inspired by mazes except instead of dead ends signifying the end of the game, touching the walls signified the end.

**Process**

* I set the canvas to 1200x800 dimension in order to get a landscape orientation and set the background colour.

![Background](images/Screenshot%20(182).png)

* Then I got to work on the layout of the maze. I created an array for the x-coordinates of the rectangle and for the y-coordinates of the rectangle.

```js
 //Rectangles

  int[] x = { 
    25, 125, 225, 325, 425, 525, 625, 725, 825, 925, 1025, 1125 // x refers to the x-coordinates of the rectangles
  };
  int[] y = { 
    500, 200, 400, 600, 200, 600, 400, 600, 400, 300, 600, 450 // y refers to the y-coordinates of the rectangles
  };
  ```
  
* Then using the for loop, I played around with some values to create rectangles of varying height, varying position, but equal width until the maze looked a little complicated. I then filled in the rectangles with colour and outlined them so that the boundaries of the maze would stand out

```js
stroke(255, 255, 255);
  fill(245, 143, 146);

  // To read one array element each time through the for loop and draw the rectangles

  for (int i = 0; i < x.length; i++) {
    rect(x[i]+20, 800 - y[i], 50, y[i]);
    rect(x[i], 0, 50, 600-y[i]);
  }
  ```
* So the layout looked like this

![Rectangles](images/Screenshot%20(183).png)

* Then came the fun (and tedious :weary:) part: creating the ball and programming it to signal when it's perimeter had touched the walls of the maze
</p>
&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp I first had to create the ball and set the default colour
</p>

![Default_Ball_Colour](images/Screenshot%20(184).png)

</p>
&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp Then I had to use and if statement and set certain boundaries so that the program would run as I had intended.
</p>

```js
  //Ball 

  stroke(0);

  int r = 10; // r refers to the radius of the ball

  for (int i = 0; i < x.length; i++) {


    if ( // This if block ensures that if the ball comes in contact with any of the rectangles, there is a colour change

      //Rectangles on roof
      (mouseX>=25-r && mouseX<=75+r) && (mouseY>=0 && mouseY<=100+r)
      || (mouseX>=125-r && mouseX<=175+r) && (mouseY>=0 && mouseY<=400+r)
      || (mouseX>=225-r && mouseX<=275+r) && (mouseY>=0 && mouseY<=200+r)
      || (mouseX>=425-r && mouseX<=475+r) && (mouseY>=0 && mouseY<=400+r)
      || (mouseX>=625-r && mouseX<=675+r) && (mouseY>=0 && mouseY<=200+r)
      || (mouseX>=825-r && mouseX<=875+r) && (mouseY>=0 && mouseY<=200+r)
      || (mouseX>=925-r && mouseX<=975+r) && (mouseY>=0 && mouseY<=300+r)
      || (mouseX>=1125-r && mouseX<=1175+r) && (mouseY>=0 && mouseY<=150+r)

      //Rectangles on ground
      || (mouseX>=45-r && mouseX<=95+r) && (mouseY>=300-r && mouseY<=1200)
      || (mouseX>=145-r && mouseX<=195+r) && (mouseY>=600-r && mouseY<=1200)
      || (mouseX>=245-r && mouseX<=295+r) && (mouseY>=400-r && mouseY<=1200)
      || (mouseX>=345-r && mouseX<=395+r) && (mouseY>=200-r && mouseY<=1200)
      || (mouseX>=445-r && mouseX<=495+r) && (mouseY>=600-r && mouseY<=1200)
      || (mouseX>=545-r && mouseX<=595+r) && (mouseY>=200-r && mouseY<=1200)
      || (mouseX>=645-r && mouseX<=695+r) && (mouseY>=400-r && mouseY<=1200)
      || (mouseX>=745-r && mouseX<=795+r) && (mouseY>=200-r && mouseY<=1200)
      || (mouseX>=845-r && mouseX<=895+r) && (mouseY>=400-r && mouseY<=1200)
      || (mouseX>=945-r && mouseX<=995+r) && (mouseY>=500-r && mouseY<=1200)
      || (mouseX>=1045-r && mouseX<=1095+r) && (mouseY>=200-r && mouseY<=1200)
      || (mouseX>=1145-r && mouseX<=1195+r) && (mouseY>=350-r && mouseY<=1200)
      ) 
      //The subtraction or addition of the radius is to ensure that the colour changes when the circumference of the circle touches the rectangle rather than the centre of the circle
    {
      fill(183, 36, 27);
      ellipse(mouseX, mouseY, 20, 20);
    } else {
      fill(255, 215, 0);
      ellipse(mouseX, mouseY, 20, 20);
    }
  }
  ```

The if block is basically ensuring that if the circumference of the ball touches any part of the "walls" there is a colour change to indicate that the player has lost. If not, the colour of the ball remains the same
