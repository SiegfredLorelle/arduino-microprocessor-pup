#include <Keypad.h>

// Constants
const byte rows = 4;
const byte cols = 3;

// Keypad setup
char keys[rows][cols] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};

byte rowPins[rows] = {13, 12, 11, 10};
byte colPins[cols] = {9, 8, 7}; 

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
  Serial.println("0. Display INVALID CODE!!! \n");
}

void pyramidOfStars() {

    int heightOfPyramid = getInt("Enter the height of asterisks for the pyramid: ");
    Serial.println(heightOfPyramid);


  // Print the centered pyramid
  for (int i = 0; i < heightOfPyramid; i++) {
    // Print spaces (centered)
    for (int j = 1; j < heightOfPyramid - i; j++) {
      Serial.print(" ");
    }
    // Print asterisks
    for (int j = 0; j <  i + 1; j++) {
      Serial.print("* ");
    }
    Serial.println(); // Move to the next line
  }
}

void drawSquare() {
  int side = getInt("Enter side length for square:");
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
  int n = getInt("Enter the number of Fibonacci terms:");
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
  int num = getInt("Enter number for multiplication table: ");
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
    Serial.println();

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
  while (Serial.available() > 0) {
    Serial.read();
  }
}