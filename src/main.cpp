/*
 * Demo for SSD1306 based 128x64 OLED module using u8glib.
 * See https://github.com/pacodelgado/arduino/wiki/SSD1306-based-OLED-connected-to-Arduino
 * for more information.
 *
 *  ---------------------------------------------------------------------
 * U8glib library copyright notice:
 * Universal 8bit Graphics Library, http://code.google.com/p/u8glib/
 * Copyright (c) 2012, olikraus@gmail.com
 * All rights reserved.
 */
#include <Arduino.h>
#include "U8glib.h"

/* Create an instance for the SSD1306 OLED display in SPI mode
 * connection scheme:
 *   D0=sck=Pin 12
 *   D1=mosi=Pin 11
 *   CS=Pin 8
 *   DC=A0=Pin 9
 *   Reset=Pin 10
 */


U8GLIB_SSD1306_128X64 u8g(12, 11, 8, 9, 10);
const int POT_LEFT = A5;
const int POT_RIGHT = A4;

void draw(void);
int map_input(int, int, int);

void setup()
{
  /* nothing to do here */
}

void loop()
{
  u8g.firstPage();
  do {
    draw();
  } while(u8g.nextPage());
}

void draw(void) {
  int x_pos = map_input(POT_LEFT, 0, 127);
  int y_pos = map_input(POT_RIGHT, 0, 63);
  u8g.drawPixel(x_pos,y_pos);
}

int map_input(int POT, int min, int max){
  return map(analogRead(POT), 0, 1024, min, max);
}
