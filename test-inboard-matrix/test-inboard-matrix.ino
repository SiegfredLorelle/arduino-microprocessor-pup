// To use ArduinoGraphics APIs, please include BEFORE Arduino_LED_Matrix
#include <ArduinoGraphics.h>
#include <Arduino_LED_Matrix.h>

ArduinoLEDMatrix matrix;

void setup() {
  const uint32_t heart[] = {
    0x3184a444,
    0x44042081,
    0x100a0040
  };
  
  Serial.begin(115200);
  matrix.begin();

  matrix.loadFrame(heart);
  delay(3000);
}

void loop() {

  // Make it scroll!
  matrix.beginDraw();

  matrix.stroke(0xFFFFFFFF);
  matrix.textScrollSpeed(40);

  // add the text
  const char text[] = "  Elijah  ";
  matrix.textFont(Font_5x7);
  matrix.beginText(0, 1, 0xFFFFFF);
  matrix.println(text);
  matrix.endText(SCROLL_LEFT);

  matrix.endDraw();
}