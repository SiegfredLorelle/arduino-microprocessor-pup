const int ledA = 7;
const int ledB = 6;
const int ledC = 5;
const int ledD = 4;
const int ledE = 3;


void setup() {
  Serial.begin(9600);
  pinMode(ledA, OUTPUT);
  pinMode(ledB, OUTPUT);
  pinMode(ledC, OUTPUT);
  pinMode(ledD, OUTPUT);
  pinMode(ledE, OUTPUT);
}

void loop() {
  // Prompt for an input
  Serial.print("Input: ");
  while (!Serial.available()) {
  }
  String input = Serial.readStringUntil('\n');
  input.trim();
  Serial.println(input);

  // Turn off all LEDs
  triggerAllLED(LOW);

  // Turn on LEDs based on input
  for (int i = 0; i < input.length(); i++) {
    if (input[i] == 'a') {
      digitalWrite(ledA, HIGH);
    }
    else if (input[i] == 'b') {
      digitalWrite(ledB, HIGH);
    }
    else if (input[i] == 'c') {
      digitalWrite(ledC, HIGH);
    }
    else if (input[i] == 'd') {
      digitalWrite(ledD, HIGH);
    }
    else if (input[i] == 'e') {
      digitalWrite(ledE, HIGH);
    }
    else {
      Serial.println("ERROR, INPUT INVALID!; only a-e allowed!");
      blinkAllLEDTwice();
      break;
    }

  }

}


void triggerAllLED(bool isHigh) {
  /* Turn on or off all LEDs */
  digitalWrite(ledA, isHigh);
  digitalWrite(ledB, isHigh);
  digitalWrite(ledC, isHigh);
  digitalWrite(ledD, isHigh);
  digitalWrite(ledE, isHigh);
}

void blinkAllLEDTwice() {
  /* Blink all LEDs twice in a 2 seconds total duration  */
  for (int i = 0; i < 2; i++) {
  triggerAllLED(HIGH);
  delay(500);
  triggerAllLED(LOW);
  delay(500);
  }
}