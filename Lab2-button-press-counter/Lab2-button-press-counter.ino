const int btn = 4;
const int led = 13;

bool isPressed = false; 
bool isOffPrevState = false;
int pressCount = 0;
const int maxBtnPresses = 5;

void setup() {
  Serial.begin(9600);
  pinMode(btn, INPUT);
  pinMode(led, OUTPUT);
}

void loop() {
  // Limit button press (to 5)
  if (pressCount >= maxBtnPresses) {
    Serial.println("ALL DONE!");
    Serial.println("ALL DONE!");
    while (true) {}
  }

  // Get input from the switch
  isPressed = !digitalRead(btn);

  // Do nothing when the current state is the same as the prevState
  if (isOffPrevState == isPressed) {
    return;
  }

  // Lit the LED base on the input from the switch
  digitalWrite(led, isPressed);

  // Print statements and update prevState
  if (isPressed) {
    Serial.println("Button Pressed!");
    isOffPrevState = true;
  }
  else {
    Serial.println("Button Released!");
    isOffPrevState = false;
    pressCount++;
    Serial.print("Press Count: ");
    Serial.println(pressCount);
  }
}
