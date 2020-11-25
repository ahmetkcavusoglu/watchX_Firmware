#ifndef MENU_INIT_H
#define MENU_INIT_H

#include <Arduino.h>
#include "Menu.h"

class InitMenu : public Menu {
public:
  InitMenu();
  bool update();
  void button1();
  void button2();
  void button3();
  void draw(Adafruit_GFX* display) const;
private:

};


#endif
