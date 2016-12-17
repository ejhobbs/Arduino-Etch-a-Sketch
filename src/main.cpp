#include "Arduino.h"
#include "Wire.h"
#include "U8g2lib.h"


#define X_POS A0
#define Y_POS A1
#define CLCK 0
#define DATA 0
#define CS 0
#define DC 0

U8G2_SH1106_128X64_NOANME_1_4W_HW_SPI display(U8G2_R0, CLCK, DATA, CS, DC);


void setup() {
  display.begin();
  pinMode(X_POS, INPUT);
  pinMode(Y_POS, INPUT);
  Serial.begin(9600);
}

void loop() {
  //TODO
}
