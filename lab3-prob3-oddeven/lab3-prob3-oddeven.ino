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
  // Update for btn1 and btn3
  if (isBtnsPressed[0] || isBtnsPressed[2]) {
    clearLEDs();
  }
  // Update for btn2 and btn4
  if (isBtnsPressed[1] || isBtnsPressed[3]) {
    LEDTraverse(false);
  }
  // Update for no btn pressesd
  if (!isBtnsPressed[0] && !isBtnsPressed[1] && !isBtnsPressed[2] && !isBtnsPressed[3]) {
    LEDTraverse(true);
  }

}

void clearLEDs() {
  for (int i = 0; i < NUM_OF_LEDS; i++) {
    digitalWrite(LEDS[i], LOW);
  }
}

void lightLEDs() {
  for (int i = 0; i < NUM_OF_LEDS; i++) {
    digitalWrite(LEDS[i], HIGH);
  }
}

void LEDTraverse(bool on) {
  int delayInMS = 500;
  if (on) {
    clearLEDs();
  }
  else {
    lightLEDs();
  }

  for (int i = 0; i < NUM_OF_LEDS; i++) {
    digitalWrite(LEDS[i], !on);
    delay(delayInMS);
    digitalWrite(LEDS[i], on);
  }

  delay(delayInMS);
  if (on) {
    clearLEDs();
  }
  else {
    lightLEDs();
  }  

  for (int i = NUM_OF_LEDS - 1; i >= 0; i--) {
    digitalWrite(LEDS[i], !on);
    delay(delayInMS);
    digitalWrite(LEDS[i], on);
  }
  delay(delayInMS);
}
