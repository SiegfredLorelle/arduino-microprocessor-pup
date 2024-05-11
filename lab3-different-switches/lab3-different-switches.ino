const int BTN1 = 2;
const int BTN2 = 3;
const int BTN3 = 4;
const int BTN4 = 5;

const int LED1 = 6;
const int LED2 = 7;
const int LED3 = 8;
const int LED4 = 9;
const int LED5 = 10;
const int LED6 = 11;
const int LED7 = 12;
const int LED8 = 13;

const int LEDS[8] = {
  LED1, 
  LED2, 
  LED3, 
  LED4, 
  LED5, 
  LED6, 
  LED7, 
  LED8,
};
const int NUM_OF_LEDS = 8;

bool isProcessOngoing = false;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(BTN1, INPUT_PULLUP);
  pinMode(BTN2, INPUT_PULLUP);
  pinMode(BTN3, INPUT_PULLUP);
  pinMode(BTN4, INPUT_PULLUP);

  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(LED6, OUTPUT);
  pinMode(LED7, OUTPUT);
  pinMode(LED8, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  bool isBtn1Pressed = digitalRead(BTN1);
  bool isBtn2Pressed = digitalRead(BTN2);
  bool isBtn3Pressed = digitalRead(BTN3);
  bool isBtn4Pressed = digitalRead(BTN4);

  if (isBtn1Pressed) {
    Serial.println("1 PRESSED");
    blinkTraverse();
  }
  if (isBtn2Pressed) {
    Serial.println("2 PRESSED");
    blinkInward(false);
  }
  if (isBtn3Pressed) {
    Serial.println("3 PRESSED");
    // blinkInward(true);
    clearLEDs();
  }
  if (isBtn4Pressed) {
    Serial.println("4 PRESSED");
    // blinkGapped();
    litLEDs();
  }
}


void clearLEDs() {
  int durationInMS = 1000;
  int delayInMS = durationInMS / NUM_OF_LEDS;
  Serial.println("CLEARING");

  for (int i = 0; i < NUM_OF_LEDS; i++) {
    digitalWrite(LEDS[i], LOW);
    Serial.print("CLEARING: ");
    Serial.println(i);
  }
}

void litLEDs() {
  Serial.println("LITTING");
  for (int i = 0; i < NUM_OF_LEDS; i++) {
    digitalWrite(LEDS[i], HIGH);
    Serial.print("LIT: ");
    Serial.println(i);
  }
}

void blinkTraverse() {
  int durationInMS = 1000;
  int delayInMS = durationInMS / NUM_OF_LEDS;

  for (int i = 0; i < NUM_OF_LEDS; i++) {
    clearLEDs();
    digitalWrite(LEDS[i], HIGH);
    delay(delayInMS);
  }

  for (int i = NUM_OF_LEDS - 2; i > 0; i--) {
    clearLEDs();
    digitalWrite(LEDS[i], HIGH);
    delay(delayInMS);
  }
}

void blinkInward(bool keep) {

}

void blinkGapped() {

}

/* Questions:
1. magkakahiwalay ba ung problem 1, 2, 3 like tig hiwa hiwalay ng program
2.  ano mangyayare kapag multiple buttons pinindot
3. kapag may ongoing process, maooveride ba kapag pumindot uli
4. 
*/