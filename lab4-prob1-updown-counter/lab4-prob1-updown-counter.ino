const int NUM_OF_DIGITS = 10;
const int NUM_OF_SEGMENTS = 7;

// Feel free to change it to any positive number that can be contained in the 7 segment(s)
const int MAX_COUNT = 15;

// Pins
// {a, b, c ,d ,e ,f, g} of 7 segments
const byte SEVEN_SEG_PINS[][NUM_OF_SEGMENTS] = {
  {0, 1, 2, 3, 4, 5, 6},      // Ones place
  {7, 8, 9, 10, 11, 12, 13},  // Tens place
                              // Add more pins if using hundreds place
                              // Add more pins if using thousands place
                              // ...
};
const byte SWITCH = A5;



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
// 
int maxDigits = 0;
int numOf7Segments;

bool isSwitchOn;
int currentDigit;

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  int tmpMaxCount = MAX_COUNT; 
  while (tmpMaxCount > 0) {
    tmpMaxCount /= 10;
    maxDigits++;
  }
  numOf7Segments = sizeof(SEVEN_SEG_PINS) / sizeof(int);

  for (int i = 0; i < NUM_OF_SEGMENTS; i++) {
    for (int j = 0; j <= numOf7Segments; j++) {
      pinMode(SEVEN_SEG_PINS[j][i], OUTPUT);

    }
  }
  pinMode(SWITCH, INPUT_PULLUP);
  
  
  clearAll();
}

void loop() {
  // put your main code here, to run repeatedly:
  // Serial.println(maxDigits);
  if (MAX_COUNT <= 0) {
    
    for (int i = 0; i < numOf7Segments; i++) {
      for (int j = 0; j < NUM_OF_SEGMENTS; j++) {
        digitalWrite(SEVEN_SEG_PINS[i][j], !ERROR_7SEG[j]);
      }
    }
    delay(300);
    clearAll();
    delay(300);

    return;
  }

  isSwitchOn = digitalRead(SWITCH);
  // Serial.println(isSwitchOn);

  if (isSwitchOn) {
    currentDigit++;
  }
  else {
    currentDigit--;
  }
  if (currentDigit < 0) {
    currentDigit = MAX_COUNT;
  }
  if (currentDigit > MAX_COUNT) {
    currentDigit = 0;
  }

  // LightAll();
  // delay(500);
  // clearAll();
  delay(300);
  intTo7Seg(currentDigit);
}

void clearAll() {
  for (int i = 0; i < NUM_OF_SEGMENTS; i++) {
    for (int j = 0; j < NUM_OF_SEGMENTS; j++) {
      digitalWrite(SEVEN_SEG_PINS[j][i], !IS_CATHODE);
    }
  }
}
void LightAll() {
  for (int i = 0; i < NUM_OF_SEGMENTS; i++) {
    for (int j = 0; j < NUM_OF_SEGMENTS; j++) {
      digitalWrite(SEVEN_SEG_PINS[j][i], IS_CATHODE);
      // Serial.println(i);
    }
  }
}


void intTo7Seg(int integer) {
  bool isCurrOnesSegHigh, isCurrTensSegHigh;

  
  char intAsChars[maxDigits];
  itoa(integer, intAsChars, 10);

  if (integer < pow(10, (maxDigits - 1))) {
    intAsChars[1] = intAsChars[0];
    intAsChars[0] = '0';
  }

  
  for (int i = 0; i < NUM_OF_SEGMENTS; i++) {
    for (int k = 0; k < maxDigits; k++) {
      
      byte isCurrSegHigh = DIGIT_TO_7SEG[intAsChars[k] - '0'][i];

      if (!IS_CATHODE) {
        isCurrSegHigh = !isCurrSegHigh;
      }
      digitalWrite(SEVEN_SEG_PINS[maxDigits - k - 1][i], isCurrSegHigh);
    }
  }
}

/* TODO:
SOLVE MAX DIGITS AUTOMATICALLY
RENAME DIGIT TO INT
REMOVE LIGHT ALL
TEST multiple places
PLACE IN FUNCTIONS 
COMMENTS*/