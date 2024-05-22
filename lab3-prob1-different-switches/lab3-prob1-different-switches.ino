// Buttons
const int NUM_OF_BTNS = 4;
const byte BTNS[NUM_OF_BTNS] = {2, 3, 4, 5};
byte isBtnsPressed[NUM_OF_BTNS] = {LOW, LOW, LOW, LOW};
// Used to handle edge cases
int lastBtnPressed = -1;

// LEDs
const int NUM_OF_LEDS = 8;
const byte LEDS[NUM_OF_LEDS] = {6, 7, 8, 9, 10, 11, 12, 13};

// Delays for majority of the LED patterns
const int durationInMS = 1000;
const int delayInMS = durationInMS / NUM_OF_LEDS;

void setup() {
  Serial.begin(9600);

  // Configure modes for button and LED pins
  for (int i = 0; i < NUM_OF_BTNS; i++) {
    pinMode(BTNS[i], INPUT_PULLUP);
  }
  for (int i = 0; i < NUM_OF_LEDS; i++) {
    pinMode(LEDS[i], OUTPUT);
  }
}

void loop() {
  // Check button presses
  int numOfBtnPressed = 0;
  for (int i = 0; i < NUM_OF_BTNS; i++) {
    isBtnsPressed[i] = !digitalRead(BTNS[i]);
    if (isBtnsPressed[i]) {
      numOfBtnPressed++;
      if (numOfBtnPressed > 1) {
        clearLEDs();
        return;
        };
    }
  }

  clearLEDs();

  // Light LED patterns based on button pressed
  if (isBtnsPressed[0]) {
    blinkTraverse();
    lastBtnPressed = 0;
  } else if (isBtnsPressed[1]) {
    blinkInward(false);
    lastBtnPressed = 1;
  } else if (isBtnsPressed[2]) {
    blinkInward(true);
    lastBtnPressed = 2;
  } else if (isBtnsPressed[3]) {
    blinkGapped();
    lastBtnPressed = 3;
  } else {
    handleEdgeCases();
  }
}

void clearLEDs() {
  for (int i = 0; i < NUM_OF_LEDS; i++) {
    digitalWrite(LEDS[i], LOW);
  }
}

void blinkTraverse() {
  /* Blink from left to right, then right to left */
  for (int i = 0; i < NUM_OF_LEDS; i++) {
    if (checkButtons()) return;
    digitalWrite(LEDS[i], HIGH);
    delay(delayInMS);
    digitalWrite(LEDS[i], LOW);
  }
  for (int i = NUM_OF_LEDS - 2; i >= 0; i--) {
    if (checkButtons()) return;
    digitalWrite(LEDS[i], HIGH);
    delay(delayInMS);
    digitalWrite(LEDS[i], LOW);
  }
}

void blinkInward(bool keep) {
  /* Blinks inward from left & right to center,
     then outward from center to left & right
     keep = keeps light for passed LEDs */
  int i = 0;
  int j = NUM_OF_LEDS - 1;
  while (i < j) {
    if (checkButtons()) return;
    if (keep) {
    digitalWrite(LEDS[i], HIGH);
    digitalWrite(LEDS[j], HIGH);
    delay(125);

    }
    if (!keep) {
      digitalWrite(LEDS[i], HIGH);
      digitalWrite(LEDS[j], HIGH);
      delay(125);
      clearLEDs();
    }
    i++;
    j--;
  }
  while (i > 0) {
    i--;
    j++;
    if (checkButtons()) return;
    if (keep) {
    digitalWrite(LEDS[i], LOW); // LAST EDIT
    digitalWrite(LEDS[j], LOW);
    delay(125);
    }
    if (!keep) {
      digitalWrite(LEDS[i], HIGH);
      digitalWrite(LEDS[j], HIGH);
      delay(125);
      clearLEDs();
    
    }
  }
}

void blinkGapped() {
  /* Blink two LEDs with a gap, from right to left */
  int delayInMS = 500;
  for (int i = NUM_OF_LEDS - 3, j = NUM_OF_LEDS - 1; i >= 0; i--, j--) {
    if (checkButtons()) return;
    digitalWrite(LEDS[i], HIGH);
    digitalWrite(LEDS[j], HIGH);
    delay(delayInMS);
    digitalWrite(LEDS[i], LOW);
    digitalWrite(LEDS[j], LOW);
  }
}

bool checkButtons() {
  // Check button presses
  for (int i = 0; i < NUM_OF_BTNS; i++) {
    if (isBtnsPressed[i] != !digitalRead(BTNS[i])) {
      return true;
    }
  }
  return false;
}

void handleEdgeCases() {
  /* Makes LED patterns for Switch1 and Switch 2 smoother */
  // if ((!isBtnsPressed[0] || isBtnsPressed[3]) && lastBtnPressed == 0) {
  //   digitalWrite(LEDS[0], HIGH);
  //   delay(delayInMS);
  //   digitalWrite(LEDS[0], LOW);
  //   lastBtnPressed = -1;
  // } 
  // else if ((!isBtnsPressed[1] || isBtnsPressed[0] || isBtnsPressed[3]) && lastBtnPressed == 1) {
  //   digitalWrite(LEDS[0], HIGH);
  //   digitalWrite(LEDS[NUM_OF_LEDS - 1], HIGH);
  //   delay(delayInMS);
  //   digitalWrite(LEDS[0], LOW);
  //   digitalWrite(LEDS[NUM_OF_LEDS - 1], LOW);
  //   lastBtnPressed = -1;
  // }
}