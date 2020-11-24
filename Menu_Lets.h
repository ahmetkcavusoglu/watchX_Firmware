#ifndef MENU_LETS_H
#define MENU_LETS_H

#include <Arduino.h>
#include "Menu.h"

class LetsMenu : public Menu {
  public:
    LetsMenu();
    bool update();
    void button1();
    void button2();
    void button3();
    void draw(Adafruit_GFX* display) const;
    uint8_t dots_xxxx, blinky_xxxx;
  private:

};

#endif
