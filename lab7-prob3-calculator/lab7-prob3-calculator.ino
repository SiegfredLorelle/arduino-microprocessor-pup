#include <LiquidCrystal.h>
#include <Keypad.h>

LiquidCrystal lcd(7, 6, 5, 4, 3, 2);


const byte rows = 4;
const byte cols = 4;

// Keypad values
char keys[rows][cols] = {
  {'1','2','3', 'A'},
  {'4','5','6', 'B'},
  {'7','8','9', 'C'},
  {'*','0','#', 'D'}
};

// Keypad pins
byte rowPins[rows] = {A5, A4, A3, A2};
byte colPins[cols] = {13, 12, 11, 10}; 

// Map keypad with its pins
Keypad keypad = Keypad(
  makeKeymap(keys), 
  rowPins, 
  colPins, 
  rows, 
  cols
);

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);

}

void loop() {
  // Execute command based on entered key
  char key = keypad.getKey();
  if (key) {
      Serial.println(key);
    }
  // askToTryAgain();
}

void displayMenu() {
  lcd.clear();
  lcd.setCursor(0, 0);
}