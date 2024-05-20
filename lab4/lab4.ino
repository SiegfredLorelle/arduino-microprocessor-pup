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
  if (pressedKey) {
  	Serial.println(pressedKey);
  }
}
