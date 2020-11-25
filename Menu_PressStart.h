#ifndef MENU_START_H
#define MENU_START_H

#include <Arduino.h>
#include "Menu.h"

const unsigned char PROGMEM wxlogo_bmp [] = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x80, 0x00, 0x00, 0x07,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xFC, 0x00, 0x00, 0xFE,
  0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0x00, 0x00, 0x00, 0x78, 0x00, 0x03, 0xFF, 0x00, 0x0F, 0xFC,
  0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0x00, 0x00, 0x00, 0x78, 0x00, 0x01, 0xFF, 0x80, 0x3F, 0xF8,
  0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0x00, 0x00, 0x00, 0x78, 0x00, 0x00, 0xFF, 0xC0, 0x7F, 0xF0,
  0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0x00, 0x00, 0x00, 0x78, 0x00, 0x00, 0x7F, 0xE0, 0x7F, 0xE0,
  0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0x00, 0x00, 0x00, 0x78, 0x00, 0x00, 0x3F, 0xE0, 0xFF, 0xC0,
  0xF1, 0xE3, 0xC3, 0xFF, 0xF8, 0xFF, 0xE1, 0xFF, 0xF8, 0x7F, 0xFF, 0x00, 0x3F, 0xF1, 0xFF, 0x80,
  0xF1, 0xE3, 0xC3, 0xFF, 0xF8, 0xFF, 0xE1, 0xFF, 0xF8, 0x7F, 0xFF, 0x00, 0x1F, 0xF9, 0xFF, 0x00,
  0xF1, 0xE3, 0xC3, 0xFF, 0xF8, 0xFF, 0xE1, 0xFF, 0xF8, 0x7F, 0xFF, 0x00, 0x0F, 0xFF, 0xFE, 0x00,
  0xF1, 0xE3, 0xC3, 0xFF, 0xF8, 0xFF, 0xE1, 0xFF, 0xF8, 0x7F, 0xFF, 0x00, 0x07, 0xEF, 0xFC, 0x00,
  0xF1, 0xE3, 0xC0, 0x00, 0x78, 0xF0, 0x01, 0xE0, 0x00, 0x78, 0x0F, 0x00, 0x03, 0xEF, 0xF8, 0x00,
  0xF1, 0xE3, 0xC0, 0x00, 0x78, 0xF0, 0x01, 0xE0, 0x00, 0x78, 0x0F, 0x00, 0x01, 0xDF, 0xF0, 0x00,
  0xF1, 0xE3, 0xC3, 0xFF, 0xF8, 0xF0, 0x01, 0xE0, 0x00, 0x78, 0x0F, 0x00, 0x00, 0xBF, 0xE0, 0x00,
  0xF1, 0xE3, 0xC3, 0xFF, 0xF8, 0xF0, 0x01, 0xE0, 0x00, 0x78, 0x0F, 0x00, 0x00, 0x7F, 0xD0, 0x00,
  0xF1, 0xE3, 0xC3, 0xFF, 0xF8, 0xF0, 0x01, 0xE0, 0x00, 0x78, 0x0F, 0x00, 0x00, 0xFF, 0xB0, 0x00,
  0xF1, 0xE3, 0xC3, 0xC0, 0x78, 0xF0, 0x01, 0xE0, 0x00, 0x78, 0x0F, 0x00, 0x01, 0xFF, 0x70, 0x00,
  0xF1, 0xE3, 0xC3, 0xC0, 0x78, 0xF0, 0x01, 0xE0, 0x00, 0x78, 0x0F, 0x00, 0x03, 0xFE, 0xF8, 0x00,
  0xFF, 0xFF, 0xC3, 0xFF, 0xF8, 0xFF, 0xE1, 0xFF, 0xF8, 0x78, 0x0F, 0x00, 0x07, 0xFE, 0xFC, 0x00,
  0xFF, 0xFF, 0xC3, 0xFF, 0xF8, 0xFF, 0xE1, 0xFF, 0xF8, 0x78, 0x0F, 0x00, 0x0F, 0xFF, 0xFE, 0x00,
  0xFF, 0xFF, 0xC3, 0xFF, 0xF8, 0xFF, 0xE1, 0xFF, 0xF8, 0x78, 0x0F, 0x00, 0x1F, 0xF9, 0xFF, 0x00,
  0xFF, 0xFF, 0xC3, 0xFF, 0xF8, 0xFF, 0xE1, 0xFF, 0xF8, 0x78, 0x0F, 0x00, 0x3F, 0xF0, 0xFF, 0x80,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7F, 0xE0, 0xFF, 0xC0,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xC0, 0x7F, 0xE0,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xFF, 0xC0, 0x3F, 0xF0,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xFF, 0x00, 0x1F, 0xF8,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xFE, 0x00, 0x0F, 0xFC,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F, 0xC0, 0x00, 0x03, 0xFE,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1C, 0x00, 0x00, 0x00, 0x1C,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};


class StartMenu : public Menu {
public:
  StartMenu();
  bool update();
  void button1();
  void button2();
  void button3();
  void draw(Adafruit_GFX* display) const;
private:

};


#endif
