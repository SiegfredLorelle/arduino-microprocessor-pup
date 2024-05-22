// Buttons
const int NUM_OF_BTNS = 4;
const byte BTNS[NUM_OF_BTNS] = {2, 3, 4, 5};
byte isBtnsPressed[NUM_OF_BTNS] = {LOW, LOW, LOW, LOW};

// LEDs
const int NUM_OF_LEDS = 8;
const int NUM_OF_LEDS_HALF = NUM_OF_LEDS / 2;
const byte LEDS[NUM_OF_LEDS] = {6, 7, 8, 9, 10, 11, 12, 13};

const int NUM_OF_LEDS_PER_SWITCH = 2;
// Map btns to LEDs (index represent btn; value represents LEDs for that index)
const byte SWITCHLEDMAP[NUM_OF_BTNS][NUM_OF_LEDS_PER_SWITCH] = {
  {LEDS[3], LEDS[4]}, // LEDs controlled by btn1
  {LEDS[2], LEDS[5]}, // LEDs controlled by btn2
  {LEDS[1], LEDS[6]}, // LEDs controlled by btn3
  {LEDS[0], LEDS[7]}, // LEDs controlled by btn4
};

void setup() {
  // Initialize serial communication
  Serial.begin(9600);

  // Configure modes for button and LED pins
  for (int i = 0; i < NUM_OF_BTNS; i++) {
    pinMode(BTNS[i], INPUT_PULLUP);
  }
  for (int i = 0; i < NUM_OF_LEDS; i++) {
    pinMode(LEDS[i], OUTPUT);
  }

  // Initialize all LEDs to off
  clearLEDs();
}

void loop() {
  // Check button presses
  int pressedCount = 0;
  for (int i = 0; i < NUM_OF_BTNS; i++) {
    isBtnsPressed[i] = !digitalRead(BTNS[i]);
    if (isBtnsPressed[i]) {
      pressedCount++;
    }
  }

  // If more than one button is pressed, turn off all LEDs
  if (pressedCount > 1) {
    clearLEDs();
  } else {
    // Light specific LEDs based on the individual button pressed
    for (int i = 0; i < NUM_OF_BTNS; i++) {
      if (isBtnsPressed[i]) {
        for (int j = 0; j < NUM_OF_LEDS_PER_SWITCH; j++) {
          digitalWrite(SWITCHLEDMAP[i][j], HIGH);
        }
      } else {
        for (int j = 0; j < NUM_OF_LEDS_PER_SWITCH; j++) {
          digitalWrite(SWITCHLEDMAP[i][j], LOW);
        }
      }
    }
  }
}

void clearLEDs() {
  for (int i = 0; i < NUM_OF_LEDS; i++) {
    digitalWrite(LEDS[i], LOW);
  }
}
