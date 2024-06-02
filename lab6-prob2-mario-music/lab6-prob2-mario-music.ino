#define REST 0
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

int buzzer = 10;

// Super Mario Bros - Underground Theme
int underworldNotes[] = {
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
int underworldTempos[] = {
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
int underworldBaseTempo = 198;
int underworldSize = sizeof(underworldNotes) / sizeof(underworldNotes[0]);


// Super Mario Bros 2 - Overworld Theme
int overworld_melody[] = {
  NOTE_G5, REST, NOTE_C5, NOTE_E5, REST, NOTE_G5, NOTE_G5, NOTE_G5, NOTE_C5, NOTE_E5, REST, NOTE_G5,
};
int overworld_tempo[] = {
  10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10,
};
int overworld_size = sizeof(overworld_melody) / sizeof(overworld_melody[0]);

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

void playMelody(int notes[], int tempos[], int baseTempo, int size) {
  // int noteDuration, pauseBetweenNotes;
  for (int i = 0; i < size; i++) {
  //   noteDuration = 1000 / tempo[i];
  //   tone(buzzer, notes[i], noteDuration);
  //   pauseBetweenNotes = noteDuration * 1.30;
  //   delay(pauseBetweenNotes);
  // }
  // noTone(buzzer);
  // delay(1000);

  // int baseTempo = 198;
  int noteDuration = (60000 * 4 / baseTempo) / tempos[i]; // Calculate duration in milliseconds
  tone(buzzer, notes[i], noteDuration);
  delay(noteDuration * 1.05); // Add a slight pause between notes
  noTone(buzzer);
  }
}

void setup() {
  Serial.begin(9600);
  // Declare buzzer pin as output
  pinMode(buzzer, OUTPUT);

  // Play Super Mario Bros - Underground Theme
  Serial.println("Playing Underworld Theme ...");
  playMelody(underworldNotes, underworldTempos, underworldBaseTempo, underworldSize);
  // Play Super Mario Bros 2 - Overworld Theme
  // Serial.println("Playing Underworld Theme ...");
  // playMelody(overworld_melody, overworld_tempo, overworld_size);



  // Play Overworld Theme 2 melody for 20 seconds
  // Serial.println("Playing Overworld Theme ...");
  // playMelody(star_melody, star_tempo, sizeof(star_melody) / sizeof(int));
  // // Play Super Mario 2 NES Ending Theme for 20 seconds
  // Serial.println("Playing Super Mario 2 NES Ending Theme ...");
  // playMelody(mario2_ending_melody, mario2_ending_tempo, sizeof(mario2_ending_melody) / sizeof(int));
  Serial.println("DONE PLAYING");
}

void loop() {
  // int baseTempo = 200;
  // int noteDuration = (60000 * 4 / baseTempo[i]) / underworld_tempo[i]; // Calculate duration in milliseconds
  // tone(speakerPin, underworld_melody, noteDuration);
  // delay(noteDuration * 1.1); // Add a slight pause between notes
  // noTone(buzzer);
}
// }