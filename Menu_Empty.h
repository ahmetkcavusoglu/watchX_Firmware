#ifndef MENU_EMPTY_H
#define MENU_EMPTY_H

#include <Arduino.h>
#include "Menu.h"



class EmptyMenu : public Menu {
public:
  EmptyMenu();

  bool update();
  void draw(Adafruit_GFX* display) const;
  void button1();
  void button2();
  void button3();

};

#endif
