const int btn1 = 0;
const int btn2 = 1;
const int btn3 = 2;
const int btn4 = 3;

const int LED1 = 4;
const int LED2 = 5;
const int LED3 = 6;
const int LED4 = 7;
const int LED5 = 8;
const int LED6 = 9;
const int LED7 = 10;
const int LED8 = 11;

const int LEDs[8] = {
  LED1, 
  LED2, 
  LED3, 
  LED4, 
  LED5, 
  LED6, 
  LED7, 
  LED8,
};

bool isProcessOngoing = false;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(btn1, INPUT);
  pinMode(btn2, INPUT);
  pinMode(btn3, INPUT);
  pinMode(btn4, INPUT);

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
  bool isBtn1Pressed = digitalRead(btn1);
  bool isBtn2Pressed = digitalRead(btn2);
  bool isBtn3Pressed = digitalRead(btn3);
  bool isBtn4Pressed = digitalRead(btn4);

  if (isBtn1Pressed) {
    blinkTraverse();
  }
  else if (isBtn2Pressed) {
    blinkInward(false);
  }
  else if (isBtn3Pressed) {
    blinkInward(true);
  }
  else if (isBtn4Pressed) {
    blinkGapped();
  }
}


void clearLEDs() {

}

void blinkTraverse() {

  for (int i = 0; i < sizeof(LEDs); i++) {
    digitalWrite(LEDs[i], HIGH);
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