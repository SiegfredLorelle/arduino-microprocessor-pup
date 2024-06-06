#include <Keypad.h>

// Define the keypad
const byte ROWS = 4; // Four rows
const byte COLS = 4; // Four columns
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {9, 8, 7, 6}; // Connect to the row pinouts of the keypad
byte colPins[COLS] = {5, 4, 3, 2}; // Connect to the column pinouts of the keypad

// Create an object of Keypad
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup() {
  Serial.begin(9600);
}

void loop() {
  // Prompt for asking of name and password
  String userName = getUsername("ENTER YOUR NAME: ");
  Serial.println();
  String password = getPassword("ENTER YOUR PASSWORD: ");
  Serial.println(); 
  while (true) {}
}

// Function to get the username from the keyboard
String getUsername(String prompt) {
  Serial.print(prompt);
  String userName = "";
  while (true) {
    if (Serial.available()) {
      char key = Serial.read();
      if (key == '\n' || key == '\r') {
        break;
      } else {
        userName += key;
        Serial.print(key);
      }
    }
  }
  return userName;
}

// Function to get the password from the keypad
String getPassword(String prompt) {
  Serial.print(prompt);
  String password = "";
  while (true) {

    // Use keyboard Enter key to input password to serial monitor
    if (Serial.available()) {
      char key = Serial.read();
      if (key == '\n' || key == '\r') {
        break;
      }
    }

    // Read the key from the keypad
    char key = keypad.getKey();
    if (key) {
      password += key;
      Serial.print(key); 
    }
  }
  return password;
}