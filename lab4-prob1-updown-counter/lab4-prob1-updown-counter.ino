const int NUM_OF_DIGITS = 10;
const int NUM_OF_SEGMENTS = 7;

// Feel free to change it to any positive number that can be contained in the 7 segment displays(s)
const int MAX_NUM =  15;

// Pins
// {a, b, c ,d ,e ,f, g} of 7 segments
const byte SEVEN_SEG_PINS[][NUM_OF_SEGMENTS] = {
  {A4, A3, 2, 3, 4, 5, 6},      // Ones place
  {7, 8, 9, 10, 11, 12, 13},  // Tens place
                              // Add more pins if using hundreds place
                              // Add more pins if using thousands place
                              // ...
};
const byte SWITCH = A5;

// digit mapping of 7 segment
const byte DIGIT_TO_7SEG[NUM_OF_DIGITS][NUM_OF_SEGMENTS] = {
  {HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, LOW},  // 0
  {LOW, HIGH, HIGH, LOW, LOW, LOW, LOW},      // 1
  {HIGH, HIGH, LOW, HIGH, HIGH, LOW, HIGH},   // 2
  {HIGH, HIGH, HIGH, HIGH, LOW, LOW, HIGH},   // 3
  {LOW, HIGH, HIGH, LOW, LOW, HIGH, HIGH},    // 4
  {HIGH, LOW, HIGH, HIGH, LOW, HIGH, HIGH},   // 5
  {HIGH, LOW, HIGH, HIGH, HIGH, HIGH, HIGH},  // 6
  {HIGH, HIGH, HIGH, LOW, LOW, LOW, LOW},     // 7
  {HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH}, // 8
  {HIGH, HIGH, HIGH, HIGH, LOW, HIGH, HIGH},  // 9
};
const byte ERROR_7SEG[NUM_OF_SEGMENTS] = {
  HIGH, LOW, LOW, HIGH, HIGH, HIGH, HIGH
};

// Set to true if 7 segment displays used are common cathode
const bool IS_CATHODE = false;
// Feel free to adjust delay duration
const int DELAY_DURATION = 325;

int maxDigits;
int numOf7Segments;
bool isSwitchOn;
int currentNum = 0;

void setup() {
  Serial.begin(9600);

  // Assign values for variables
  maxDigits = getMaximumDigits(MAX_NUM);
  numOf7Segments = sizeof(SEVEN_SEG_PINS) / sizeof(int);

  // Assign mode for all pins 
  for (int i = 0; i < NUM_OF_SEGMENTS; i++) {
    for (int j = 0; j <= numOf7Segments; j++) {
      pinMode(SEVEN_SEG_PINS[j][i], OUTPUT);
    }
  }
  pinMode(SWITCH, INPUT_PULLUP);
  
  // Start will no lit LED
  clearAllLEDs();
}

void loop() {
  // Catch error when maximum number is 0 or negatives
  if (MAX_NUM <= 0) {
    showErrorIn7Seg();
    return;
  }
  
  // Increment or decrement curent number based on switch state 
  isSwitchOn = digitalRead(SWITCH);
  currentNum = updatecurrentNum(currentNum, isSwitchOn);

  // Update 7 segment display to the current number
  intTo7Seg(currentNum);
  delay(DELAY_DURATION);
}

void clearAllLEDs() {
  /* Turn off all LEDS */
  for (int i = 0; i < NUM_OF_SEGMENTS; i++) {
    for (int j = 0; j < NUM_OF_SEGMENTS; j++) {
      digitalWrite(SEVEN_SEG_PINS[j][i], getPolarity(IS_CATHODE));
    }
  }
}


void intTo7Seg(int num) {
  /* Display number(s)  in the the 7 segment display(s) */
  bool isCurrOnesSegHigh, isCurrTensSegHigh;

  // Convert number to array of characters
  char intAsChars[maxDigits];
  itoa(num, intAsChars, 10);

  // Add '0's in front of the number
  float tmpIntAsFloat = max(num, 1);
  while (tmpIntAsFloat < pow(10, (maxDigits - 1))) {
    for (int i = maxDigits - 2; i >= 0; i--) {
      intAsChars[i + 1] = intAsChars[i];
    }
    intAsChars[0] = '0';
    tmpIntAsFloat *= 10;
    }


  // On/off each segment of each 7 segment display
  for (int i = 0; i < NUM_OF_SEGMENTS; i++) {
    for (int k = 0; k < maxDigits; k++) {
      
      byte isCurrSegHigh = DIGIT_TO_7SEG[intAsChars[k] - '0'][i];
      isCurrSegHigh = getPolarity(isCurrSegHigh);

      digitalWrite(SEVEN_SEG_PINS[maxDigits - k - 1][i], isCurrSegHigh);
    }
  }
}

int getMaximumDigits(int num) {
  /* Get the number of digits to contain a number */
  int numDigits = 0;
  while (num > 0) {
    num /= 10;
    numDigits++;
  }
  return numDigits;
}

void showErrorIn7Seg() {
  /* Update all 7 segment display to E short for error */
  for (int i = 0; i < numOf7Segments; i++) {
  for (int j = 0; j < NUM_OF_SEGMENTS; j++) {
    digitalWrite(SEVEN_SEG_PINS[i][j], !ERROR_7SEG[j]);
    }
  }
  delay(DELAY_DURATION);
  clearAllLEDs();
  delay(DELAY_DURATION);
}

int updatecurrentNum(int num, bool isSwitchOn) {
  /* Increment or decrement curent number based on switch state */
  if (isSwitchOn) {
    num++;
  }
  else {
    num--;
  }
  if (num < 0) {
    num = MAX_NUM;
  }
  if (num > MAX_NUM) {
    num = 0;
  }
  return num;
}

bool getPolarity(bool isHigh) {
  /* Invert polarity if using common anode 7 segment displays */
      if (!IS_CATHODE) {
        return !isHigh;
      }
      return isHigh;
} 