// Include specific libraries
#include <Keypad.h>
#include <LiquidCrystal_I2C.h>
#include <EEPROM.h>

// Define LCD properties
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Define the keypad
const byte ROWS = 4;
const byte COLS = 4; 
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {9, 8, 7, 6};
byte colPins[COLS] = {5, 4, 3, 2};

// Define the LED pins
const int ledPins[] = {10, 11, 12, 13};
const int numLeds = sizeof(ledPins) / sizeof(ledPins[0]);

// Create an object of Keypad
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

// Global password for verification
const String globalPassword = "ABCD1234#";

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
}

void loop() {
  // Prompt for asking of name and password
  String userName = getUsername("ENTER YOUR NAME:");
  lcd.setCursor(0, 0);
  lcd.print(userName);
  delay(2000);

 bool accessGranted = false;
  for (int attempt = 1; attempt <= 3; attempt++) {
    String password = getPassword("ENTER YOUR PASSWORD:");
    lcd.setCursor(0, 0);
    lcd.print(password);
    delay(2000);
    
    if (password == globalPassword) {
      accessGranted = true;
      correctPassword();
      break;
    } else {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("ACCESS DENIED!!!");
      incorrectPassword(); 
      delay(2000);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(attempt);
      lcd.print(" ATTEMPT");
      lcd.setCursor(0, 1);
      lcd.print("ALREADY");
      delay(2000);
    }
  }

  if (accessGranted) {
    // Display welcome message
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("WELCOME,");
    lcd.setCursor(0, 1);
    lcd.print(userName + "!!!!");
    delay(20000);
  } else {
      disableKeypad();
  }
}

// Function to get the username from the keyboard
String getUsername(String prompt) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(prompt);
  String userName = "";
  while (true) {
    if (Serial.available()) {
      char key = Serial.read();
      if (key == '\n' || key == '\r') {
        lcd.clear();
        break;
      } else {
        userName += key;
        lcd.print(key);
      }
    }
  }
  return userName;
}

// Function to get the password from the keypad
String getPassword(String prompt) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("ENTER YOUR");
  lcd.setCursor(0, 1);
  lcd.print("PASSWORD:");
  String password = "";
  while (true) {
    if (Serial.available()) {
      char key = Serial.read();
      if (key == '\n' || key == '\r') {
        lcd.clear();
        break;
      }
    }
    char key = keypad.getKey();
    if (key) {
      password += key;
      lcd.print(key); 
    }
  }
  return password;
}

void disableKeypad() {
  while (true) {
    lcd.clear();
    for (int i = 0; i < numLeds; i++) {
      digitalWrite(ledPins[i], HIGH);
    }
  }
}

void correctPassword() {
  // Light LEDs from left to right
  for (int i = 0; i < numLeds; i++) {
    digitalWrite(ledPins[i], HIGH);
    delay(500);                      
    digitalWrite(ledPins[i], LOW);  
  }
}

void incorrectPassword() {
  // Blink all LEDs three times
  for (int j = 0; j < 3; j++) {
    for (int i = 0; i < numLeds; i++) {
      digitalWrite(ledPins[i], HIGH);
    }
    delay(500);
    for (int i = 0; i < numLeds; i++) {
      digitalWrite(ledPins[i], LOW);
    }
    delay(500); 
  }
}