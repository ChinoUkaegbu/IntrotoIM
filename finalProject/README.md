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

References to the songs: http://www.mintmusic.co.uk/2015/04/a-thousand-years-christina-perri.html \
http://www.mintmusic.co.uk/2021/02/willow-taylor-swift.html

+ This is the schematic:

![Schematic](images/board/Screenshot%20(406).jpeg)

+ Then I created another variable that would indicate what song was being played (and indirectly, what mode the player was using), and wrote that from Processing to Arduino:

```js

port.write(song + note);

```

**Difficulties:**

+ **Writing two variables to the serial port:**\
I was having difficulties writing both the variable responsible for playing the note when the mouse was clicked and the variable that would determine what song was being played. The song variable was an integer while the note variable was a string. I eventually figured out that I could use the Serial.parseInt() and the Serial.readString(); because it turns out the Serial monitor, once it has read a value, removes it from the buffer. This is the code snippet:

```js

  // check if data has been sent from the computer:
  if (Serial.available()) {
    // read the song that was chosen and the note that was played:
    song = Serial.parseInt();
    note = Serial.readString();
    note.trim();  // removes trailing characters

```

**Photos of Circuit:**

![1](images/board/Screenshot%20(407).jpeg)

![2](images/board/Screenshot%20(408).jpeg)

![3](images/board/Screenshot%20(409).jpeg)

![4](images/board/Screenshot%20(410).jpeg)

![5](images/board/Screenshot%20(411).jpg)


**GIFs**

![creditsDemo](images/credits_demo.gif)

![instructionsDemo](images/instructions_demo.gif)

**Pictures**

