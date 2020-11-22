#include <Arduino.h>
#include <Adafruit_GFX.h>

#include "Clockface_Gyro.h"
#include "State.h"

#define WHITE 1
#define BLACK 0
#define WIDTH 128
#define HEIGHT 64

void ClockfaceGyro::draw(Adafruit_GFX* display) const {
  
  MPU();
  GyroGame();
   

}
