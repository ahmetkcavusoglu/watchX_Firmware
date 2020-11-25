#ifndef MENU_USB_H
#define MENU_USB_H

#include <Arduino.h>
#include "Menu.h"



class USBMenu : public Menu {
public:
  USBMenu();

  bool update();
  void draw(Adafruit_GFX* display) const;
  void button1();
  void button2();
  void button3();

};

#endif
