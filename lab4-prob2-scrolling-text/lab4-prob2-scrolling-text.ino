const int NUM_OF_7SEGS = 2;
const int NUM_OF_SEGMENTS = 7;

// Pins {a, b, c ,d ,e ,f, g} of 7 segments
const byte SEVEN_SEG_PINS[][NUM_OF_SEGMENTS] = {
  {7, 8, 9, 10, 11, 12, 13},  // 7 segment display 1
  {A4, A3, 2, 3, 4, 5, 6},      // 7 segment display 2
                              // Add more pins to display more characters
                              // ...
};
const byte LDR1 = A2;
const byte LDR2 = A1;


// Character mapping to 7 segments
const int HELLO_LENGTH = 5;
const int BYE_LENGTH = 3;
const byte ZERO_TO_7SEG[NUM_OF_SEGMENTS] = {
  HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, LOW  // 0
};
const byte HELLO_TO_7SEG[][NUM_OF_SEGMENTS] = {
  {LOW, HIGH, HIGH, LOW, HIGH, HIGH, HIGH},   // H
  {HIGH, LOW, LOW, HIGH, HIGH, HIGH, HIGH},   // E
  {LOW, LOW, LOW, HIGH, HIGH, HIGH, LOW},     // L
  {LOW, LOW, LOW, HIGH, HIGH, HIGH, LOW},     // L
  {HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, LOW}   // O
};
const byte BYE_TO_7SEG[][NUM_OF_SEGMENTS] = {
  {LOW, LOW, HIGH, HIGH, HIGH, HIGH, HIGH},   // b
  {LOW, HIGH, HIGH, HIGH, LOW, HIGH, HIGH},   // y
  {HIGH, LOW, LOW, HIGH, HIGH, HIGH, HIGH},   // E
};

// Set to true if 7 segment displays used are common cathode
const bool IS_CATHODE = false;
// Feel free to adjust delay duration
const int DELAY_DURATION = 325;

bool isSwitchOn;
int currCharIndex = 0;
int prevState = 0;
int currState = 0;

void setup() {
  Serial.begin(9600);
  // Assign mode for all pins 
  for (int i = 0; i < NUM_OF_SEGMENTS; i++) {
    for (int j = 0; j <= NUM_OF_7SEGS; j++) {
      pinMode(SEVEN_SEG_PINS[j][i], OUTPUT);
    }
  }
  pinMode(LDR1, INPUT_PULLUP);
  pinMode(LDR2, INPUT_PULLUP);
  
  // Start will no lit LED
  int indicesToZero[] = {0, 1};
  int size = sizeof(indicesToZero) / sizeof(int);
  clear7Seg(indicesToZero, 2);
}

void loop() {
  // Get based on LDR1 and LDR2 states 
  bool isLDR1On = !digitalRead(LDR1);
  bool isLDR2On = !digitalRead(LDR2);

  if (isLDR1On == isLDR2On) {
    currState = 0;
    checkStateChange();
    turnAll7SegToZeroes();
  }
  else if (isLDR1On) {
    currState = 1;
    checkStateChange();
    scrollTextIn7Seg(HELLO_TO_7SEG, HELLO_LENGTH, true);
  }
  else {
    currState = 2;
    checkStateChange();
    scrollTextIn7Seg(BYE_TO_7SEG, BYE_LENGTH, false);
  }


  // Update 7 seg based on LDR1 and LDR2;
  delay(DELAY_DURATION);
}


void clear7Seg(int SevenSegIndices[], int size) {
  /* Turn off all LEDS */
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < NUM_OF_SEGMENTS; j++) {
      digitalWrite(SEVEN_SEG_PINS[SevenSegIndices[i]][j], getPolarity(IS_CATHODE));
    }
  }
}

void turnAll7SegToZeroes() {
  for (int i = 0; i < NUM_OF_7SEGS; i++) {
    for (int j = 0; j < NUM_OF_SEGMENTS; j++) {
      digitalWrite(SEVEN_SEG_PINS[i][j], getPolarity(ZERO_TO_7SEG[j]));
    }
  }
}


void scrollTextIn7Seg(const byte wordPinMaps[][NUM_OF_SEGMENTS], int wordLength, bool isLeftToRight) {


  int numOfWhiteSpacesOnSide = (wordLength / 2) + 1;
  int helloIndex = currCharIndex - numOfWhiteSpacesOnSide - 1;
  int i, j, isCurrSegHigh;

  int charactersSize = wordLength + (numOfWhiteSpacesOnSide * 2);
  if (currCharIndex < 0) {
      currCharIndex = charactersSize - 1;
  }
  if (currCharIndex >= charactersSize) {
      currCharIndex = 0;
  }


  for (i = 0; i < NUM_OF_7SEGS; i++) {
    if (currCharIndex + i <= numOfWhiteSpacesOnSide 
    || currCharIndex + i > wordLength + numOfWhiteSpacesOnSide) {
      int indicesToOff[] = {i};    
      clear7Seg(indicesToOff, 1);
    } 

    else {
      j = 0;
      while (j < NUM_OF_SEGMENTS) {
        isCurrSegHigh = getPolarity(wordPinMaps[helloIndex + i][j]);
        digitalWrite(SEVEN_SEG_PINS[i][j], isCurrSegHigh);
        j++;
      }      
    }
  }

  currCharIndex++;
  if (isLeftToRight) {
    currCharIndex -= 2;
  }
}


void checkStateChange() {
    if (prevState != currState) {
  prevState = currState;
  currCharIndex = 0;
  }
}

bool getPolarity(bool isHigh) {
  /* Invert polarity if using common anode 7 segment displays */
      if (!IS_CATHODE) {
        return !isHigh;
      }
      return isHigh;
} 