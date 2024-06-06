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

// Create an object of Keypad
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

// Global password for verification
const String globalPassword = "ABCD1234#";

// Define the LED pins
const int ledPins[] = {10, 11, 12, 13};
const int numLeds = sizeof(ledPins) / sizeof(ledPins[0]);

// Define note frequencies
const int REST = 0;
const int NOTE_C3 = 131;
const int NOTE_CS3 = 139;
const int NOTE_D3 = 147;
const int NOTE_DS3 = 156;
const int NOTE_E3 = 165;
const int NOTE_F3 = 175;
const int NOTE_FS3 = 185;
const int NOTE_G3 = 196;
const int NOTE_GS3 = 208;
const int NOTE_A3 = 220;
const int NOTE_AS3 = 233;
const int NOTE_B3 = 247;
const int NOTE_C4 = 262;
const int NOTE_CS4 = 277;
const int NOTE_D4 = 294;
const int NOTE_DS4 = 311;
const int NOTE_E4 = 330;
const int NOTE_F4 = 349;
const int NOTE_FS4 = 370;
const int NOTE_G4 = 392;
const int NOTE_GS4 = 415;
const int NOTE_A4 = 440;
const int NOTE_AS4 = 466;
const int NOTE_B4 = 494;
const int NOTE_C5 = 523;
const int NOTE_CS5 = 554;
const int NOTE_D5 = 587;
const int NOTE_DS5 = 622;
const int NOTE_E5 = 659;
const int NOTE_F5 = 698;
const int NOTE_FS5 = 740;
const int NOTE_G5 = 784;
const int NOTE_GS5 = 831;
const int NOTE_A5 = 880;
const int NOTE_AS5 = 932;
const int NOTE_B5 = 988;
const int NOTE_C6 = 1047;

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