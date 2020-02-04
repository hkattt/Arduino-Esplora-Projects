#include <Arduino.h>
#include <Esplora.h>

int notes[12] = {262, 277, 294, 311, 330, 349, 370, 392, 415, 440, 466, 494};

void setup() {}

void loop() {
  int slider = Esplora.readSlider();
  int index = map(slider,0, 1023, 11, 0);
  
  if (Esplora.readButton(1) == PRESSED) {
    Esplora.tone(notes[index]);
  }
  else if (Esplora.readButton(2) == PRESSED) {
    Esplora.tone(notes[index] * 2);
  }
  else {
    Esplora.noTone();
  } 
}