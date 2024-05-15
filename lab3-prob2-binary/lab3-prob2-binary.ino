// Buttons
const int NUM_OF_BTNS = 4;
const byte BTNS[NUM_OF_BTNS] = {
  2, 3, 4, 5,
};
byte isBtnsPressed[NUM_OF_BTNS] = {
  LOW, LOW, LOW, LOW,
};

// LEDs
const int NUM_OF_LEDS = 8;
const int NUM_OF_LEDS_HALF = NUM_OF_LEDS / 2;
const byte LEDS[NUM_OF_LEDS] = {
  6, 7, 8, 9, 10, 11, 12, 13,
};

const int NUM_OF_LEDS_PER_SWITCH = 2;
// Map btns to LEDs (index represent btn; value represents LEDs for that index)
const byte SWITCHLEDMAP[NUM_OF_LEDS][NUM_OF_LEDS_PER_SWITCH] = {
  {LEDS[3], LEDS[4]}, // LEDS controlled by btn1
  {LEDS[2], LEDS[5]}, // LEDS controlled by btn2
  {LEDS[1], LEDS[6]}, // LEDS controlled by btn3
  {LEDS[0], LEDS[7]}, // LEDS controlled by btn4
};

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
    isBtnsPressed[i] = !digitalRead(BTNS[i]);
    i++;
  }


  // Light specific LEDs based on button pressed
  // Update btn1
  if (isBtnsPressed[0]) {
    for (int i = 0; i < NUM_OF_LEDS_PER_SWITCH; i++) {
      digitalWrite(SWITCHLEDMAP[0][i], HIGH);
    }
  }
  else {
    for (int i = 0; i < NUM_OF_LEDS_PER_SWITCH; i++) {
      digitalWrite(SWITCHLEDMAP[0][i], LOW);
    }
  }
  // Update btn2
  if (isBtnsPressed[1]) {
    for (int i = 0; i < NUM_OF_LEDS_PER_SWITCH; i++) {
      digitalWrite(SWITCHLEDMAP[1][i], HIGH);
    }
  }
  else {
    for (int i = 0; i < NUM_OF_LEDS_PER_SWITCH; i++) {
      digitalWrite(SWITCHLEDMAP[1][i], LOW);
    }
  }
  // Update btn3
  if (isBtnsPressed[2]) {
    for (int i = 0; i < NUM_OF_LEDS_PER_SWITCH; i++) {
      digitalWrite(SWITCHLEDMAP[2][i], HIGH);
    }
  }
  else {
    for (int i = 0; i < NUM_OF_LEDS_PER_SWITCH; i++) {
      digitalWrite(SWITCHLEDMAP[2][i], LOW);
    }
  // Update btn4
  }
  if (isBtnsPressed[3]) {
    for (int i = 0; i < NUM_OF_LEDS_PER_SWITCH; i++) {
      digitalWrite(SWITCHLEDMAP[3][i], HIGH);
    }
  }
  else {
    for (int i = 0; i < NUM_OF_LEDS_PER_SWITCH; i++) {
      digitalWrite(SWITCHLEDMAP[3][i], LOW);
    }
  }
}


