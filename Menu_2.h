#ifndef MENU_2_H
#define MENU_2_H

#include <Arduino.h>
#include "Menu.h"

class Settings24hMenu : public Menu {
public:
  Settings24hMenu();
  bool update();
  void button1();
  void button2();
  void button3();
  void draw(Adafruit_GFX* display) const;
  void update(uint8_t a, uint8_t b);
  private:

  uint8_t dots_x, blinky_x, die_timer;
};

#endif
