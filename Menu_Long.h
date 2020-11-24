#ifndef MENU_LONG_H
#define MENU_LONG_H

#include <Arduino.h>
#include "Menu.h"

class LongMenu : public Menu {
  public:
    LongMenu();
    bool update();
    void button1();
    void button2();
    void button3();
    void draw(Adafruit_GFX* display) const;

  private:

};

#endif
