#ifndef CLOCKFACE_PACMAN_H
#define CLOCKFACE_PACMAN_H

#include <Adafruit_GFX.h>
#include "Clockface.h"
#include "Menu.h"
#include "Menu_Clockface.h"
#include "State.h"
class ClockfacePacman : public Clockface {
public:
  ClockfacePacman();
  void update(uint8_t a, uint8_t b);
  void draw(Adafruit_GFX* display) const;


  uint8_t dots_x, blinky_x, die_timer;
};

#endif
