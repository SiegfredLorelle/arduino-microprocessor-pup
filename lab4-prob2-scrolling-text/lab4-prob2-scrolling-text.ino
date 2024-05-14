const int NUM_OF_DIGITS = 10;
const int NUM_OF_SEGMENTS = 7;

// Pins
// {a, b, c ,d ,e ,f, g} of 7 segments
const byte SEVEN_SEG_PINS[][NUM_OF_SEGMENTS] = {
  {A4, A3, 2, 3, 4, 5, 6},      // 7 segment display 1
  {7, 8, 9, 10, 11, 12, 13},  // 7 segment display 2
                              // Add more pins to display more characters
                              // ...
};
const byte LDR1 = A2;
const byte LDR2 = A1;

// '0' mapping of 7 segment
const byte ZERO_TO_7SEG[NUM_OF_SEGMENTS] = {
  LOW, LOW, LOW, LOW, LOW, LOW, HIGH  // 0
};
const byte HELLO_TO_7SEG[NUM_OF_DIGITS][NUM_OF_SEGMENTS] = {
  {LOW, HIGH, HIGH, LOW, HIGH, HIGH, LOW},  // H
  {HIGH, LOW, LOW, HIGH, HIGH, HIGH, HIGH},  // E
  {LOW, HIGH, HIGH, HIGH, LOW, LOW, LOW},  // L
  {LOW, HIGH, HIGH, HIGH, LOW, LOW, LOW},  // L
  {HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, LOW},  // O

};

// Set to true if 7 segment displays used are common cathode
const bool IS_CATHODE = false;
// Feel free to adjust delay duration
const int DELAY_DURATION = 325;

bool isSwitchOn;
int currentIndex;

void setup() {
  Serial.begin(9600);
  // Assign mode for all pins 
  int numOf7Segments = sizeof(SEVEN_SEG_PINS) / sizeof(int);
  for (int i = 0; i < NUM_OF_SEGMENTS; i++) {
    for (int j = 0; j <= numOf7Segments; j++) {
      pinMode(SEVEN_SEG_PINS[j][i], OUTPUT);
    }
  }
  pinMode(LDR1, INPUT_PULLUP);
  pinMode(LDR2, INPUT_PULLUP);
  
  // Start will no lit LED
  clearAllLEDs();
}

void loop() {
  // Get based on LDR1 and LDR2 states 
  bool isLDR1On = digitalRead(LDR1);
  bool isLDR2On = digitalRead(LDR2);


  // Serial.println(isLDR1On);
  if (isLDR1On == isLDR2On) {
    turn7SegToZeroes();
    Serial.println("00");
    Serial.println("00");
  }
  else if (isLDR1On) {
    scrollTextIn7Seg(true);
    Serial.println("SCROLLING LEFT");
  }
  else {
    scrollTextIn7Seg(false);
    Serial.println("SCROLLING RIGHT");
  }

  // Update 7 seg based on LDR1 and LDR2;
  delay(DELAY_DURATION);
}

void clearAllLEDs() {
  /* Turn off all LEDS */
  for (int i = 0; i < NUM_OF_SEGMENTS; i++) {
    for (int j = 0; j < NUM_OF_SEGMENTS; j++) {
      digitalWrite(SEVEN_SEG_PINS[i][j], getPolarity(IS_CATHODE));
    }
  }
}

void turn7SegToZeroes() {
  for (int i = 0; i < NUM_OF_SEGMENTS; i++) {
    for (int j = 0; j < NUM_OF_SEGMENTS; j++) {
      digitalWrite(SEVEN_SEG_PINS[i][j], ZERO_TO_7SEG[j]);
    }
  }
}

void scrollTextIn7Seg(bool isLeftToRight) {
  clearAllLEDs();
  // TODO
}



bool getPolarity(bool isHigh) {
  /* Invert polarity if using common anode 7 segment displays */
      if (!IS_CATHODE) {
        return !isHigh;
      }
      return isHigh;
} 