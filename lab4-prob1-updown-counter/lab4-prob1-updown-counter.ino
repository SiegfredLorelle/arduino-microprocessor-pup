const int MAX_COUNT = 3;
const int MAX_DIGITS = 1;

const int NUM_OF_DIGITS = 10;
const int NUM_OF_SEGMENTS = 7;

const byte SEVEN_SEG_PINS[][NUM_OF_SEGMENTS] = {
  {0, 1, 2, 3, 4, 5, 6},
  {7, 8, 9, 10, 11, 12, 13}
};



const byte BCD_TO_7SEG[NUM_OF_DIGITS][NUM_OF_SEGMENTS] = {
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

const byte SWITCH = A5;

bool isSwitchOn;
int currentDigit;
bool isCathode = false;

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  for (int i = 0; i < NUM_OF_SEGMENTS; i++) {
    for (int j = 0; j < MAX_DIGITS; j++) {
      pinMode(SEVEN_SEG_PINS[j][i], OUTPUT);
    }
  }
  pinMode(SWITCH, INPUT_PULLUP);
  clearAll();
}

void loop() {
  // put your main code here, to run repeatedly:
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
      digitalWrite(SEVEN_SEG_PINS[j][i], !isCathode);
    }
  }
}
void LightAll() {
  for (int i = 0; i < NUM_OF_SEGMENTS; i++) {
    for (int j = 0; j < NUM_OF_SEGMENTS; j++) {
      digitalWrite(SEVEN_SEG_PINS[j][i], isCathode);
    }
  }
}


void intTo7Seg(int integer) {
  bool isCurrOnesSegHigh, isCurrTensSegHigh;

  
  char intAsChars[MAX_DIGITS];
  itoa(integer, intAsChars, 10);
  Serial.print(intAsChars[0]);
  for (int i = 0; i < MAX_DIGITS; i++) {
    intAsChars[i];
  }

  if (integer < pow(10, (MAX_DIGITS - 1))) {
    intAsChars[1] = intAsChars[0];
    intAsChars[0] = '0';
  }

  
  for (int i = 0; i < NUM_OF_SEGMENTS; i++) {

    // isCurrOnesSegHigh = BCD_TO_7SEG[intAsChars[1] - '0'][i];
    // isCurrTensSegHigh = BCD_TO_7SEG[intAsChars[0] - '0'][i];

    for (int k = 0; k < MAX_DIGITS; k++) {
      
        byte isCurrSegHigh = BCD_TO_7SEG[intAsChars[k] - '0'][i];

      if (!isCathode) {
        isCurrSegHigh = !isCurrSegHigh;
      }
      digitalWrite(SEVEN_SEG_PINS[MAX_DIGITS - k - 1][i], isCurrSegHigh);
    }
  }
}

/* TODO:
SOLVE MAX DIGITS AUTOMATICALLY
RENAME BCD TO INT
REMOVE LIGHT ALL
TEST multiple places
PLACE IN FUNCTIONS 
COMMENTS*/