# Final Project - *Piano Player 2.0*

## Chinonyerem Ukaegbu

**Description**

For my final project, I created a game which was a continutation of the Piano Player game from last week.
The current version of the game, Piano Player 2.0 has more functionality than the previous version ([Link to Piano Player](https://github.com/ChinoUkaegbu/IntrotoIM/tree/main/April13)):

+ There are two modes: Learning Mode and Expert Mode
+ Improved aesthetics and navigation

**Process**

+ Since I had gotten the piano keys working previously, I created the menus which would help the users navigate from page to page

Start Menu

![start_menu](images/start_menu.png)

Instructions Menu

![instructions_menu](images/instructions_menu.png)

Credits Menu

![credits_menu](images/credits_menu.png)

Level Menu

![level_menu](images/level_menu.png)

Song Menu

![song_menu](images/song_menu.png)

+ Then when I was done with the backgrounds, I got to work on the mouseClicked() function so that clicking on certain parts of the screen would allow the user progress through the game:

```js

void mouseClicked() {
  if (stage == 0) {
    if ( mouseX > 544 && mouseY > 75 && mouseX < 771 && mouseY < 145) { // start
      option = 1;
      stage = 1;
    }
    if ( mouseX > 544 && mouseY > 194 && mouseX < 771 && mouseY < 264) { // instructions
      option = 2;
    }
    if ( mouseX > 544 && mouseY > 315 && mouseX < 771 && mouseY < 385) { // credits
      option = 3;
    }

```

+ Then, I created the functions that would check if the correct notes were playing for the 2 additional songs I added (so now there are three songs: Mary Had a Little Lamb, A Thousand Years and Willow)

References to the sonngs: http://www.mintmusic.co.uk/2015/04/a-thousand-years-christina-perri.html
http://www.mintmusic.co.uk/2021/02/willow-taylor-swift.html

**24th April 2021**

The pauses between each key press have to be longer to avoid arduino mixing up the notes. I wonder why?

**GIFs**

![creditsDemo](images/credits_demo.gif)

![instructionsDemo](images/instructions_demo.gif)

**Pictures**

