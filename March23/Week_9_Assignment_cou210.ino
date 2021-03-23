/*This is the Production Assignment for Week 9
  Chinonyerem Ukaegbu
  23 March, 2021
*/

//Declare variables

//LEDs
const int GREENLED = 12;
const int REDLED = 11;
const int YELLOWLED1 = 10;
const int YELLOWLED2 = 9;
const int YELLOWLED3 = 8;

//BUTTONS
const int BLUESWITCH = A0;
const int YELLOWSWITCH = A1;
const int GREENSWITCH = A2;

//COUNTERS
int counter1 = 0;
int counter2 = 0;
int counter3 = 0;

//GAME COMPONENTS
int values[] = {5, 10, 20, 25, 30, 35};
int sum;
int answer;

boolean startgame = true;

void setup() {

  Serial.begin(9600);
  Serial.print("Welcome \n");
  delay(1000);
  Serial.print("This game involves a little memorization coupled with basic math\nat the start of the game, the yellow LEDs will flash a certain number\nof times corresponding to their assigned value. After all three yellow\nLEDs have flashed, the red LED lights up indicating the start of the game\nyour task is to press the buttons corresponding to each LED in order to\nget the value that will be displayed. There is a catch however! Each button\ncan only be pressed once as subsequent presses have no effect on the value.\nThe game can be solved with a maximum number of 3 unique button pushes\nand as little as one button push.\nGood luck!\n");
  delay(10000);

  randomSeed(analogRead(A4)); //to randomize the values more

  int i = random(0, 5);
  answer = values[i]; //this is the variable that holds the randomly generated value to be guessed

  Serial.print("The task is to obtain: ");
  Serial.println(answer);

  // initialize LEDs as output and buttons as input
  pinMode(GREENLED, OUTPUT);
  pinMode(REDLED, OUTPUT);
  pinMode(YELLOWLED1, OUTPUT);
  pinMode(YELLOWLED2, OUTPUT);
  pinMode(YELLOWLED3, OUTPUT);
  pinMode(BLUESWITCH, INPUT);
  pinMode(YELLOWSWITCH, INPUT);
  pinMode(GREENSWITCH, INPUT);

  //flashes the first yellow LED 5 times
  for (int n = 0; n < 5; n++) {
    digitalWrite(YELLOWLED1, HIGH);
    delay(250);
    digitalWrite(YELLOWLED1, LOW);
    delay(250);
  }

  //flashes the second yellow LED 10 times
  for (int n = 0; n < 10; n++) {
    digitalWrite(YELLOWLED2, HIGH);
    delay(250);
    digitalWrite(YELLOWLED2, LOW);
    delay(250);
  }

  //flashes the third yellow LED 20 times
  for (int n = 0; n < 20; n++) {
    digitalWrite(YELLOWLED3, HIGH);
    delay(250);
    digitalWrite(YELLOWLED3, LOW);
    delay(250);
  }

}


void loop() {

  while (startgame) {
    int switch1Position = digitalRead(BLUESWITCH);
    int switch2Position = digitalRead(YELLOWSWITCH);
    int switch3Position = digitalRead(GREENSWITCH);

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
    }
    else {
      digitalWrite(GREENLED, LOW);
      digitalWrite(REDLED, HIGH);

    }
  }
}
