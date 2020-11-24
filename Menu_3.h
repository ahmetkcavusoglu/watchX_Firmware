#ifndef MENU_HELLO_H
#define MENU_HELLO_H
#include <Arduino.h>
#include "Menu.h"

class HelloMenu : public Menu {
public:
  HelloMenu();
  bool update();
  void button1();
  void button2();
  void button3();
  void draw(Adafruit_SSD1306* display) const;

protected:

};

#endif
