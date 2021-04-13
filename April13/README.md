# Arduino x Processing Assignment - *Piano Player*

## Chinonyerem Ukaegbu

**Description**

The task was to make a simple game that involved some kind of communication between Arduino and Processing

**Concept**

*Piano Player* as the name suggests, is a game that teaches the user how to play a song on the piano using both Processing and Arduino.
The Processing code displays an interface mimicking a section of a piano (as shown below) and a note is played if the user clicks on the piano key for that note 
The Arduino code tracks the progress of the user. The blue LED lights up if the user is on track but if a wrong note is played, the red LED is turned on and is only turned off if the appropriate note is played.
When the tune is completed, the green LED is turned on, indicating that the game has been won.

![Piano_Interface](images/Screenshot%20(405).jpg)

**Process**
+ I first got to work on the piano interface in Processing, to mimic a section of an actual piano
+ Then I defined each "piano key" with the appropriate not that would be played each time the mouse is clicked on that section e.g.


```js
if (mouseX > 0 && mouseX < 115) {
      note = "C";
    }

    if (mouseX > 115 && mouseX < 230) {
      note = "D";
    }
    
 ```
 
+ Then, when I was sure that each section of the piano had been accurately represented, I began writing the note variable to Arduino
<br>

+ In Arduino, I defined each note on the makeshift piano
+ Then, I used the note variable from Processing to define the frequency of the notes, e.g.


```js
if (note == "C") {
      tone(buzzer, C, 100);
    }
    if (note == "C#") {
      tone(buzzer, CS, 100);
    }
 ```
 
+ Then I got to work on the breadboard
+ I got the parts of the circuit I would be using and placed the buzzer and LEDs on the breadboard, making sure to connect the appropriate resistors.
+ Then I started with the wiring. It was much faster than usual, because I was finally getting used to wiring, so yay!
+ Below is the schematic diagram:

![Schematic](images/Screenshot%20(406).jpeg)

+ When the breadboard was in place, I got to work on implementing the code
+ After I was sure that each click on Processing would result in the appropriate note being played on Arduino, I wrote out the notes for the song that would be used (Mary Had a Little Lamb)
+ Then, when I figured out the arrangement, I created a variable, pos, that would be incremented only when the appropriate key is played, to move on to the next note
+ Then, I created the checkNotes() function that was responsible for incrementing pos and lighting up the blue LED, if the user was on track, the red LED if the user had missed that note and the green LED if the user had won


```js
if (pos == 0 || pos == 4 || pos == 5 || pos == 6 || pos == 10 || pos == 13 || pos == 17 || pos == 18 || pos == 19 || pos == 23) {
    if (note == "E") {
      digitalWrite(BLUELED, HIGH);
      digitalWrite(REDLED, LOW);
      pos++;
    }
    else {
      digitalWrite(BLUELED, LOW);
      digitalWrite(REDLED, HIGH);
    }
  }
  ```

+ Also, the user is unable to move to the next note unless the tune is followed


Below are the links to the videos:\
[Music Player](https://www.youtube.com/watch?v=_6ZXNNd_vmo)
[Music Maker](https://youtu.be/4T26GDzKUJk)
**Difficulties**

At first, the black keys were not being recognized in Processing. Then I realized I had to place the if statements at the end because they were laid over the other keys.
Also, the LEDs weren't lighting up at the right time. Then when I used else if, instead of if, they worked fine. I'm not exactly sure why but I think I have an idea why it works

**Interesting Things I Found:**

It seems kind of trivial, but placement of certain lines of code actually makes a huge difference.

**Possible Improvements**

+ Having different songs that could be played. I actually tried to, but I didn't know how I would indicate that I wanted to learn another song, because it wasn't recognizing the button I placed.

**Photos of Circuit**

![1](images/Screenshot%20(407).jpeg)

![2](images/Screenshot%20(408).jpeg)

![3](images/Screenshot%20(409).jpeg)

![4](images/Screenshot%20(410).jpeg)

![5](images/Screenshot%20(411).jpg)

**Conclusion**

This was a really nice project to do and it's really cool how Arduino and Processing can communicate.
