void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop() {
  digitalWrite(13, HIGH);
  Serial.println("Hello World!");
  delay(3000);
  digitalWrite(13, LOW); 
  delay(3000);
}
