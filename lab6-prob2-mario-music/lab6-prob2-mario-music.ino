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

int buzzer = 10;

// Mario Underworld melody
int underworld_melody[] = {
  NOTE_C4, NOTE_C5, NOTE_A3, NOTE_A4, NOTE_AS3, NOTE_AS4,
  REST, REST, REST,
  NOTE_C4, NOTE_C5, NOTE_A3, NOTE_A4, NOTE_AS3, NOTE_AS4,
  REST, REST, REST,

  NOTE_F3, NOTE_F4, NOTE_D3, NOTE_D4, NOTE_DS3, NOTE_DS4,
  REST, REST, REST,
  NOTE_F3, NOTE_F4, NOTE_D3, NOTE_D4, NOTE_DS3, NOTE_DS4,

  REST, REST, NOTE_DS4, NOTE_D4, NOTE_CS4,

  NOTE_C4, REST, NOTE_DS4, REST, NOTE_D4, REST,
  NOTE_GS3, REST, NOTE_G3, REST, NOTE_CS4, REST,

  NOTE_C4, NOTE_FS4, NOTE_F4, NOTE_E4, NOTE_AS4, NOTE_A4, NOTE_GS4, NOTE_DS4,
  REST, NOTE_B3, REST, NOTE_AS3, NOTE_A3, REST, NOTE_GS3, REST,
};
int underworld_tempo[] = {
  8, 8, 8, 8, 8, 8,
  4, 4, 4,
  8, 8, 8, 8, 8, 8,
  4, 4, 4,

  8, 8, 8, 8, 8, 8,
  4, 4, 4,
  8, 8, 8, 8, 8, 8,

  4, 4, 16, 16, 8,

  8, 8, 8, 8, 8, 8,
  8, 8, 8, 8, 8, 8,

  16, 16, 8, 16, 16, 8, 8, 8,
  16, 8, 16, 8, 8, 16, 8, 16,
};
int underworld_size = sizeof(underworld_melody) / sizeof(underworld_melody[0]);

// Mario Star Theme 2 melody
int star_melody[] = {
  NOTE_F5,
  NOTE_F5,
  NOTE_F5,
  NOTE_D5,
  NOTE_F5,
  NOTE_F5,
  NOTE_D5,
  NOTE_F5,
  NOTE_F5,
  NOTE_F5,
  NOTE_F5,
  NOTE_F5,
  NOTE_D5,
  NOTE_F5,
  NOTE_F5,
  NOTE_D5,
  NOTE_F5,
  NOTE_F5,
  NOTE_F5,
  NOTE_F5,
  NOTE_F5,
  NOTE_D5,
  NOTE_F5,
  NOTE_F5,
  NOTE_D5,
  NOTE_F5,
  NOTE_F5,
  NOTE_F5,
  NOTE_F5,
  NOTE_F5,
  NOTE_D5,
  NOTE_F5,
  NOTE_F5,
  NOTE_D5,
  NOTE_F5,
  NOTE_F5,
  NOTE_F5,
  NOTE_F5,
  NOTE_F5,
  NOTE_D5,
  NOTE_F5,
  NOTE_F5,
  NOTE_D5,
  NOTE_F5,
  NOTE_F5,
  NOTE_F5,
  NOTE_F5,
  NOTE_F5,
  NOTE_D5,
  NOTE_F5,
  NOTE_F5,
  NOTE_D5,
  NOTE_F5,
  NOTE_F5,
  NOTE_F5,
  NOTE_F5,
  NOTE_F5,
  NOTE_D5,
  NOTE_F5,
  NOTE_F5,
  NOTE_D5,
  NOTE_F5,
  NOTE_F5,
  NOTE_F5,
  NOTE_F5,
  NOTE_F5,
  NOTE_D5,
  NOTE_F5,
  NOTE_F5,
  NOTE_D5,
  NOTE_F5,
  NOTE_F5,
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

void playMelody(int melody[], int tempo[], int size) {
  int noteDuration, pauseBetweenNotes;
  for (int i = 0; i < size; i++) {
    noteDuration = 1000 / tempo[i];
    tone(buzzer, melody[i], noteDuration);
    pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
  }
  noTone(buzzer);
  delay(1000);
}

void setup() {
  Serial.begin(9600);
  // Declare buzzer pin as output
  pinMode(buzzer, OUTPUT);

  // Play Underworld melody for 20 seconds
  Serial.println("Playing Underworld Theme ...");
  playMelody(underworld_melody, underworld_tempo, underworld_size);
  // Play Overworld Theme 2 melody for 20 seconds
  Serial.println("Playing Overworld Theme ...");
  playMelody(star_melody, star_tempo, sizeof(star_melody) / sizeof(int));
  // Play Super Mario 2 NES Ending Theme for 20 seconds
  Serial.println("Playing Super Mario 2 NES Ending Theme ...");
  playMelody(mario2_ending_melody, mario2_ending_tempo, sizeof(mario2_ending_melody) / sizeof(int));
  Serial.println("DONE PLAYING");
}

void loop() {
}