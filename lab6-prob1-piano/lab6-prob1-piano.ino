// Define pin numbers for buttons
const int buttonPins[8] = {2, 3, 4, 5, 6, 7, 8, 9};

// Define the buzzer pin
const int buzzerPin = 10;

// Define the frequencies for the musical notes
const int noteFrequencies[8] = {
  262, // DO (C4)
  294, // RE (D4)
  330, // MI (E4)
  349, // FA (F4)
  392, // SO (G4)
  440, // LA (A4)
  494, // TI (B4)
  523  // DO (C5)
};

void setup() {
  Serial.begin(9600);
  // Set button pins as INPUT_PULLUP
  for (int i = 0; i < 8; i++) {
    pinMode(buttonPins[i], INPUT_PULLUP);
  }
  // Set buzzer pin as OUTPUT and start it off
  pinMode(buzzerPin, OUTPUT);
  noTone(buzzerPin);
}

void loop() {
  // Check each button
  for (int i = 0; i < 8; i++) {
    // If the button is pressed
    if (digitalRead(buttonPins[i]) == LOW) {
      Serial.println(i);
      // Play the corresponding note
      tone(buzzerPin, noteFrequencies[i]);
      return; // Exit the loop to continue playing the note
    }
  }
  // Stop the buzzer when no button is pressed
  noTone(buzzerPin);
}