/*
 * Digital Clockface
 *
 * Shows the hours:minutes in big text, and has a bar underneath showing
 * the seconds.
 * It also has the date on the right hand side of the screen.
 */
#include <Arduino.h>
#include <Adafruit_GFX.h>
#include "Clockface_Digital.h"
#include "State.h"

#define WHITE 1
#define BLACK 0
#define WIDTH 128
#define HEIGHT 64

void ClockfaceDigital::draw(Adafruit_GFX* display) const {

//  display->drawCircle(120, 19, 1, WHITE);
  GyroGame();



}
