# Arduino Assignment 2 - *Plant Parents*

## Chinonyerem Ukaegbu

**Description**

The task was to get information from at least one analog sensor and at least one digital sensor (switch), and use this information to control at least two LEDs, one in a digital fashion and the other in an analog fashion, in some creative way.

**Concept**

*Plant Parents* is a program that helps keep track of the status of your imaginary plant and ensure that enough nutrients are getting to the plant. The plant needs adequate sunlight and water to grow. To control the amount of sunlight that the plant receives, simply regulate how much light gets to the light sensor on the bread board. The green LED will dim or fade depending on how much sunlight the plant receives. To water your plant, simply push the button on the breadboard to deliver drops of water to the plant. The blue LED lights up each time water is delivered to the plant. Beware, if your plant has not received enough water for this cycle and sunlight levels drop too low, the red LED will flash and a message will be displayed.

**Process**

+ I first got to work on the breadboard
+ I got the parts of the circuit I would be using and placed the buttons and LEDs on the breadboard, making sure to connect the appropriate resistors.
+ Then I started with the wiring. I I wanted it to look a little organized because there were a lot of parts on the board, so I tried to align the components and use similar coloured wires.
+ Below is the schematic diagram:

![Schematic](images/Screenshot%20(333).jpeg)

+ To achieve the fading effect of the green LEd, I used the analogRead() and analogWrite() functions. However, I discovered that the analogRead() had a range from 0 to 1023 while the analogWrite() had a range from 0 to 255. Because I wanted the output from the analogRead() to be used to affect the  brightness of the LED, I created a variable, brightness, which was a quarter of the value gotten from analogRead() so that the values would correspond:

```js
int sensorValue = analogRead(LDR);

brightness = sensorValue / 4; // because of the range of analogRead and analogWrite
delay(30);
analogWrite(GREENLED, brightness);
```

+ Then I created two variables: one that would be incremented and displayed each time the plant was "watered" and the other that would record the last state of the first variable. :

```js
if (buttonState != lastButtonState) {
    // if the state has changed, increment the counter
    if (buttonState == HIGH) {
      buttonPushCounter++;
      Serial.print("Drops of water: ");
      Serial.println(buttonPushCounter);
      if (buttonPushCounter % amountWater != 0) {
        Serial.println(plantName + " needs more water");
      }
      else {
        Serial.println(plantName + " has gotten enough water and sunlight for this cycle :)");
      }

      Serial.println();
    }
    // Delay a little bit to avoid bouncing (making and breaking of contact)
    delay(50);
  }
  // save the current state as the last state, for next time through the loop
  lastButtonState = buttonState;
```

+ Then I wrote out the sections that would be printed in the serial monitor\
Here are the messages being displayed in the serial monitor while the game is running:

![SerialMonitor1](images/Screenshot%20(334).jpeg)

![SerialMonitor2](images/Screenshot%20(335).jpeg)

![SerialMonitor3](images/Screenshot%20(336).jpeg)

**Difficulties**

The major difficulty I faced was in printing some sentences in the serial monitor but I was able to resolve it

**Interesting Things I Found:**

+ **Bouncing:**\

"When you press a button down, it may not immediately make a complete connection. In fact, it may make contact on one side – then both – and then the other side – until it finally settles down. This making and breaking contact is called bouncing. It is not a manufacturing defect of the button – bouncing is implicit in most physical switches."


+ **string.trim():**\
Removes leading and trailing whitespace from strings

+ **string.toInt():**\

Typecasts strings to integers

+ **Entering values into the serial monitor:**\

I just assumed the serial monitor could only display values but you can actually enter values as well. I found this really interesting so I used it to save the name of the plant and the amount of drops of water per cycle the plant needed which I eventually used in the code as well

**Possible Improvements**

+ More functionality aside from just sunlight and water perhaps

**Photos of Circuit**

![1](images/Screenshot%20(328).jpeg)

![2](images/Screenshot%20(329).jpeg)

![3](images/Screenshot%20(330).jpeg)

![4](images/Screenshot%20(331).jpeg)

![5](images/Screenshot%20(332).jpeg)

**Conclusion**

This was a really cool project to do and I really enjoyed it. I particularly enjoyed how interactive it was from naming the plant yourself, to entering how much water the plant needed

**Cool Things the Circuit Does**

It saves the name of the plant and displays it in the messages displayed on the Serial Monitor
