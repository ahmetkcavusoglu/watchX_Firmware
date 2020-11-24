#ifndef MENU_GYRO_H
#define MENU_GYRO_H

#include <Arduino.h>
#include "Menu.h"

class GyroMenu : public Menu {
  public:
    GyroMenu();
    bool update();
    void button1();
    void button2();
    void button3();
    void draw(Adafruit_GFX* display);

};

void GyroGame(void);
void MPU(void);

void setRandom();
#endif
