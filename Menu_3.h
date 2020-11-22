#ifndef MENU_AT_H
#define MENU_AT_H

#include <Arduino.h>
#include "Menu.h"

class SettingsDateMenu : public Menu {
  public:
    SettingsDateMenu();
    bool update();
    void button1();
    void button2();
    void button3();
    void draw(Adafruit_GFX* display) const;

};

#endif
