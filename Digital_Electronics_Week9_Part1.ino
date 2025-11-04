#include "BetterButton.h"

int button1Pin = 32;
int button2Pin = 30;


BetterButton button1(button1Pin, 0);
BetterButton button2(button2Pin, 1);


int midiNotes[4] = { 60, 64, 67, 71};

void setup() {
  Serial.begin(9600);

  button1.pressHandler(onPress);
  button1.releaseHandler(onRelease);
  button2.pressHandler(onPress);
  button2.releaseHandler(onRelease);

}

void loop() {
  button1.process();
  button2.process();

}

void onPress(int val) {
  Serial.print(val);
  Serial.println(" on");
  usbMIDI.sendNoteOn(midiNotes[val], 127, 1);
}

void onRelease(int val) {
  Serial.print(val);
  Serial.println(" off");
  usbMIDI.sendNoteOff(midiNotes[val], 0, 1);
}
