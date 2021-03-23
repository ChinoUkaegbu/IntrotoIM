# Arduino Assignment - *Falling Objects*

## Chinonyerem Ukaegbu


**Description**

The task was to use at least three momentary switches (often called buttons), and at least three LEDs to create a puzzle that can be solved by pressing the buttons.

**Inspiration**

The game I created is called Falling Objects and was inspired by a game I used to play when i was younger called *The Incident*

**How to Play the Game**

This game involves a little memorization coupled with basic math\
at the start of the game, the yellow LEDs will flash a certain number\
of times corresponding to their assigned value. After all three yellow\
LEDs have flashed, the red LED lights up indicating the start of the game\
your task is to press the buttons corresponding to each LED in order to\
get the value that will be displayed. There is a catch however! Each button\
can only be pressed once as subsequent presses have no effect on the value.\
The game can be solved with a maximum number of 3 unique button pushes\
and as little as one button push.


**Process**

+ I first got to work on the breadboard
+ I got the parts of the circuit I would be using and placed the buttons and LEDs on the breadboard, making sure to connect the appropriate resistors.
+ Then I started with the wiring. I I wanted it to look a little organized because there were a lot of parts on the board, so I tried to align the components and use similar coloured wires.
+ Below is the schematic diagram:

![Schematic](images/Screenshot%20(298).jpg)


**Difficulties**

+ **Randomizing the values:**\
I was actually lowkey grateful for this difficulty because without it, I wouldn't have discovered the randomSeed() function. I noticed that anytime I printed the "random" value, it was the same number that popped up. It turns out that Arduino's random function isn't as random as I thought. I searched for help on Google and discovered that you could "initialize the pseudo-random number generator, causing it to start at an arbitrary point in its random sequence" using randomSeed() and not only did I fix the error, I also gained insight into how computers randomize values.

+ **Incrementing the counter:**\
I tried to increment the counter with each button push but the counter just stayed at some random position. I didn't fix this actually, I just worked my way around it outlined in this part of the code:

```js
if (switch1Position == HIGH) {
      counter1 = 5;
      digitalWrite(YELLOWLED1, HIGH);
    } else  {
      digitalWrite(YELLOWLED1, LOW);
    }

    if (switch2Position == HIGH) {
      counter2 = 10;
      digitalWrite(YELLOWLED2, HIGH);
    } else  {
      digitalWrite(YELLOWLED2, LOW);
    }

    if (switch3Position == HIGH) {
      counter3 = 20;
      digitalWrite(YELLOWLED3, HIGH);
    } else  {
      digitalWrite(YELLOWLED3, LOW);
    }

    sum = counter1 + counter2 + counter3;
    if (sum == answer) {
      digitalWrite(GREENLED, HIGH);
      digitalWrite(REDLED, LOW);
      Serial.print("Congratulations! You guessed right \n");
      Serial.print("Game Over! \n");
      startgame = false;
```
So that's basically why the buttons can only be pushed once to actually have an effect. Some may call it a design flaw, I see it as a way to make the game more challenging 😆

**Interesting Things I Found:**

+ randomSeed()
+ analogRead()
+ I didn't use this, but I also found this cool function that basically made the momentary switches act as toggles, so instead of the LEDs going off when the button isn't being pushed, it actually stays on or off, depending. This is it: 
```js
const int LED=13;
const int SW=7;
boolean state = true; //declare variable state as boolean
int val=0;

void setup()
{
  pinMode(LED,OUTPUT);
  pinMode(SW,INPUT);
  }
void loop()
{
  val=digitalRead(SW);
  delay(120); // Software debouncing using 120ms delay

if(val==HIGH)

{state=!state; // Compliment variable state using ! operator
  digitalWrite(LED,state);
}
}
```
Source: https://www.circuitstoday.com/simple-led-projects-using-arduino
**Possible Improvements**


**Conclusion**

This was a really cool project to do and I thoroughly enjoyed it. I especially loved the sound effects because they sounded so real as though they had been produced by actual interaction between objects and not just lines of code. I also find the fact that we can simulate certain events just by writing code really intriguing and this project further fuelled my amazement. 

**Cool Things the Game Does**

Okay so this isn't really cool but you might have noticed the alternator variable in the function. Basically all it does is help me switch between 0 and 1 using modulus
``` js
if ((circles[i]).y - (circles[i]).radius == height) {
        alternator++;
        if (alternator%2 == 0) {
          circles[i].reset();
        } else {
          circles[i].fillers();
        }
```
Okay it does sound a bit boring on its own but I used it to determine where the circles would appear from when they had been reset (either from the top or from the middle of the screen) which honestly leaves so much to wonder about the potential of modulus.
