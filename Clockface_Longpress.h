#ifndef CLOCKFACE_LONGPRESS_H
#define CLOCKFACE_LONGPRESS_H

#include <Adafruit_GFX.h>
#include "Clockface.h"


class ClockfaceLongpress : public Clockface {
public:

    void draw(Adafruit_GFX* display) const;
};

#endif
