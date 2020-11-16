#include <Arduino.h>
#include <Adafruit_GFX.h>
#include "Clockface_Button.h"
#include "State.h"

#define WHITE 1
#define BLACK 0
#define WIDTH 128
#define HEIGHT 64

void ClockfaceButton::draw(Adafruit_GFX* display) const {

  display->setTextColor(WHITE);
    display->setTextSize(1);
    display->setCursor(20, 0);
    display->print(F("Button Game"));





}
