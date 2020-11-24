#ifndef MENU_FREE_H
#define MENU_FREE_H

#include <Arduino.h>
#include "Menu.h"

class FreeMenu : public Menu {
  public:
    FreeMenu();
    bool update();
    void button1();
    void button2();
    void button3();
    void draw(Adafruit_GFX* display) const;

};

#endif
