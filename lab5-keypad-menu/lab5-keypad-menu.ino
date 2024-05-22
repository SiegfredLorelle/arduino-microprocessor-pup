#include <Keypad.h>

// Constants
const byte ROWS = 4; // Four rows
const byte COLS = 3; // Three columns

// Keypad setup
char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};

byte rowPins[ROWS] = {13, 12, 11, 10}; // Connect to the row pinouts of the keypad
byte colPins[COLS] = {9, 8, 7};    // Connect to the column pinouts of the keypad

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

// LED pins
const byte ledPins[] = {3, 2, A0, A1, A2, A3, A4, A5};
const int numLeds = sizeof(ledPins) / sizeof(ledPins[0]);

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < numLeds; i++) {
    pinMode(ledPins[i], OUTPUT);
    digitalWrite(ledPins[i], LOW);
  }
  displayMenu();
}

void loop() {
  char key = keypad.getKey();
  if (key) {
    switch (key) {
      case '1': pyramidOfStars(); break;
      case '2': drawSquare(); break;
      case '3': fibonacciSeries(); break;
      case '4': multiplicationTable(); break;
      case '5': surfaceAreaOfCone(); break;
      case '6': printLogo(); break;
      case '7': lightUpLEDs(); break;
      case '8': blinkLEDs(); break;
      case '9': errorBlinkLEDs(); break;
      case '0': invalidCode(); break;
      case '*': Serial.println("*"); break;
      case '#': Serial.println("#"); break;
    }
    askToTryAgain();
  }
}

void displayMenu() {
  Serial.println("Main Menu:");
  Serial.println("1. Pyramid of stars");
  Serial.println("2. Draw a Square");
  Serial.println("3. Fibonacci Number Series");
  Serial.println("4. Multiplication table up to 10x");
  Serial.println("5. Solve the Surface Area of a cone");
  Serial.println("6. Print the logo of Louis Vuitton using *");
  Serial.println("7. Light up 8LED from left to right for 3s");
  Serial.println("8. Blink 4LED from the left, then blink 4LED from the right");
  Serial.println("9. Display an error, then blink all LED for 2 seconds");
  Serial.println("0. Display INVALID CODE!!!");
}

void pyramidOfStars() {
  int numAsterisks;
  char inputBuffer[10]; // Buffer to store user input

  // Prompt user for input until a valid numeric value is entered
  while (true) {
    Serial.println("Enter the number of asterisks for the pyramid: ");
    while (!Serial.available()); // Wait for user input
    int bytesRead = Serial.readBytesUntil('\n', inputBuffer, sizeof(inputBuffer) - 1);
    inputBuffer[bytesRead] = '\0'; // Null-terminate the string

    // Check if input contains only digits
    bool validInput = true;
    for (int i = 0; i < bytesRead; ++i) {
      if (!isdigit(inputBuffer[i])) {
        validInput = false;
        break;
      }
    }

    if (validInput) {
      numAsterisks = atoi(inputBuffer); // Convert input to integer
      break; // Valid input, exit the loop
    } else {
      Serial.println("Invalid input. Please enter a valid number.");
    }
  }

  // Print the centered pyramid
  for (int i = 1; i <= numAsterisks; ++i) {
    // Print spaces (centered)
    for (int j = 1; j <= numAsterisks - i; ++j) {
      Serial.print(" ");
    }
    // Print asterisks
    for (int j = 0; j <= i +  - 1; ++j) {
      Serial.print(" *");
    }
    Serial.println(); // Move to the next line
  }
}

void drawSquare() {
  int side = getInt("Enter side length for square:", false);
  Serial.println(side);

  for (int i = 0; i < side; i++) Serial.print("*");
  Serial.println();
  for (int i = 0; i < side - 2; i++) {
    Serial.print("*");
    for (int j = 0; j < side - 2; j++) Serial.print(" ");
    Serial.println("*");
  }
  for (int i = 0; i < side; i++) Serial.print("*");
  Serial.println();
}

void fibonacciSeries() {
  int n = getInt("Enter the number of Fibonacci terms:", false);
  Serial.println(n);

  long a = 0, b = 1, next;
  Serial.print("Fibonacci Series: ");
  for (int i = 0; i < n; i++) {
    Serial.print(a);
    Serial.print(" ");
    next = a + b;
    a = b;
    b = next;
  }
  Serial.println();
}

void multiplicationTable() {
  int num = getInt("Enter number for multiplication table: ", true);
  Serial.println(num);

  if (num > 10) {
    
    return;
  }

  for (int i = 1; i <= 10; i++) {
    Serial.print(num);
    Serial.print(" x ");
    Serial.print(i);
    Serial.print(" = ");
    Serial.println(num * i);
  }
}

void surfaceAreaOfCone() {
  float radius = getFloat("Enter radius: ");
  Serial.println(radius);
  float height = getFloat("Enter height: ");
  Serial.println(height);
  float slantHeight = sqrt(radius * radius + height * height);
  float surfaceArea = PI * radius * (radius + slantHeight);
  Serial.print("Surface Area of Cone: ");
  Serial.println(surfaceArea);
}

void printLogo() {
    Serial.println(F("                                                *******************\n"
    " *********************                           *******************\n"
    " *********************                              ************\n"
    "     **************                                    *******\n"
    "      ***********                                       *****\n"
    "       ***********           **********************     *****       \n"
    "        ***********         **********************     *****        \n"
    "         ***********           **************         ******        \n"
    "          ***********           **********            *****         \n"
    "          ***********          ***********           *****          \n"
    "           ***********         **********           *****           \n"
    "            ***********       **********           *****            \n"
    "             ***********     ***********           *****            \n"
    "              ***********    **********           *****             \n"
    "               ***********  **********           *****              \n"
    "                ********** ***********          *****               \n"
    "                 ********************           *****               \n"
    "                  *******************           *****               \n"
    "                   ******************          *****                \n"
    "                    ****************          *****                 \n"
    "                     **************          ******                 \n"
    "                      *************          *****                  \n"
    "                       **********            *****                   \n"
    "                        ***********          *****                   \n"
    "                        *************       ******                  \n"
    "                       ***************      *****                   \n"
    "                       ****************    *****                    \n"
    "                      ******************  *****                     \n"
    "                      ****************** *****                ****\n"
    "                     *************************               ****\n"
    "                    **********  *************              ****\n"
    "                    **********  ************              ****\n"
    "                   **********    **********              ****\n"
    "                  **********      *********            ******\n"
    "                 ***********                         *******\n"
    "               ************                        ********\n"
    "    ******************************************************** \n"
    "   *********************************************************\n"
    "                                                                    \n"
    "                                                                    \n"
    "                                                                    \n"
    "                                                                    \n"
    "                                                                    \n"
    " **   ******  *   ** * ** *    **  ****   ** * ***  *** *******  *    **\n"
    "  *  *      * *   ** * ***      *  *  *   *  *  *    *  *      * * *  **\n"
    "  *  *      * *   ** *    **     ***  *   *  *  *   **  *      * *  ****\n"
    " **** ******  ***** ** ****      **   *****  *  **  **  *******  *    **"));
}



void lightUpLEDs() {
  for (int i = 0; i < numLeds; i++) {
    digitalWrite(ledPins[i], HIGH);
    delay(375);  // 3 seconds divided by 8 LEDs
    digitalWrite(ledPins[i], LOW);
  }
}

void blinkLEDs() {
  for (int i = 0; i < 4; i++) {
    digitalWrite(ledPins[i], HIGH);
    delay(500);
    digitalWrite(ledPins[i], LOW);
  }
  delay(500);
  for (int i = 7; i > 3; i--) {
    digitalWrite(ledPins[i], HIGH);
    delay(500);
    digitalWrite(ledPins[i], LOW);
  }
}

void errorBlinkLEDs() {
  Serial.println("Error!");
  for (int i = 0; i < numLeds; i++) digitalWrite(ledPins[i], HIGH);
  delay(2000);
  for (int i = 0; i < numLeds; i++) digitalWrite(ledPins[i], LOW);
}

void invalidCode() {
  Serial.println("INVALID CODE!!!");
}

void askToTryAgain() {
  while (true) {
    Serial.println("press Y to try again; press N to exit: ");
    while (!Serial.available()) {
    }
    String answer = Serial.readStringUntil('\n');
    answer.trim();
    if (answer.equals("Y") || answer.equals("y")) {
      displayMenu();
      break;
    }
    else if (answer.equals("N") || answer.equals("n")) {
      Serial.println("Goodbye!");
      while (true) {
      }
    }
  }
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

int getInt(char* message, bool isNegativeAllowed) {
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
    if (input[0] == '-' && !isNegativeAllowed) {
      Serial.println("ERROR: Cannot be negative.");
      continue;
    }

    // Ensures input has no non digits and has at most 1 decimal point
    bool hasNonDigit = false;
    for (int i = 0; i < input.length(); i++) {
      if (!isDigit(input[i])) {
        hasNonDigit = true;
        break;
      }
    }

    if (hasNonDigit) {
      Serial.println("ERROR: Must NOT contain non digits.");
      continue;
    }

    int validInt = input.toFloat();
    if (validInt < 0) continue;
    return validInt;
  }
}