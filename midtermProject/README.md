# Midterm Project - *Falling Objects*

## Chinonyerem Ukaegbu


**Description**

The task was to create a game using everything we've learnt so far.

**Inspiration**

The game I created is called Falling Objects and was inspired by a game I used to play when i was younger called *The Incident*

**How to Play the Game**
+ The game is designed for one player use
+ The player moves the bowl along the screen to collect the falling objects
+ The circles are worth 10 points and the squares are worth 20 points.
+ Watch out for the triangles! Collecting them results in a deduction of 100 points.
+The game ends if your score falls below zero.
+ Goodluck!

**Process**

Most of the beginning process can be found in the journal.md file: [MidtermJournal](https://github.com/ChinoUkaegbu/IntrotoIM/blob/main/midtermProject/journal.md)

+ After I had figured out the frame work for the game, I created three classes for the falling objects: a class for the squares, a class for the circles and a class for the triangles.

[SquareClass](https://github.com/ChinoUkaegbu/IntrotoIM/blob/main/midtermProject/SquareClass.pde)

[TriangleClass](https://github.com/ChinoUkaegbu/IntrotoIM/blob/main/midtermProject/TriangleClass.pde)

[CircleClass](https://github.com/ChinoUkaegbu/IntrotoIM/blob/main/midtermProject/CircleClass.pde)

(The classes have essentially the same functions in each of them, just modified with respect to each shape)

+ Then I got to work on creating the illusion that the objects were falling from the sky and being collected in the bowl moving along the screen. Take for instance the code for the triangles:

```js
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
```

**Difficulties**

The major difficulty I faced was with reading data from a CSV file with multiple columns. I wanted to access the data in a column and not in a row but I couldn't find any function that could do that which was why I had to seperate the fields into different CSV files in the first place. 

**Interesting Things I Found**

I found out that there was a circle() function. I thought it was only ellipse() that was available. I could've used ellipse() of course but circle() was much more convenient.
Also, even though I didn't use it in this program, I learnt how to create or read data from tables in Processing.

**Possible Improvements**

I wanted to use a sort of mouseOver function so that anytime the mouse hovered over a circle, the name of the song would be displayed but I did not know how to. I believe I'd have to rewrite the program and include a class so that that would be implementable and it would really pull the design together. 

**Conclusion**

At first, I thought the assignment was going to be really boring because it seemed like dealing with datasets was just tedious and uninteresting. However, manipulating these data sets and being able to create visuals is actually reallyu cool and the possibilites are really endless when it comes to data manipulation and visualization.
