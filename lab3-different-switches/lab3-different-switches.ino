// Buttons
const int NUM_OF_BTNS = 4;
const byte BTNS[NUM_OF_BTNS] = {
  2, 3, 4, 5,
};
byte isBtnsPressed[NUM_OF_BTNS] = {
  LOW, LOW, LOW, LOW,
};
// Used to handle edge cases
int lastBtnPressed = -1;

// LEDs
const int NUM_OF_LEDS = 8;
const int NUM_OF_LEDS_HALF = NUM_OF_LEDS / 2;
const byte LEDS[NUM_OF_LEDS] = {
  6, 7, 8, 9, 10, 11, 12, 13,
};

// Delays for majority of the LED patterns
int durationInMS = 1000;
int delayInMS = durationInMS / NUM_OF_LEDS;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  // Cofigure modes for btn and LED pins
  for (int i = 0; i < NUM_OF_BTNS; i++) {
    pinMode(BTNS[i], INPUT_PULLUP);
  }
  for (int i = 0; i < NUM_OF_LEDS; i++) {
    pinMode(LEDS[i], OUTPUT);
  }
}


void loop() {
  // put your main code here, to run repeatedly:
  // Check button presses
  int i = 0;
  while (i < NUM_OF_BTNS) {
    isBtnsPressed[i] = digitalRead(BTNS[i]);
    i++;
  }

  handleEdgeCases();
  clearLEDs();

  // Light LED patterns based on button pressed
  if (isBtnsPressed[0]) {
    blinkTraverse();
    lastBtnPressed = 0;
    handleEdgeCases();
  }
  if (isBtnsPressed[1]) {
    blinkInward(false);
    lastBtnPressed = 1;
    handleEdgeCases();
  }
  if (isBtnsPressed[2]) {
    blinkInward(true);
    lastBtnPressed = 2;
  }
  if (isBtnsPressed[3]) {
    blinkGapped();
    lastBtnPressed = 3;
  }
}


void clearLEDs() {
  for (int i = 0; i < NUM_OF_LEDS; i++) {
    digitalWrite(LEDS[i], LOW);
  }
}


void blinkTraverse() {
  /* Blink from left to right, then right to left */
  clearLEDs();
  for (int i = 0; i < NUM_OF_LEDS; i++) {
    digitalWrite(LEDS[i], HIGH);
    delay(delayInMS);
    digitalWrite(LEDS[i], LOW);
  }

  for (int i = NUM_OF_LEDS - 2; i > 0; i--) {
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
  clearLEDs();

  while (i < j) {
    digitalWrite(LEDS[i], HIGH);
    digitalWrite(LEDS[j], HIGH);
    delay(delayInMS);

    if (!keep) {
      digitalWrite(LEDS[i], LOW);
      digitalWrite(LEDS[j], LOW);
    }
    i++;
    j--;
  }

  if (keep) {
    clearLEDs();
  } else {
    i--;
    j++;
  }

  i--;
  j++;
  while (i != 0 && j != NUM_OF_LEDS - 1) {
    digitalWrite(LEDS[i], HIGH);
    digitalWrite(LEDS[j], HIGH);
    delay(delayInMS);

    if (!keep) {
      digitalWrite(LEDS[i], LOW);
      digitalWrite(LEDS[j], LOW);
    }
    i--;
    j++;
  }

  if (keep) {
    digitalWrite(LEDS[i], HIGH);
    digitalWrite(LEDS[j], HIGH);
    delay(delayInMS);
  }
}


void blinkGapped() {
  /* Blink two LEDs with a gap, from right to left */
  int delayInMS = 500;
  int i = NUM_OF_LEDS - 3;
  int j = NUM_OF_LEDS - 1;
  clearLEDs();

  while (i > -1) {
    digitalWrite(LEDS[i], HIGH);
    digitalWrite(LEDS[j], HIGH);
    delay(delayInMS);
    digitalWrite(LEDS[i], LOW);
    digitalWrite(LEDS[j], LOW);
    i--;
    j--;
  }
}


void handleEdgeCases() {
  /* Makes LED patterns for Switch1 and Switch 2 smoother */
  if ((!isBtnsPressed[0] || isBtnsPressed[3]) && lastBtnPressed == 0) {
    digitalWrite(LEDS[0], HIGH);
    delay(delayInMS);
    digitalWrite(LEDS[0], LOW);
    lastBtnPressed = -1;
  } 
  else if ((!isBtnsPressed[1] || isBtnsPressed[0] || isBtnsPressed[3]) && lastBtnPressed == 1) {
    digitalWrite(LEDS[0], HIGH);
    digitalWrite(LEDS[NUM_OF_LEDS - 1], HIGH);
    delay(delayInMS);
    digitalWrite(LEDS[0], LOW);
    digitalWrite(LEDS[NUM_OF_LEDS - 1], LOW);
    lastBtnPressed = -1;
  }
}