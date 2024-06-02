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
int undergroundNotes[] = {
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
int undergroundTempos[] = {
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
int undergroundBaseTempo = 198;
int undergroundSize = sizeof(undergroundNotes) / sizeof(undergroundNotes[0]);


// Super Mario Bros 2 (NES) Music - Overworld Theme
int bros2OverworldNotes[] = {
  NOTE_G5, REST, NOTE_C5, NOTE_E5, REST, NOTE_G5, 
  NOTE_G5, NOTE_C5, NOTE_E5, REST, NOTE_G5,

  NOTE_B4, NOTE_DS5, NOTE_G5, NOTE_B5, REST, 
  
  NOTE_A5, NOTE_A5, REST,

  NOTE_G5, REST, NOTE_AS4, NOTE_D5, REST, NOTE_G5, 
  NOTE_G5, NOTE_AS4, NOTE_D5, REST, NOTE_G5,
  
  NOTE_CS5, NOTE_E5, NOTE_G5, NOTE_B5, REST, 
  
  NOTE_A5, NOTE_A5, NOTE_A5,

  NOTE_C6, REST, NOTE_B5, NOTE_C6, REST, NOTE_A5, 
  NOTE_A5, NOTE_C6, NOTE_B5, REST, NOTE_A5,

  NOTE_G5, REST, NOTE_FS5, NOTE_G5, REST, NOTE_E5, 
  NOTE_E5, NOTE_CS5, NOTE_D5, REST, 

  NOTE_E5, NOTE_F5, REST, NOTE_E5, NOTE_F5, REST, 
  
  NOTE_B4, NOTE_B4, NOTE_E5, NOTE_D5, REST, 
  NOTE_C4, NOTE_C4, NOTE_C4, REST,
};
int bros2OverworldTempos[] = {
  8, 8, 8, 8, 8, 4, 
  8, 8, 8, 8, 8, 

  8, 8, 8, 8, 8, 

  2, 4, 8,

  8, 8, 8, 8, 8, 4,
  8, 8, 8, 8, 8,

  8, 8, 8, 8, 8, 

  2, 4, 8,

  8, 8, 8, 8, 8, 4, 
  8, 8, 8, 8, 8,

  8, 8, 8, 8, 8, 4, 
  8, 8, 8, 8, 

  8, 8, 8, 8, 8, 8, 

  4, 8, 8, 8, 8, 
  4, 4, 4, 8, 
};
int bros2OverworldBaseTempo = 300;
int bros2OverworldSize = sizeof(bros2OverworldNotes) / sizeof(bros2OverworldNotes[0]);



// Super Mario Bros (NES) Music - Ending Theme
int endingNotes[] = {
  NOTE_C5, NOTE_E5, NOTE_E5, NOTE_D5,
  NOTE_E5, NOTE_F5, NOTE_A4,
  NOTE_D5, REST, NOTE_C5,
  NOTE_E4, NOTE_FS4, NOTE_E4,
  NOTE_E4, NOTE_E4, REST, NOTE_C4,
  NOTE_FS4, NOTE_G4, NOTE_G4, REST
};
int endingTempos[] = {
  4, 8, 8, 4,
  4, 4, 4,
  4, 8, 4,
  12, 12, 12,
  4, 8, 8, 4,
  4, 4, 8, 8
};
int endingBaseTempo = 154;
int endingSize = sizeof(endingNotes) / sizeof(endingNotes[0]);



// Super Mario Bros (NES) Music - Underwater Theme
int underwaterNotes[] = {
  NOTE_D4, NOTE_E4, NOTE_FS4, NOTE_G4, NOTE_A4, NOTE_AS4,
  NOTE_B4, NOTE_B4, NOTE_B4, REST, NOTE_B4, REST,
  NOTE_B4, NOTE_G4, NOTE_E5, REST,
  NOTE_DS5, REST, NOTE_E5, REST,
  REST, NOTE_G4, NOTE_A4, NOTE_B4, NOTE_C5, NOTE_D5,
  NOTE_E5, REST, NOTE_DS5, NOTE_F5,
  NOTE_E5, REST, REST, REST, NOTE_G4,
  NOTE_D5, REST, NOTE_CS5, REST,
  NOTE_D5, REST,
  REST, NOTE_G4, NOTE_A4, NOTE_B4, NOTE_C5, NOTE_CS5,
  NOTE_D5, REST, NOTE_G4, NOTE_F5,
  NOTE_E5, REST, REST, REST, NOTE_G4,
  NOTE_G5, NOTE_G5, REST,
  NOTE_G5, NOTE_G5, REST,
  NOTE_G5, NOTE_G5, REST,
  NOTE_G5, NOTE_A5, REST, NOTE_G5,
  NOTE_F5, NOTE_F5, REST,
  NOTE_F5, NOTE_F5, REST,
  NOTE_F5, NOTE_F5, REST,
  NOTE_F5, NOTE_G5, REST, NOTE_F5,
  NOTE_E5, NOTE_E5, REST,
  NOTE_A4, NOTE_B4, NOTE_F5,
  NOTE_E5, NOTE_E5, NOTE_E5, NOTE_E5, NOTE_B4,
  NOTE_C5, NOTE_C5, REST
};
int underwaterTempos[] = {
  4, 4, 4, 4, 4, 4,
  8, 8, 8, 8, 8, 8,
  2, 4, 2, 4,
  2, 4, 2, 4,
  8, 8, 8, 8, 8, 8,
  2, 4, 2, 4,
  2, 4, 2, 8, 8,
  2, 4, 2, 4,
  2, 4,
  8, 8, 8, 8, 8, 8,
  2, 4, 2, 4,
  2, 4, 2, 8, 8,
  2, 8, 8,
  2, 8, 8,
  2, 8, 8,
  4, 4, 8, 8,
  2, 8, 8,
  2, 8, 8,
  2, 8, 8,
  4, 4, 8, 8,
  2, 8, 8,
  4, 4, 4,
  8, 8, 4, 8, 8,
  2, 4, 4,
};
int underwaterBaseTempo = 227;
int underwaterSize = sizeof(underwaterNotes) / sizeof(underwaterNotes[0]);



// Super Mario World - Overworld Theme Music
int partyOSTNotes[] = {
  NOTE_A4, NOTE_F4,
  NOTE_C4, NOTE_D4, 
  NOTE_F4, NOTE_F4,
  NOTE_D4, NOTE_C4,
  NOTE_F4, NOTE_F4, NOTE_C5,
  NOTE_A4, NOTE_A4, NOTE_G4, NOTE_G4,
  REST, NOTE_C4, NOTE_A4,
  NOTE_F4, NOTE_F4, NOTE_C4, NOTE_D4,
  NOTE_F4, NOTE_F4, NOTE_D4,
  NOTE_C4, NOTE_F4, 
  NOTE_AS4, NOTE_A4, NOTE_G4,
  NOTE_F4, REST,
};
int partyOSTTempos[] = {
  2, 2,
  8, 8,
  4, 2,
  8, 4,
  4, 4, 4,
  4, 8, 8, 4,
  8, 8, 2,
  4, 8, 8, 8,
  4, 2, 8,
  4, 4,
  8, 8, 8, 
  2, 2,
};
int partyOSTBaseTempo = 240;
int partyOSTSize = sizeof(partyOSTNotes) / sizeof(partyOSTNotes[0]);

// Super Mario Party OST - Main Theme
int worldOverworldNotes[] = {
  NOTE_A4, NOTE_F4,
  NOTE_C4, NOTE_D4, 
  NOTE_F4, NOTE_F4,
  NOTE_D4, NOTE_C4,
  NOTE_F4, NOTE_F4, NOTE_C5,
  NOTE_A4, NOTE_A4, NOTE_G4, NOTE_G4,
  REST, NOTE_C4, NOTE_A4,
  NOTE_F4, NOTE_F4, NOTE_C4, NOTE_D4,
  NOTE_F4, NOTE_F4, NOTE_D4,
  NOTE_C4, NOTE_F4, 
  NOTE_AS4, NOTE_A4, NOTE_G4,
  NOTE_F4, REST,
};
int worldOverworldTempos[] = {
  2, 2,
  8, 8,
  4, 2,
  8, 4,
  4, 4, 4,
  4, 8, 8, 4,
  8, 8, 2,
  4, 8, 8, 8,
  4, 2, 8,
  4, 4,
  8, 8, 8, 
  2, 2,
};
int worldOverworldBaseTempo = 240;
int worldOverworldSize = sizeof(worldOverworldNotes) / sizeof(worldOverworldNotes[0]);

void playMelody(int notes[], int tempos[], int baseTempo, int size, int repeat=1) {
  for (repeat; repeat > 0; repeat--) {
    for (int i = 0; i < size; i++) {
    int noteDuration = (60000 * 4 / baseTempo) / tempos[i];
    tone(buzzer, notes[i], noteDuration);
    delay(noteDuration * 1.025);
    noTone(buzzer);
    }
  }
  delay(1000);
}

void setup() {
  Serial.begin(9600);
  // Declare buzzer pin as output
  pinMode(buzzer, OUTPUT);

  Serial.println("Playing Super Mario World - Overworld Theme Music ...");
  playMelody(worldOverworldNotes, worldOverworldTempos, worldOverworldBaseTempo, worldOverworldSize);
  Serial.println("Playing Super Mario Bros 2 (NES) Music - Overworld Theme ...");
  playMelody(bros2OverworldNotes, bros2OverworldTempos, bros2OverworldBaseTempo, bros2OverworldSize);
  Serial.println("Playing Super Mario Bros - Underground Theme ...");
  playMelody(undergroundNotes, undergroundTempos, undergroundBaseTempo, undergroundSize);
  Serial.println("Playing Super Mario Bros 2 (NES) Music - Ending Theme ...");
  playMelody(endingNotes, endingTempos, endingBaseTempo, endingSize, 2);
  Serial.println("Playing Super Mario Bros (NES) Music - Underwater Theme ...");
  playMelody(underwaterNotes, underwaterTempos, underwaterBaseTempo, underwaterSize);
  Serial.println("DONE PLAYING");
}

void loop() {
}