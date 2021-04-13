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

The major difficulty I faced was in organizing how the songs would be played. It was a bit messy at first but I was able to arrange it and it actually helped me a lot while debugging

**Interesting Things I Found:**

+ If you chose the first option in the menu, which deals with the light sensor, you have to regulate the ambient light in the surroundings for the sound to come out nicely and this has to be done in the first 5 seconds of running the code.

```js

  while (millis() < 5000) {
    sensorValue = analogRead(LDR);
    if (sensorValue > sensorHigh) {
      sensorHigh = sensorValue;
    }
    if (sensorValue < sensorLow) {
      sensorLow = sensorValue;
    }
  }

```

**Possible Improvements**

+ Being able to switch from one mode to the other perhaps.

**Photos of Circuit**

![1](images/Screenshot%20(367).jpg)

![2](images/Screenshot%20(368).jpg)

![3](images/Screenshot%20(369).jpg)

![4](images/Screenshot%20(370).jpg)

![5](images/Screenshot%20(371).jpg)

**Conclusion**

This was a really cool project to do and I really enjoyed it. Working with more parts of the Arduino kit really blows my mind every time as it expands the possibilities for what we can create with the Arduino kit.
