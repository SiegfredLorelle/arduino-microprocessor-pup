#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

const int ldrLeft = A1; // Left LDR analog pin
const int ldrRight = A0; // Right LDR analog pin
int leftThreshold = 20; // Adjust threshold based on your LDR sensitivity
int rightThreshold = 100; // Adjust threshold based on your LDR sensitivity

String welcomeMessage = "WELCOME TO THE PUP-CPE DEPARTMENT";  // Message for left LDR
String byeMessage = "GOODBYE, SEE YOU AGAIN NEXT TIME!!!!"; // Message for right LDR


void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  pinMode(ldrLeft, INPUT);
  pinMode(ldrRight, INPUT);
}

void loop() {
  lcd.clear();

  int leftValue = analogRead(ldrLeft);
  int rightValue = analogRead(ldrRight);

  Serial.print("Left:");
  Serial.print(leftValue);
  Serial.print("  Right:");
  Serial.println(rightValue);

  bool leftHasLight = leftValue > leftThreshold;
  bool rightHasLight = rightValue > rightThreshold;

  if (leftHasLight == rightHasLight) {
    return;
  }
  if (leftHasLight && !rightHasLight) {
     displayMarqueeToRight(welcomeMessage);
  } 

  else if (!leftHasLight && rightHasLight) {
    displayMarqueeToRight(byeMessage);
  }
}

void displayMarqueeToLeft(String message) {
  lcd.clear();
  String newMessage = "                " + message + "  ";
  int start = 0;
  int end = 17;

  while (start < newMessage.length()) {
    lcd.setCursor(0, 0);
    Serial.println(newMessage.substring(start, end));
    lcd.print(newMessage.substring(start, end));

    if (end < newMessage.length() - 1) {
      end++;
    };
    start++;
    delay(250);
  }
}

void displayMarqueeToRight(String message) {
  lcd.clear();
  String newMessage =  "               " + message + "                  ";
  int start = newMessage.length() - 17;
  int end = newMessage.length() - 1;

  while (start >= 0) {
    lcd.setCursor(0, 0);
    Serial.println(newMessage.substring(start, end));
    lcd.print(newMessage.substring(start, end));

    if (end > 0) {
      end--;
    };
    start--;
    delay(250);
  }
}

// Detect for change in LDR
