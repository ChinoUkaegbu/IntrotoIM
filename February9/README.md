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
