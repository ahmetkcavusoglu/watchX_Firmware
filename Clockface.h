#ifndef CLOCKFACE_H
#define CLOCKFACE_H

#include <Adafruit_GFX.h>

class Clockface {
public:
  virtual void update(uint8_t a, uint8_t b) {}
  virtual void draw(Adafruit_GFX* display) const = 0;

};

#endif
