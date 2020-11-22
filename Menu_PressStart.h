#ifndef MENU_START_H
#define MENU_START_H

#include <Arduino.h>
#include "Menu.h"

class SettingsTimeMenu : public Menu {
public:
  SettingsTimeMenu();
  bool update();
  void button1();
  void button2();
  void button3();
  void draw(Adafruit_GFX* display) const;
private:

};


#endif
