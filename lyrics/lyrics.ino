#include "LiquidCrystal.h"
#include "pitches.h"

#define BUZZER_PIN 2

struct Note {
  int pitch;
  int duration;
  char* text;
};

// notes in the melody:
struct Note melody[] = {
  {NOTE_AS5, 500, "H-"}, {NOTE_CS6, 500, "H-O-"}, {NOTE_CS6, 500, "H-O-T-"}, {NOTE_CS6, 500, "H-O-T-T-"}, {NOTE_DS6, 750, "H-O-T-T-O-"}, {NOTE_CS6, 250, "H-O-T-T-O-G-"}, {NOTE_DS6, 250, "H-O-T-T-O-G-O"}, {NOTE_CS6, 250},
  {-1, 500, ""},
  {NOTE_AS5, 500, "You"}, {NOTE_CS6, 500, "You can"}, {NOTE_FS6, 500, "You can take"}, {NOTE_GS6, 500, "You can take me"}, {NOTE_GS6, 750, "HOT"}, {NOTE_AS6, 250, "HOT-TO"}, {NOTE_GS6, 250, "HOT-TO-GO"}, {NOTE_FS6, 250, "HOT-TO-GO!"},
  {-1, 500, ""}
};
int melodyLen = 18;

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

void setup() {
 lcd.begin(16, 2);
}
 
void loop() {  
  for (int thisNote = 0; thisNote < melodyLen; thisNote++) {
    
    Note note = melody[thisNote];

    if (note.pitch != -1) {
      tone(BUZZER_PIN, note.pitch, note.duration - 50);
    }

    if (note.text != NULL) {
      lcd.setCursor(0, 0);
      lcd.clear();
      lcd.print(note.text);
    }
    
    delay(note.duration);
  }
}
