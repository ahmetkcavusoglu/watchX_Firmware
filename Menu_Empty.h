#ifndef MENU_EMPTY_H
#define MENU_EMPTY_H

#include <Arduino.h>
#include <RTClib.h>
#include "Menu.h"


enum FACE {
  FACE_GYRO,

  
  FACE_MAX
};

class EmptyMenu : public Menu {
public:
  EmptyMenu();
  ~EmptyMenu();

  bool update();
  void draw(Adafruit_GFX* display) const;
  void button1();
  void button2();
  void button3();
private:
  void changeMenu();
  uint8_t faceType;
};

#endif
