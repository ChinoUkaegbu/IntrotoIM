# Arduino Assignment 3 - *Limitless*

## Chinonyerem Ukaegbu

**Description**

The task was to create a musical instrument.

**Concept**

*Limitless* is a program that allows you to create and listen to music. When the program is run, a menu pops up that guides you through setting up the program to either let you create or play music.

**Process**

+ I first got to work on the breadboard
+ I got the parts of the circuit I would be using and placed the buzzer, photoresistor and LEDs on the breadboard, making sure to connect the appropriate resistors.
+ Then I started with the wiring. I I wanted it to look a little organized because there were a lot of parts on the board, so I tried to align the components and use similar coloured wires.
+ Below is the schematic diagram:

![Schematic](images/Screenshot%20(366).jpeg)

+ Then I got to work on the section that would involve creating music
+ I wanted to create a rhythm that wouldn't be too complicated and I wanted the pitch to be controlled by the photoresistor so that the amount of light being received would either increase or reduce the pitch.
+ I stumbled upon this very helpful example and modified it to use in my code: https://www.reddit.com/r/arduino/comments/34fcyz/making_shitty_techno_with_an_arduino/cqu5zwq/
+ The segment of code is shown below:


```js
 float pitch = map(sensorValue, sensorLow, sensorHigh, 55, 900);
    if (pitch < 60.205 ) {
      pitch = 55; // A
    }
```
and so on for different intervals.

+ This results in an interesting rhythm whenever the light hitting the sensor changes.

+ Then I got to work on the portion that would play the songs
+ I first picked out the three songs that had already been writen using Arduino's note library (the link was: https://github.com/robsoncouto/arduino-songs)
+ Some parts of the song were unnecessary, so I got rid of them. It was really fun to count the notes as the song played but I got really tired of hearing the same tune over again.
+ I then set the tempo for each song accordingly and created separate functions to play each song so that it would be organized
+ Here is the portion that plays the christmas song for instance:

```js
void play_christmas() {
  tempo = 140;
  int notes = sizeof(christmas) / sizeof(christmas[0]) / 2;

  // this calculates the duration of a whole note in ms
  int wholenote = (60000 * 4) / tempo;

  int divider = 0, noteDuration = 0;
  for (int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2) {

    // calculates the duration of each note
    divider = christmas[thisNote + 1];
    if (divider > 0) {
      // regular note, just proceed
      noteDuration = (wholenote) / divider;
    } else if (divider < 0) {
      // dotted notes are represented with negative durations!!
      noteDuration = (wholenote) / abs(divider);
      noteDuration *= 1.5; // increases the duration in half for dotted notes
    }

    // we only play the note for 90% of the duration, leaving 10% as a pause
    tone(buzzer, christmas[thisNote], noteDuration * 0.9);

    // Wait for the specief duration before playing the next note.
    delay(noteDuration);

    // stop the waveform generation before the next note.
    noTone(buzzer);
  }
}
```

+ Then began working on the menu and essentially how the user would interact with the program
+ I made use of the serial monitor and here are some of the messages being displayed as the game is running:
Here are the messages being displayed in the serial monitor while the game is running:

![SerialMonitor1](images/Screenshot%20(334).jpeg)

![SerialMonitor2](images/Screenshot%20(335).jpeg)

![SerialMonitor3](images/Screenshot%20(336).jpeg)

Below is the link to the video:\
[Link to Video](https://youtu.be/oaEOwxzFMIA)

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
