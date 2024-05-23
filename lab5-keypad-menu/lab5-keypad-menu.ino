#include <Keypad.h>

const byte rows = 4;
const byte cols = 3;

// Keypad values
char keys[rows][cols] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};

// Keypad pins
byte rowPins[rows] = {13, 12, 11, 10};
byte colPins[cols] = {9, 8, 7}; 

// Map keypad with its pins
Keypad keypad = Keypad(
  makeKeymap(keys), 
  rowPins, 
  colPins, 
  rows, 
  cols
);

// LED pins
const byte ledPins[] = {3, 2, A0, A1, A2, A3, A4, A5};
const int numLeds = sizeof(ledPins) / sizeof(ledPins[0]);

void setup() {
  Serial.begin(9600);
  // Set LEDs mode as outputs
  for (int i = 0; i < numLeds; i++) {
    pinMode(ledPins[i], OUTPUT);
    digitalWrite(ledPins[i], LOW);
  }
  displayMenu();
}

void loop() {
  // Execute command based on entered key
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
      case '0': Serial.println("INVALID CODE!!!"); break;
      case '*': Serial.println("*"); break;
      case '#': Serial.println("#"); break;
    }
    askToTryAgain();
  }
}

void displayMenu() {
  /* Displays the main menu */
  Serial.println();
  Serial.println("Main Menu:");
  Serial.println("1. Draw a pyramid");
  Serial.println("2. Draw a Square");
  Serial.println("3. Fibonacci Number Series");
  Serial.println("4. Multiplication table");
  Serial.println("5. Surface Area of a cone");
  Serial.println("6. Logo of Louis Vuitton");
  Serial.println("7. Light up LEDs from left to right");
  Serial.println("8. Blink LEDs from the left to center then right to center");
  Serial.println("9. Print error and blink all LED");
  Serial.println("0. Print INVALID CODE!!! \n");
}

void pyramidOfStars() {
  /* Prints a pyramid of * based on the given height */
  // Prompt for the height of the pyramid
  int heightOfPyramid = getInt("Enter the height of asterisks for the pyramid: ");
  Serial.println(heightOfPyramid);

  // Print the pyramid
  for (int i = 0; i < heightOfPyramid; i++) {
    // Print white spaces
    for (int j = 1; j < heightOfPyramid - i; j++) {
      Serial.print(" ");
    }
    // Print asterisks
    for (int j = 0; j <  i + 1; j++) {
      Serial.print("* ");
    }
    Serial.println();
  }
}

void drawSquare() {
  /* Print a square of * based on the given length of a side */
  // Prompt for the side of the square
  int side = getInt("Enter side length for square: ");
  Serial.println(side);
  // Print the top side of the square
  for (int i = 0; i < side; i++) {
    Serial.print("*");
  }
  Serial.println();
  // Print the left and right side of the square
  for (int i = 0; i < side - 2; i++) {
    Serial.print("*");
    // Print the white spaces between the left and right side of the square
    for (int j = 0; j < side - 2; j++) {
      Serial.print(" ");
    }
    Serial.println("*");
  }
  // Print the bottom side of the square
  for (int i = 0; i < side; i++) {
    Serial.print("*");
  }
  Serial.println();
}

void fibonacciSeries() {
  /* Prints Fibonacci Series of up to the given number of terms */
  // Prompt for the number of Fibonnacci terms
  int n = getInt("Enter the number of Fibonacci terms: ");
  Serial.println(n);

  // Print each Fibonnaci term
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
  /* Print the multiplication table with the multiplicant form (1-10) and the multiplier as a user input */
  // Prompt for a number to be used as a multiplier (only 0-10 allowed)
  int num;
  while (true) {
    num = getInt("Enter number for multiplication table: ");
    
    if (num > 10) {
      Serial.println("ERROR: 0-10 only.");
    }
    else {
      Serial.println(num);
      break;
    };
  }

  // Print the multiplication table
  for (int i = 1; i <= 10; i++) {
    Serial.print(num);
    Serial.print(" x ");
    Serial.print(i);
    Serial.print(" = ");
    Serial.println(num * i);
  }
}

void surfaceAreaOfCone() {
  /* Solve the surface area of a cone based on the given radius and height */
  // Prompt for the radius and height of the cone
  float radius = getFloat("Enter radius: ");
  Serial.println(radius);
  float height = getFloat("Enter height: ");
  Serial.println(height);
  // Solve and print the surface area of the cone
  float slantHeight = sqrt(radius * radius + height * height);
  float surfaceArea = PI * radius * (radius + slantHeight);
  Serial.print("Surface Area of Cone: ");
  Serial.println(surfaceArea);
}

void printLogo() {
  /* Print the logo of Louis Vuitton */
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
  /* Light LEDs from left to right for 3 seconds */
  for (int i = 0; i < numLeds; i++) {
    digitalWrite(ledPins[i], HIGH);
    delay(375);  // 3 seconds divided by 8 LEDs
    digitalWrite(ledPins[i], LOW);
  }
}

void blinkLEDs() {
  /* Blinked LEDs from left to center, then right to center */
  // Blink LEDs from left to center
  for (int i = 0; i < 4; i++) {
    digitalWrite(ledPins[i], HIGH);
    delay(500);
    digitalWrite(ledPins[i], LOW);
  }
  delay(500);
  // Blink LEDs from right to center
  for (int i = 7; i > 3; i--) {
    digitalWrite(ledPins[i], HIGH);
    delay(500);
    digitalWrite(ledPins[i], LOW);
  }
}

void errorBlinkLEDs() {
  /* Light all LEDs for 2 seconds and Print 'Error!' */
  Serial.println("Error!");
  for (int i = 0; i < numLeds; i++) digitalWrite(ledPins[i], HIGH);
  delay(2000);
  for (int i = 0; i < numLeds; i++) digitalWrite(ledPins[i], LOW);
}

void askToTryAgain() {
  /* Prompt for a Y or an N, if they want to ask again or exit */
  Serial.println();
  clearSerialBuffer();
  while (true) {
    Serial.print("[Y] : try again \n[N] : exit \nYour Answer: ");
    while (!Serial.available()) {
    }
    String answer = Serial.readStringUntil('\n');
    answer.trim();
    if (answer.equals("Y") || answer.equals("y")) {
      Serial.println(answer);
      displayMenu();
      break;
    }
    else if (answer.equals("N") || answer.equals("n")) {
      Serial.println(answer);
      Serial.println("Goodbye!");
      while (true) {}
    }
    Serial.println();
  }
}

float getFloat(char* message) {
  /* Prompts for a valid positive float */
  clearSerialBuffer();
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

int getInt(char* message) {
  /* Prompts for a valid positive int */
  clearSerialBuffer();
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

    // Ensures input has no non digits
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

    int validInt = input.toInt();
    return validInt;
  }
}

void clearSerialBuffer() {
  /* Clears the serial buffer to prevent preloading previous inputs */
  while (Serial.available() > 0) {
    Serial.read();
  }
}