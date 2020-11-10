#ifndef MENU_CLOCKFACE_H
#define MENU_CLOCKFACE_H

#include <Arduino.h>
#include "Menu.h"
#include "Clockface.h"


enum FACE {
  FACE_PACMAN,
  FACE_DIGITAL,
  FACE_MAX
};

class ClockfaceMenu : public Menu {
  public:
    ClockfaceMenu();
    ~ClockfaceMenu();
    bool update();
    void draw(Adafruit_GFX* display) const;
    void button1();
  private:
    void changeMenu();
    Clockface* face;
    uint8_t faceType;
};

#endif
