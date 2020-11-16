#ifndef CLOCKFACE_BUTTON_H
#define CLOCKFACE_BUTTON_H

#include <Adafruit_GFX.h>
#include "Clockface.h"


class ClockfaceButton : public Clockface {
public:

    void draw(Adafruit_GFX* display) const;
};

#endif
