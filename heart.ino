/*
 Qduino Mini Heart Project

 Simple 3D printed heart and Qduino combo
 that pulses.

 Forked from the Arduino example - Fade
 */

#include "Qduino.h"
#include "Wire.h"

int led = 10;           // the pin that the LED is attached to
int brightness = 0;    // how bright the LED is
int fadeAmount = 5;    // how many points to fade the LED by

qduino q;

// the setup routine runs once when you press reset:
void setup() {
  // declare pin 10 to be an output:
  pinMode(led, OUTPUT);
  q.setup();
}

// the loop routine runs over and over again forever:
void loop() {
  // set the brightness of pin 10:
  analogWrite(10, brightness);

  // change the brightness for next time through the loop:
  brightness = brightness + fadeAmount;

  // reverse the direction of the fading at the ends of the fade:
  if (brightness == 0 || brightness == 255) {
    fadeAmount = -fadeAmount ;
  }
  // wait for 30 milliseconds to see the dimming effect
  delay(20);
}

