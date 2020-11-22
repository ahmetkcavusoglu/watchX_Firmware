#ifndef MENU_4_H
#define MENU_4_H

#include <Arduino.h>
#include "Menu.h"

class SettingsClockfaceMenu : public Menu {
  public:
    SettingsClockfaceMenu();
    bool update();
    void button1();
    void button2();
    void button3();
    void draw(Adafruit_GFX* display) const;
    uint8_t dots_xxxx, blinky_xxxx;
  private:

};

#endif
