#ifndef CLOCKFACE_FIRSTSCREEN_H
#define CLOCKFACE_FIRSTSCREEN_H

#include <Adafruit_GFX.h>
#include "Clockface.h"


class ClockfaceFirstScreen : public Clockface {
  public:
    ClockfaceFirstScreen();
    void button2();

    void draw(Adafruit_GFX* display) const;
  private:

};

void watchX_logo(void);
#endif
