#ifndef CLOCKFACE_HELLO_H
#define CLOCKFACE_HELLO_H

#include <Adafruit_GFX.h>
#include "Clockface.h"

class ClockfaceHello : public Clockface {
  public:

    void draw(Adafruit_GFX* display) const;
  private:

};

//void hello(void);

#endif
