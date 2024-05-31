#define REST 0
#define NOTE_B0 31
#define NOTE_C1 33
#define NOTE_CS1 35
#define NOTE_D1 37
#define NOTE_DS1 39
#define NOTE_E1 41
#define NOTE_F1 44
#define NOTE_FS1 46
#define NOTE_G1 49
#define NOTE_GS1 52
#define NOTE_A1 55
#define NOTE_AS1 58
#define NOTE_B1 62
#define NOTE_C2 65
#define NOTE_CS2 69
#define NOTE_D2 73
#define NOTE_DS2 78
#define NOTE_E2 82
#define NOTE_F2 87
#define NOTE_FS2 93
#define NOTE_G2 98
#define NOTE_GS2 104
#define NOTE_A2 110
#define NOTE_AS2 117
#define NOTE_B2 123
#define NOTE_C3 131
#define NOTE_CS3 139
#define NOTE_D3 147
#define NOTE_DS3 156
#define NOTE_E3 165
#define NOTE_F3 175
#define NOTE_FS3 185
#define NOTE_G3 196
#define NOTE_GS3 208
#define NOTE_A3 220
#define NOTE_AS3 233
#define NOTE_B3 247
#define NOTE_C4 262
#define NOTE_CS4 277
#define NOTE_D4 294
#define NOTE_DS4 311
#define NOTE_E4 330
#define NOTE_F4 349
#define NOTE_FS4 370
#define NOTE_G4 392
#define NOTE_GS4 415
#define NOTE_A4 440
#define NOTE_AS4 466
#define NOTE_B4 494
#define NOTE_C5 523
#define NOTE_CS5 554
#define NOTE_D5 587
#define NOTE_DS5 622
#define NOTE_E5 659
#define NOTE_F5 698
#define NOTE_FS5 740
#define NOTE_G5 784
#define NOTE_GS5 831
#define NOTE_A5 880
#define NOTE_AS5 932
#define NOTE_B5 988
#define NOTE_C6 1047
#define NOTE_CS6 1109
#define NOTE_D6 1175
#define NOTE_DS6 1245
#define NOTE_E6 1319
#define NOTE_F6 1397
#define NOTE_FS6 1480
#define NOTE_G6 1568
#define NOTE_GS6 1661
#define NOTE_A6 1760
#define NOTE_AS6 1865
#define NOTE_B6 1976
#define NOTE_C7 2093
#define NOTE_CS7 2217
#define NOTE_D7 2349
#define NOTE_DS7 2489
#define NOTE_E7 2637
#define NOTE_F7 2794
#define NOTE_FS7 2960
#define NOTE_G7 3136
#define NOTE_GS7 3322
#define NOTE_A7 3520
#define NOTE_AS7 3729
#define NOTE_B7 3951
#define NOTE_C8 4186
#define NOTE_CS8 4435
#define NOTE_D8 4699
#define NOTE_DS8 4978

int but1 = 2;
int but2 = 3;
int but3 = 4;
int but4 = 5;
int but5 = 6;
int but6 = 7;
int but7 = 8;
int but8 = 9;

int buzzer = 10;

// Mario Underworld melody
int underworld_melody[] = {
  NOTE_C4, NOTE_C5, NOTE_A3, NOTE_A4,
  NOTE_AS3, NOTE_AS4, 0,
  0,
  NOTE_C4, NOTE_C5, NOTE_A3, NOTE_A4,
  NOTE_AS3, NOTE_AS4, 0,
  0,
  NOTE_F3, NOTE_F4, NOTE_D3, NOTE_D4,
  NOTE_DS3, NOTE_DS4, 0,
  0,
  NOTE_F3, NOTE_F4, NOTE_D3, NOTE_D4,
  NOTE_DS3, NOTE_DS4, 0,
  0, NOTE_DS4, NOTE_CS4, NOTE_D4,
  NOTE_CS4, NOTE_DS4,
  NOTE_DS4, NOTE_GS3,
  NOTE_G3, NOTE_CS4,
  NOTE_C4, NOTE_FS4, NOTE_F4, NOTE_E3, NOTE_AS4, NOTE_A4,
  NOTE_GS4, NOTE_DS4, NOTE_B3,
  NOTE_AS3, NOTE_A3, NOTE_GS3,
  0, 0, 0
};
int underworld_tempo[] = {
  12, 12, 12, 12,
  12, 12, 6,
  3,
  12, 12, 12, 12,
  12, 12, 6,
  3,
  12, 12, 12, 12,
  12, 12, 6,
  3,
  12, 12, 12, 12,
  12, 12, 6,
  6, 18, 18, 18,
  6, 6,
  6, 6,
  6, 6,
  18, 18, 18, 18, 18, 18,
  10, 10, 10,
  10, 10, 10,
  3, 3, 3
};

// Mario Star Theme 2 melody
int star_melody[] = {
  NOTE_F5, NOTE_F5, NOTE_F5, NOTE_D5, NOTE_F5, NOTE_F5, NOTE_D5,NOTE_F5, NOTE_F5,
  NOTE_F5, NOTE_F5, NOTE_F5, NOTE_D5, NOTE_F5, NOTE_F5, NOTE_D5,NOTE_F5, NOTE_F5,
  NOTE_F5, NOTE_F5, NOTE_F5, NOTE_D5, NOTE_F5, NOTE_F5, NOTE_D5,NOTE_F5, NOTE_F5,
  NOTE_F5, NOTE_F5, NOTE_F5, NOTE_D5, NOTE_F5, NOTE_F5, NOTE_D5,NOTE_F5, NOTE_F5,
  NOTE_F5, NOTE_F5, NOTE_F5, NOTE_D5, NOTE_F5, NOTE_F5, NOTE_D5,NOTE_F5, NOTE_F5,
  NOTE_F5, NOTE_F5, NOTE_F5, NOTE_D5, NOTE_F5, NOTE_F5, NOTE_D5,NOTE_F5, NOTE_F5,
  NOTE_F5, NOTE_F5, NOTE_F5, NOTE_D5, NOTE_F5, NOTE_F5, NOTE_D5,NOTE_F5, NOTE_F5,
  NOTE_F5, NOTE_F5, NOTE_F5, NOTE_D5, NOTE_F5, NOTE_F5, NOTE_D5,NOTE_F5, NOTE_F5,
};
int star_tempo[] = {
  4, 4, 4, 8, 4, 4, 8, 4, 4,
  4, 4, 4, 8, 4, 4, 8, 4, 4,
  4, 4, 4, 8, 4, 4, 8, 4, 4,
  4, 4, 4, 8, 4, 4, 8, 4, 4,
  4, 4, 4, 8, 4, 4, 8, 4, 4,
  4, 4, 4, 8, 4, 4, 8, 4, 4,
  4, 4, 4, 8, 4, 4, 8, 4, 4,
  4, 4, 4, 8, 4, 4, 8, 4, 4
};

// Super Mario 2 NES Ending Theme melody
int mario2_ending_melody[] = {
   NOTE_G4, NOTE_C5, NOTE_E5, NOTE_G5, 
  NOTE_E5, NOTE_G5, NOTE_A5, NOTE_B5, 
  NOTE_A5, NOTE_G5, NOTE_E5, NOTE_C5,
  NOTE_D5, NOTE_E5, NOTE_F5, NOTE_G5,
  NOTE_E5, NOTE_F5, NOTE_E5, NOTE_C5,
  NOTE_E5, NOTE_G5, NOTE_B5, NOTE_C6,
  NOTE_B5, NOTE_G5, NOTE_A5, NOTE_G5,
  NOTE_E5, NOTE_C5, NOTE_D5, NOTE_E5,
  NOTE_F5, NOTE_G5, NOTE_E5, NOTE_D5,
  NOTE_C5, 0, NOTE_G4, 0,
  NOTE_G4, NOTE_C5, NOTE_E5, NOTE_G5,
  NOTE_E5, NOTE_G5, NOTE_A5, NOTE_B5,
  NOTE_A5, NOTE_G5, NOTE_E5, NOTE_C5,
  NOTE_D5, NOTE_E5, NOTE_F5, NOTE_G5,
  NOTE_E5, NOTE_F5, NOTE_E5, NOTE_C5,
  NOTE_E5, NOTE_G5, NOTE_B5, NOTE_C6,
  NOTE_B5, NOTE_G5, NOTE_A5, NOTE_G5,
  NOTE_E5, NOTE_C5, NOTE_D5, NOTE_E5,
  NOTE_F5, NOTE_G5, NOTE_E5, NOTE_D5,
  NOTE_C5, 0, NOTE_G4, 0
};
int mario2_ending_tempo[] = {
  8, 8, 8, 8,
  2, 2, 2, 2,
  2, 2, 2, 2,
  2, 2, 2, 2,
  2, 2, 2, 2,
  2, 2, 2, 2,
  2, 2, 2, 2,
  2, 2, 2, 2,
  2, 2, 2, 2,
  1, 1, 2, 1,
  2, 2, 2, 2,
  2, 2, 2, 2,
  2, 2, 2, 2,
  2, 2, 2, 2,
  2, 2, 2, 2,
  2, 2, 2, 2,
  2, 2, 2, 2,
  2, 2, 2, 2,
  2, 2, 2, 2,
  1, 1, 2, 1
};

void playMelody(int melody[], int tempo[], int length, int duration) {
  unsigned long startTime = millis();
  int noteDuration, pauseBetweenNotes;
  for (int i = 0; i < length && (millis() - startTime) < duration; i++) {
    noteDuration = 1000 / tempo[i];
    tone(buzzer, melody[i], noteDuration);
    pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
  }
}

void setup() {
  // Let's declare the button pins as input
  pinMode(but1, INPUT);
  pinMode(but2, INPUT);
  pinMode(but3, INPUT);
  pinMode(but4, INPUT);
  pinMode(but5, INPUT);
  pinMode(but6, INPUT);
  pinMode(but7, INPUT);
  pinMode(but8, INPUT);
  // Declare buzzer pin as output
  pinMode(buzzer, OUTPUT);
}

void loop() {
  // Play Underworld melody for 20 seconds
  playMelody(underworld_melody, underworld_tempo, sizeof(underworld_melody) / sizeof(int), 20000);

  // Play Overworld Theme 2 melody for 20 seconds
  playMelody(star_melody, star_tempo, sizeof(star_melody) / sizeof(int), 20000);

  // Play Super Mario 2 NES Ending Theme for 20 seconds
  playMelody(mario2_ending_melody, mario2_ending_tempo, sizeof(mario2_ending_melody) / sizeof(int), 20000);
}