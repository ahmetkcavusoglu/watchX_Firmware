#ifndef MENU_STOP_H
#define MENU_STOP_H

#include <Arduino.h>
#include "Menu.h"



class StopMenu : public Menu {
public:
  StopMenu();

  bool update();
  void draw(Adafruit_GFX* display) const;
  void button1();
  void button2();
  void button3();

};

#endif
