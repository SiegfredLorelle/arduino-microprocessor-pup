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

byte heartLeft[8] = {
  0b00110,
  0b01111,
  0b11111,
  0b11111,
  0b01111,
  0b00111,
  0b00011,
  0b00001
};

byte heartRight[8] = {
  0b01100,
  0b11110,
  0b11111,
  0b11111,
  0b11110,
  0b11100,
  0b11000,
  0b10000
};

byte codeLeft[8] = {
  0b00010,
  0b00100,
  0b01000,
  0b10000,
  0b01000,
  0b00100,
  0b00010,
  0b00000
};

void setup() 
{
	// set up the LCD's number of columns and rows:
	lcd.begin(16, 2);

	// Clears the LCD screen
	lcd.clear();

  lcd.createChar(0, peaceLeft);
  lcd.createChar(1, peaceMid);
  lcd.createChar(2, peaceRight);
  lcd.createChar(3, heartLeft);
  lcd.createChar(4, heartRight);

  lcd.setCursor(1, 0);
  lcd.write(byte(0));
  lcd.write(byte(1));
  lcd.write(byte(2));


  lcd.setCursor(7, 0);
	lcd.write(byte(3));
	lcd.write(byte(4));

  lcd.setCursor(0, 1);
  lcd.print("Peace Love Code");
}


void loop() 
{

}