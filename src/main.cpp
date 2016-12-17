#include "Arduino.h"
#include "Wire.h"
#include "SPI.h"
#include "Adafruit_GFX.h"
#include "Adafruit_SSD1306.h"

const int X_POS = A0;
const int Y_POS = A1;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  Serial.begin(9600);
}

void loop() {
  int pos = analogRead(A1);
  Serial.println(pos);
}
