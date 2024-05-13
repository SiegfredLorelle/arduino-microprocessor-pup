const int MAX_COUNT = 15;
const int NUM_OF_DIGITS = 10;
const int NUM_OF_SEGMENTS = 7;
const byte ONES_PIN[NUM_OF_SEGMENTS] = {
  0, 1, 2, 3, 4, 5, 6
};
const byte TENS_PIN[NUM_OF_SEGMENTS] = {
  7, 8, 9, 10, 11, 12, 13
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

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  for (int i = 0; i < NUM_OF_SEGMENTS; i++) {
    pinMode(ONES_PIN[i], OUTPUT);
    pinMode(TENS_PIN[i], OUTPUT);
    Serial.println(i);
  }
  pinMode(SWITCH, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  isSwitchOn = digitalRead(SWITCH);
  // Serial.println(isSwitchOn);

  // TODO: MAKE 4 BIT UP/DOWN COUNTER
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
  Serial.println(currentDigit);


}
