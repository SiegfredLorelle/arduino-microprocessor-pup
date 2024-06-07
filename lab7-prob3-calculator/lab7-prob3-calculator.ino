#include <LiquidCrystal.h>
#include <Keypad.h>

LiquidCrystal lcd(7, 6, 5, 4, 3, 2);


const byte rows = 4;
const byte cols = 4;

// Keypad values
char keys[rows][cols] = {
  {'1','2','3', '+'},
  {'4','5','6', '-'},
  {'7','8','9', '*'},
  {'C','0','=', '/'}
};

// Keypad pins
byte rowPins[rows] = {A5, A4, A3, A2};
byte colPins[cols] = {13, 12, 11, 10}; 

// Map keypad with its pins
Keypad keypad = Keypad(
  makeKeymap(keys), 
  rowPins, 
  colPins, 
  rows, 
  cols
);

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);

}

void loop() {
  // Execute command based on entered key
  menu();
  calculator();
  
}

void menu() {
  int numOfLines = 5;
  String lines[numOfLines] = {
    "Calculator:   ",
    "[A] +    [B] -",
    "[C] x    [D] /",
    "[*] C    [#] =",
    "              ",
  };

  int row1 = 0;
  int row2 = 1;
  while (true) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(lines[row1]);
    lcd.setCursor(0, 1);
    lcd.print(lines[row2]);

    for (int i = 0; i < 20; i++) {
      if (keypad.getKey()) {
        lcd.clear();
        return;
      };
      delay(100);
    }

    if (row2 < numOfLines - 1) row2++;
    if (row1 >= numOfLines - 2) {
      row1 = 0;
      row2 = 1;
    }
    else row1++;
  }
}


char currOperator = ' ';
int currRow = 0;
void calculator() {
    String strNum1;
    String strNum2;

  while (true) {
    strNum1 = getDigit();
    int num1 = strNum1.toInt();
    Serial.println(num1);
    Serial.println(currOperator);
    
    processOperation();
    // Display operator

    // Get 2nd num
    

  }
}

String getDigit() {
  String strDigit = "";
  while (true) {
    char key = keypad.getKey();

    if (isDigit(key)) {
      if (strDigit.length() == 15) continue;
      strDigit += key;
      Serial.println(strDigit);
      displayDigit(currRow, strDigit);
    }
    else if (key == 'C') {
      strDigit = "";
      displayDigit(currRow, strDigit);
    }
    else if (key && strDigit.length() > 0) {
      currOperator = key;
      return strDigit;
    }
  }
}

void displayDigit(int row, String strDigit) {
  lcd.setCursor(1, row);
  lcd.print("               ");
  lcd.setCursor(16 - strDigit.length(), row);
  lcd.print(strDigit);
}

void displayOperator(char currOperator) {
    lcd.setCursor(0, 1);
    lcd.print(currOperator);
}

void processOperation() {
    if (currOperator != '=') {
      displayOperator(currOperator);
    }
}
// Handle edge cases