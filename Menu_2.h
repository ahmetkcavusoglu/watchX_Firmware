#ifndef MENU_CANAVAR_H
#define MENU_CANAVAR_H

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

};

#endif
