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

    for (int i = 0; i < 15; i++) {
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
char pendingOperator = ' ';
int currRow = 0;
void calculator() {
    String strNums[2] = {
      "",
      "",
    };

  while (true) {
    strNums[currRow] = getDigit();
    // strNums1;
    Serial.println(strNums[currRow]);
    Serial.println(currOperator);
    
    String result = processOperation(strNums[0], strNums[1]);
    strNums[0] = result;
    strNums[1] = "";
    displayDigit(0, strNums[0]);
    displayDigit(1, strNums[1]);
    currRow = 1;
  }
}

String getDigit() {
  String strDigit = "";
  while (true) {
    char key = keypad.getKey();

    if (!key) continue;
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
    else {
      if (key != '=') {
        displayOperator(key);
        pendingOperator = key;
        if (currOperator == ' ') currOperator = key;
      }
      if (strDigit.length() > 0) {

        return trimDigit(strDigit);
      }
      else currOperator = key;
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

String processOperation(String strNum1, String strNum2) {
    if (strNum1.length() == 0 || strNum2.length() == 0) return strNum1;

    float num1 = strNum1.toFloat(); 
    float num2 = strNum2.toFloat(); 
    float res;

    if (currOperator == '+') {
      res = num1 + num2;
    }
    else if (currOperator == '-') {
      res = num1 - num2;
    }
    else if (currOperator == '*') {
      res = num1 * num2;
    }
    else if (currOperator == '/') {
      res = num1 / num2;
    }

    Serial.println(res);
    currOperator = pendingOperator;
    // serial.println(currOperator);
    
    if (isnan(res) || isinf(res)) res = 0;
    Serial.print("RESULT: ");
    return trimDigit(String(res));
}

String trimDigit(String digit) {
  String newDigitStart = "";
  String newDigitEnd = "";
  int start = 0;
  int end = digit.length() - 1;

  while (start < digit.length() - 1) {
    if (digit[start] == '0') start++;
    else break;
  }

  if (digit[digit.length() - 3] == '.') {
    while (end >= 0) {
      if (digit[end] == '0') end--;
      else break;
    }
  }


  String newDigit = digit.substring(start, end + 1);
  if (newDigit[0] == '.') {
    newDigit = "0" + newDigit;
  }
  if (newDigit[newDigit.length() - 1] == '.') {
    newDigit.remove(newDigit.length() - 1);
  }

  return newDigit;

}

// Handle edge cases
// Clear all
// Remove negative if res = 0
// Limit result