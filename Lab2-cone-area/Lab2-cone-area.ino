const int LED = 0;


void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
}

void loop() {
  // Prompt for the raduis and height of the cone
  float radius = getFloat("Radius of the cone: ");
  Serial.println(radius, 2);
  float height = getFloat("Height of cone: ");
  Serial.println(height, 2);

  // Solve for the volume of the cone
  float volume = M_PI * sq(radius) * height/3;
  Serial.print("Volume: ");
  Serial.println(volume, 20);

  // Blink LED thrice base on its volume
  if (volume < 100) {
    blinkLEDThrice(5000, 5000);
  }
  else if (100 <= volume && volume <= 500) {
    blinkLEDThrice(3000, 5000);
  }
  else {
    blinkLEDThrice(1000, 3000);
  }

  askAgain();
}


float getFloat(char* message) {
  while (true) {
    // Prompt for the an input
    Serial.print(message);
    while (!Serial.available()) {
    }
    String input = Serial.readStringUntil('\n');
    input.trim();

    // Ensures input is not empty
    if (input.length() == 0) {
      Serial.println("ERROR: Cannot be empty.");
      continue;
    }

    // Ensures input is not a negative number
    if (input[0] == '-') {
      Serial.println("ERROR: Cannot be negative.");
      continue;
    }
    
    // Ensures first letter is number
    if (!isDigit(input[0])) {
      Serial.println("ERROR: First character must be a digit.");
      continue;
    }

    // Ensures input has no non digits and has at most 1 decimal point
    bool hasNonDigit = false;
    int decimalCount = 0;
    for (int i = 1; i < input.length(); i++) {
      if (input[i] == '.') {
        decimalCount++;
      }
      else if (!isDigit(input[i])) {
        hasNonDigit = true;
      }
    }
    if (hasNonDigit) {
      Serial.println("ERROR: Must NOT contain non digits.");
      continue;
    }
    if (decimalCount > 1) {
      Serial.println("ERROR: Cannot have more than (one) 1 decimal point.");
      continue;
    }

    float validFloat = input.toFloat();
    return validFloat;
  }
}

void askAgain() {
  while (true) {
    Serial.println("press 0 to try again; press 1 to exit: ");
    while (!Serial.available()) {
    }
    String answer = Serial.readStringUntil('\n');
    answer.trim();
    if (answer.equals("0")) {
      break;
    }
    else if (answer.equals("1")) {
      Serial.println("Goodbye!");
      while (true) {
      }
    }
  }

}


void blinkLEDThrice(int onDuration, int offDuration) {
  for (int i = 0; i < 3; i++) {
  digitalWrite(LED, HIGH);
  delay(onDuration);
  digitalWrite(LED, LOW);
  delay(offDuration);
  }
}