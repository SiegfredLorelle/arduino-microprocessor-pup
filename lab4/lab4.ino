#include <Keypad.h>
  
const int NUM_ROWS = 4;
const int NUM_COLS = 3;

char keypadMapping[NUM_ROWS][NUM_COLS] = {
  {'0', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};

byte ROW_PINS[NUM_ROWS] = {
	13, 12, 11, 10
};

byte COL_PINS[NUM_COLS] = {
	9, 8, 7
};

Keypad KEYPAD = Keypad(
  makeKeymap(keypadMapping), 
  ROW_PINS, 
  COL_PINS, 
  NUM_ROWS, 
  NUM_COLS
); 

void setup() {
	Serial.begin(9600);
}

void loop() {
  char pressedKey = KEYPAD.getKey(); 
  if (pressedKey == "1") {
  	Serial.println("PRESSED 1");
  }
  else if (pressedKey == "2") {
  	Serial.println("PRESSED 2");
  }
  else if (pressedKey == "3") {
  	Serial.println("PRESSED 3");
  }
  else if (pressedKey == "4") {
  	Serial.println("PRESSED 4");
  }
  else if (pressedKey == "5") {
  	Serial.println("PRESSED 5");
  }
  else if (pressedKey == "6") {
  	Serial.println("PRESSED 6");
  }
  else if (pressedKey == "7") {
  	Serial.println("PRESSED 7");
  }
  else if (pressedKey == "8") {
  	Serial.println("PRESSED 8");
  }
  else if (pressedKey == "9") {
  	Serial.println("PRESSED 9");
  }
  else if (pressedKey == "*") {
  	Serial.println("PRESSED *");
  }
  else if (pressedKey == "#") {
  	Serial.println("PRESSED #");
  }
}
