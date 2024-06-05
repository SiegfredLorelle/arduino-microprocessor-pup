// include the library code:
#include <LiquidCrystal.h>

// Creates an LCD object. Parameters: (rs, enable, d4, d5, d6, d7)
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);


byte peaceLeft[8] = {
0b00000,
0b00000,
0b00001,
0b00001,
0b00001,
0b00001,
0b00000,
0b00000
};

byte peaceMid[8] = {
0b01110,
0b10101,
0b00100,
0b00100,
0b00100,
0b01010,
0b10001,
0b01110
};

byte peaceRight[8] = {
0b00000,
0b00000,
0b10000,
0b10000,
0b10000,
0b10000,
0b00000,
0b00000
};

  // Define characters for the top and bottom half of the heart
  char topHeart[] = {0, 3, 127, 42, 32, 8, 0};
  char bottomHeart[] = {0, 8, 32, 126, 42, 3, 0};

void setup() 
{
	// set up the LCD's number of columns and rows:
	lcd.begin(16, 2);

	// Clears the LCD screen
	lcd.clear();

  lcd.createChar(0, peaceLeft);
  lcd.createChar(1, peaceMid);
  lcd.createChar(2, peaceRight);
}

void loop() 
{
	// Print a message to the LCD.
  lcd.setCursor(0, 0);
  lcd.write(byte(0));
  lcd.write(byte(1));
  lcd.write(byte(2));

  lcd.setCursor(5, 0);
	lcd.print("TEST1");

	// set the cursor to column 0, line 1
	// (note: line 1 is the second row, since counting begins with 0):
	lcd.setCursor(3, 1);
	// Print a message to the LCD.
	lcd.print("LCD Testing");
}