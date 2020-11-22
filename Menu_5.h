#ifndef MENU_5_H
#define MENU_5_H

#include <Arduino.h>
#include "Menu.h"

class Menu5 : public Menu {
  public:
    Menu5();
    bool update();
    void button1();
    void button2();
    void button3();
    void draw(Adafruit_GFX* display) const;

  private:

};

#endif
