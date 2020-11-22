#ifndef CLOCKFACE_GYRO_H
#define CLOCKFACE_GYRO_H

#include <Adafruit_GFX.h>
#include "Clockface.h"

class ClockfaceGyro : public Clockface {
  public:
    void draw(Adafruit_GFX* display) const;

};

void GyroGame(void);
void MPU(void);
#endif
