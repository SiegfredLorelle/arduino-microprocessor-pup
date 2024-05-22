const int NUM_OF_7SEGMENTS = 2;
const int NUM_OF_SEGMENT_PER_DISPLAY = 7;

// Pins {a, b, c ,d ,e ,f, g} of 7 segments
const byte SEVEN_SEGMENT_DISPLAY_PINS[NUM_OF_7SEGMENTS][NUM_OF_SEGMENT_PER_DISPLAY] = {
  {7, 8, 9, 10, 11, 12, 13},    // 7 segment display 1
  {A4, A3, 2, 3, 4, 5, 6},      // 7 segment display 2
                                // Add more 7 segment pins to display more characters
                                // ...
};

const byte LDR1 = A2;
const byte LDR2 = A1;


// Character mapping to 7 segments
const int HELLO_LENGTH = 5;
const int BYE_LENGTH = 3;
const byte ZERO_TO_7SEG[NUM_OF_SEGMENT_PER_DISPLAY] = {
  HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, LOW  // 0
};
const byte HELLO_TO_7SEG[][NUM_OF_SEGMENT_PER_DISPLAY] = {
  {LOW, HIGH, HIGH, LOW, HIGH, HIGH, HIGH},   // H
  {HIGH, LOW, LOW, HIGH, HIGH, HIGH, HIGH},   // E
  {LOW, LOW, LOW, HIGH, HIGH, HIGH, LOW},     // L
  {LOW, LOW, LOW, HIGH, HIGH, HIGH, LOW},     // L
  {HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, LOW}   // O
};
const byte BYE_TO_7SEG[][NUM_OF_SEGMENT_PER_DISPLAY] = {
  {LOW, LOW, HIGH, HIGH, HIGH, HIGH, HIGH},   // b
  {LOW, HIGH, HIGH, HIGH, LOW, HIGH, HIGH},   // y
  {HIGH, LOW, LOW, HIGH, HIGH, HIGH, HIGH},   // E
};

// Set to true if 7 segment displays used are common cathode
const bool IS_CATHODE = false;
// Feel free to adjust delay duration
const int DELAY_DURATION = 500;

int currCharIndex = 0;
int prevState = 0;
int currState = 0;

void setup() {
  Serial.begin(9600);
  // Assign mode for all pins 
  for (int i = 0; i < NUM_OF_7SEGMENTS; i++) {
    for (int j = 0; j < NUM_OF_SEGMENT_PER_DISPLAY; j++) {
      pinMode(SEVEN_SEGMENT_DISPLAY_PINS[i][j], OUTPUT);
    }
  }
  pinMode(LDR1, INPUT_PULLUP);
  pinMode(LDR2, INPUT_PULLUP);
  
  // Start with no segments off
  int indicesToZero[] = {0, 1};
  clear7Seg(indicesToZero, NUM_OF_7SEGMENTS);
}

void loop() {
  // Read LDR states; LDR is considered on if exposed to enough light
  bool isLDR1On = !digitalRead(LDR1);
  bool isLDR2On = !digitalRead(LDR2);

  // Update 7 segment based on LDR states
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

  delay(DELAY_DURATION);
}


void clear7Seg(int SevenSegIndices[], int size) {
  /* Turn off specific segment displays */
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < NUM_OF_SEGMENT_PER_DISPLAY; j++) {
      digitalWrite(SEVEN_SEGMENT_DISPLAY_PINS[SevenSegIndices[i]][j], getPolarity(IS_CATHODE));
    }
  }
}

void turnAll7SegToZeroes() {
  /* Turn all 7 segments to '0' */
  for (int i = 0; i < NUM_OF_7SEGMENTS; i++) {
    for (int j = 0; j < NUM_OF_SEGMENT_PER_DISPLAY; j++) {
      digitalWrite(SEVEN_SEGMENT_DISPLAY_PINS[i][j], getPolarity(ZERO_TO_7SEG[j]));
    }
  }
}


void scrollTextIn7Seg(const byte wordPinMaps[][NUM_OF_SEGMENT_PER_DISPLAY], int wordLength, bool isLeftToRight) {
  /* Scroll each character in wordPinMaps var on direction of isLeftToRight var */

  // Add white spaces space at the start and end of the word to act as buffer 
  int numOfWhiteSpacesOnSide = (wordLength / 2) + 1;
  int charactersSize = wordLength + (numOfWhiteSpacesOnSide * 2);

  // Adjust currCharIndex if it goes out of bounds  
  if (currCharIndex < 0) {
      currCharIndex = charactersSize - 1;
  }
  if (currCharIndex >= charactersSize) {
      currCharIndex = 0;
  }

  // Update 7 segment accordingly
  for (int i = 0; i < NUM_OF_7SEGMENTS; i++) {
    // Update 7segment to off if character is a whitespace buffer
    int displayIndex = currCharIndex - numOfWhiteSpacesOnSide - 1 + i;
    if (currCharIndex + i <= numOfWhiteSpacesOnSide 
    || currCharIndex + i > wordLength + numOfWhiteSpacesOnSide) {
      int indicesToOff[] = {i};    
      clear7Seg(indicesToOff, 1);
    } 

    // Update 7segment to the character
    else {
      for (int j = 0; j < NUM_OF_SEGMENT_PER_DISPLAY; j++) {
        bool isCurrSegmentOn = getPolarity(wordPinMaps[displayIndex][j]);
        digitalWrite(SEVEN_SEGMENT_DISPLAY_PINS[i][j], isCurrSegmentOn);
      }
    }
  }

  // Increment or decrement based on the direction of the text
  if (isLeftToRight) {
    currCharIndex--;
  }
  else {
    currCharIndex++;
  }
}


void checkStateChange() {
  /* Detect state changes then resets character/word index */
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