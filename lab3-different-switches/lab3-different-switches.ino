const int NUM_OF_BTNS = 4;
const byte BTN1 = 2;
const byte BTN2 = 3;
const byte BTN3 = 4;
const byte BTN4 = 5;
const byte BTNS[NUM_OF_BTNS] = {
  BTN1, 
  BTN2,
  BTN3, 
  BTN4,
};

const int NUM_OF_LEDS = 8;
const int NUM_OF_LEDS_HALF = NUM_OF_LEDS / 2;
const byte LED1 = 6;
const byte LED2 = 7;
const byte LED3 = 8;
const byte LED4 = 9;
const byte LED5 = 10;
const byte LED6 = 11;
const byte LED7 = 12;
const byte LED8 = 13;
const byte LEDS[NUM_OF_LEDS] = {
  LED1, 
  LED2, 
  LED3, 
  LED4, 
  LED5, 
  LED6, 
  LED7, 
  LED8,
};

byte isBtnsPressed[NUM_OF_BTNS] = {
  LOW,
  LOW,
  LOW,
  LOW,
};

int lastBtnPressed = -1;

int durationInMS = 1000;
int delayInMS = durationInMS / NUM_OF_LEDS;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  for (int i = 0; i < NUM_OF_BTNS; i++) {
    pinMode(BTNS[i], INPUT_PULLUP);
  }

  for (int i = 0; i < NUM_OF_LEDS; i++) {
    pinMode(LEDS[i], OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  int i = 0;
  while (i < NUM_OF_BTNS) {
    isBtnsPressed[i] = digitalRead(BTNS[i]);
    Serial.print(digitalRead(BTNS[i]));
    Serial.print(digitalRead(BTN1));
    i++;
  }

  handleEdgeCases();
  clearLEDs();
  
  if (isBtnsPressed[0]) {
    blinkTraverse();
    lastBtnPressed = 0;
  }
  if (isBtnsPressed[1]) {
    blinkInward(false);
    lastBtnPressed = 1;

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


void handleEdgeCases() {
  bool is123Pressed = false;
  for (int i = 0; i < NUM_OF_BTNS - 1; i++) {
    is123Pressed |= isBtnsPressed[i];
  }
  if (!is123Pressed) {
    if (lastBtnPressed == 0) {
      digitalWrite(LEDS[0], HIGH);
      delay(delayInMS);
      digitalWrite(LEDS[0], LOW);
    }
    else if (lastBtnPressed == 1) {
      digitalWrite(LEDS[0], HIGH);
      digitalWrite(LEDS[NUM_OF_LEDS - 1], HIGH);
      delay(delayInMS);
      digitalWrite(LEDS[0], LOW);
      digitalWrite(LEDS[NUM_OF_LEDS - 1], LOW);
    }
    lastBtnPressed = -1;
  }
}

void clearLEDs() {
  for (int i = 0; i < NUM_OF_LEDS; i++) {
    digitalWrite(LEDS[i], LOW);
  }
}

void blinkTraverse() {
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
  }
  else {
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