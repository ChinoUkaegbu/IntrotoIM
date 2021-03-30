/*This is the Production Assignment for Week 10
  "Plant Parent"
  Chinonyerem Ukaegbu
  30 March, 2021
*/

// LEDs
const int GREENLED = 11;
const int BLUELED = 10;
const int REDLED = 9;

// SENSORS
const int BUTTON = A4;
const int LDR = A5;

// PLANT PROPERTIES
int brightness;
String plantName = "";
String water = "";
int amountWater = 0;

// MISCELLANEOUS
int buttonState;
int lastButtonState;
int buttonPushCounter;


void setup() {

  pinMode(GREENLED, OUTPUT);
  pinMode(BLUELED, OUTPUT);
  pinMode(REDLED, OUTPUT);
  pinMode(BUTTON, INPUT);
  pinMode(LDR, INPUT);

  Serial.begin(9600);

  Serial.println("Welcome to Plant Parent. Here you can raise and take care of a plant.");
  Serial.println();

  // allows user to input the name of the plant

  Serial.println("But first, what would you like to name your plant?");
  while (Serial.available() == 0) {}
  plantName = Serial.readString();
  plantName.trim(); // removes any leading or trailing whitespace
  Serial.println("Your plant's name is " + plantName);
  Serial.println();

  // allows user to enter how much water they want to give the plant

  Serial.println("How many drops of water would you like to give " + plantName + " per cycle?");
  while (Serial.available() == 0) {}
  water = Serial.readString();
  water.trim();
  Serial.println(water + " drops of water per cycle");
  Serial.println();

  amountWater = water.toInt(); //typecasts the amount of water from a string to an integer
  
  Serial.println("Great! Now you can begin your journey as a plant parent. Your plant needs adequate");
  Serial.println("sunlight and water to grow. To control the amount of sunlight that " + plantName + " receives,");
  Serial.println("simply regulate how much light gets to the light sensor on the bread board. The greenLED will dim or");
  Serial.println("fade depending on how much sunlight " + plantName + " receives. To water your plant, simply push");
  Serial.println("the button on the breadboard to deliver drops of water to " + plantName + ". Beware, if your plant");
  Serial.println("has not received enough water for this cycle and sunlight levels drop too low, the red LED will flash");
  Serial.println("and a message will be displayed. Good luck and happy parenting!");
  Serial.println();
  Serial.println("*-------------------------------------------------------------------------------*");
  delay(10000);
  Serial.println();
  Serial.println("Push the blue button to begin");
  Serial.println();
}

void loop() {

  int sensorValue = analogRead(LDR);
  buttonState = digitalRead(BUTTON);

  if (buttonState == HIGH) {
    digitalWrite(BLUELED, HIGH);
  } else  {
    digitalWrite(BLUELED, LOW);
  }

  brightness = sensorValue / 4; // because of the range of analogRead and analogWrite
  delay(30);
  analogWrite(GREENLED, brightness);

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

  if (brightness < 128 && buttonPushCounter % amountWater != 0) {
    digitalWrite(REDLED, HIGH);
    delay(1000);
    digitalWrite(REDLED, LOW);
    delay(1000);
    Serial.println(plantName + " needs more sunlight");
    Serial.println();
  }

}
