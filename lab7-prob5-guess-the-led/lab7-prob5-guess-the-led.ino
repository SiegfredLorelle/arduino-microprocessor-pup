// Include specific libraries
#include <Keypad.h>
#include <LiquidCrystal_I2C.h>

// Define LCD properties
LiquidCrystal_I2C lcd(0x27, 16, 2); // I2C address, columns, rows

// Define the keypad
const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5',  '6', 'B'},
  {'7', '8',  '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte rowPins[ROWS] = {9, 8, 7, 6};
byte colPins[COLS] = {5, 4, 3, 2};

// Create an object of Keypad
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

// Define the LED pins
const int ledPins[] = {10, 11, 12, 13, A1, A2};
const int numLeds = 6;

// LED to user number mapping
const int ledMapping[] = {1, 2, 3, 4, 5, 6};

// Define buzzer pin
const int buzzerPin = A0;

// Define note frequencies
const int REST = 0;
const int NOTE_CS4 = 277;
const int NOTE_D4 = 294;
const int NOTE_E4 = 330;
const int NOTE_FS4 = 370;
const int NOTE_GS4 = 415;
const int NOTE_A4 = 440;
const int NOTE_B4 = 494;
const int NOTE_C5 = 523;
const int NOTE_CS5 = 554;
const int NOTE_D5 = 587;
const int NOTE_E5 = 659;
const int NOTE_F5 = 698;
const int NOTE_G5 = 784;
const int NOTE_A5 = 880;
const int NOTE_D6 = 977;
const int NOTE_B5 = 988;
const int NOTE_C6 = 1047;

// Selecta Theme Song
// Notes from https://www.youtube.com/watch?v=NNSRxQPz5UM
int selectaThemeSongNotes[] = {
  NOTE_E5, NOTE_G5, NOTE_C5,
  NOTE_A5, NOTE_C6, NOTE_F5,
  NOTE_G5, NOTE_A5, NOTE_B5, NOTE_A5, NOTE_B5,
  NOTE_D6, NOTE_C6,
  NOTE_E5, NOTE_G5, NOTE_C5,
  NOTE_A5, NOTE_C6, NOTE_F5,
  NOTE_G5, NOTE_A5, NOTE_B5, NOTE_A5, NOTE_B5,
  NOTE_D6, NOTE_C6,
};

int selectaThemeSongBaseTempo = 600;
int selectaThemeSongSize = sizeof(selectaThemeSongNotes) / sizeof(selectaThemeSongNotes[0]);

// Nokia Ringtone
// Notes from https://musescore.com/user/29944637/scores/5266155
int nokiaRingtoneNotes[] = {
  NOTE_E5, 8, NOTE_D5, 8, NOTE_FS4, 4, NOTE_GS4, 4, 
  NOTE_CS5, 8, NOTE_B4, 8, NOTE_D4, 4, NOTE_E4, 4, 
  NOTE_B4, 8, NOTE_A4, 8, NOTE_CS4, 4, NOTE_E4, 4,
  NOTE_A4, 2, 
};
int nokiaRingtoneTempo = 150;
int nokiaRingtoneSize = sizeof(nokiaRingtoneNotes) / sizeof(nokiaRingtoneNotes[0]);

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();

  // Initialize each LED pin as an output
  for (int i = 0; i < numLeds; i++) {
    pinMode(ledPins[i], OUTPUT);
  }

  // Initialize the random seed
  randomSeed(analogRead(49));
}

void loop() {
  // Print the initial message
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Guess the LED!");
  delay(2000);

  // Display the LED mappings
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("LEDs: 1, 2, 3,");
  lcd.setCursor(0, 1);
  lcd.print("4, 5, 6");
  delay(3000);

  // Get the user's guess
  String guess = userGuess();

  // Display the guess on the LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("You guessed: ");
  lcd.setCursor(0, 1);
  lcd.print(guess);

  // Light a random LED and get its number
  int litLed = randomLED();

  // Clear the LCD for the result
  lcd.clear();
  lcd.setCursor(0, 0);

  // Check if the guess is correct
  if (guess == litLed) {
    lcd.print("You win!");
    playSelectaThemeSong();
  } else {
    lcd.print("You lose!");
    lcd.setCursor(0, 1);
    lcd.print("LED: ");
    lcd.print(litLed);
    playNokiaRingtone();
  }

  // Wait for a few seconds before restarting the game
  delay(3000);

  for (int i = 0; i < numLeds; i++) {
    digitalWrite(ledPins[i], LOW);
  }
}

// Function to randomly light one LED and return the LED number (1-6)
int randomLED() {
  // Turn off all LEDs first
  for (int i = 0; i < numLeds; i++) {
    digitalWrite(ledPins[i], LOW);
  }

  // Select a random LED index (0 to 5)
  int randomIndex = random(0, numLeds);

  // Light the selected LED
  digitalWrite(ledPins[randomIndex], HIGH);

  // Return the LED number (1 to 6) according to mapping
  return ledMapping[randomIndex];
}

// Function to get user's guess
String userGuess() {
  // Ask user for a guess
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Enter guess: ");

  String guess = "";
  while (true) {
    char key = keypad.getKey();
    if (key) {
      if (key == '#') {
        lcd.clear();
        break;
      } else {
        guess += key;
        lcd.print(key); 
      }
    }
  }
  return guess;
}

// Function to play Selecta Theme Song
void playSelectaThemeSong() {
  for (int i = 0; i < selectaThemeSongSize; i++) {
    int noteDuration = selectaThemeSongBaseTempo;
    tone(buzzerPin, selectaThemeSongNotes[i], noteDuration);
    delay(noteDuration * 1.30);
  }
}

// Function to play Nokia Ringtone when user loses
void playNokiaRingtone() {
  for (int i = 0; i < nokiaRingtoneSize; i += 2) {
    int note = nokiaRingtoneNotes[i];
    int duration = nokiaRingtoneNotes[i + 1] * nokiaRingtoneTempo;
    if (note == REST) {
      delay(duration);
    } else {
      tone(buzzerPin, note, duration);
      delay(duration * 1.30);
    }
  }
  noTone(buzzerPin);
}