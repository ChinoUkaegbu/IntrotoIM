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

* Then came the fun (and tedious :weary: )part
