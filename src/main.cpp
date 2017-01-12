#include <Arduino.h>
#include <Wire.h>
#include <SPI.h>
#include "U8g2lib.h"

/* Create an instance for the SSD1306 OLED display in SPI mode
 * connection scheme:
 *   D0=sck=Pin 12
 *   D1=mosi=Pin 11
 *   CS=Pin 8
 *   DC=A0=Pin 9
 *   Reset=Pin 10
 */
U8G2_SH1106_128X64_NONAME_F_4W_SW_SPI u8g2(U8G2_R0, 12, 11, 8, 9, 10);

const int POT_LEFT = A5;
const int POT_RIGHT = A4;

void draw(void);
int map_input(int, int, int);

void setup() {
  u8g2.begin();
}

void loop() {
  draw();
}

void draw(void) {
  int x_pos = map_input(POT_LEFT, 0, 127);
  int y_pos = map_input(POT_RIGHT, 0, 63);
  u8g2.drawPixel(x_pos,y_pos);
  u8g2.sendBuffer();
}

int map_input(int POT, int min, int max) {
  return map(analogRead(POT), 0, 1024, min, max);
}
