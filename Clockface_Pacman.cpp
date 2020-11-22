
#include <Adafruit_GFX.h>
#include "Menu.h"
#include "Menu_Clockface.h"
#include "State.h"
#include "Clockface_Pacman.h"

#define WHITE 1
#define BLACK 0
#define WIDTH 128
#define HEIGHT 64

#define DOTS_SPACE 10

ClockfacePacman::ClockfacePacman()
: Menu(MENU_PACMAN)
  , blinky_x(0)
  , dots_x(0)
//  , die_timer(0)
{}

bool ClockfacePacman::update() {
//  if (state.now.second() >= 5) {
    blinky_x = map(state.now.second(), 5, 60, WIDTH / 2 + 16, 12);
    dots_x = (dots_x + 2) % DOTS_SPACE;
//    die_timer = 0;
//  } else {
//    die_timer += 1;
//  }
}
void ClockfacePacman::button1() {
  switchMenu(MENU_CANAVAR);
}

void ClockfacePacman::button3() {
  switchMenu(MENU_CANAVAR);
}

void ClockfacePacman::button2() {
  switchMenu(MENU_CANAVAR);
}


void ClockfacePacman::draw(Adafruit_GFX* display) const {

  display->setTextColor(WHITE);
  display->setTextSize(1);
  display->setCursor(10, 0);
  display->print(F("Now, press button"));
  display->setCursor(15, 10);
  display->print(F("and connect"));
  display->setCursor(20, 20);
  display->print(F("watchX to PC :)"));

//   Pacman!
  display->drawFastHLine(0, HEIGHT - 22, WIDTH, WHITE);
  display->drawFastHLine(0, HEIGHT - 3, WIDTH, WHITE);

  for (uint8_t i = (WIDTH / 2) + DOTS_SPACE * 2 - dots_x; i < WIDTH; i += DOTS_SPACE) {
    display->fillCircle(i, HEIGHT - 14, 1, WHITE);
  }

  uint8_t pac_frame = dots_x < 2 ? 52 : (dots_x < 6 ? 26 : 0);
  uint8_t ghost_frame = dots_x < 5 ? 0 : 28;

  // Approach
  display->drawBitmap(WIDTH / 2, HEIGHT - 20, pacman_bmp + pac_frame, 16, 13, WHITE);
  display->drawBitmap(WIDTH / 2 - blinky_x, HEIGHT - 20, blinky_bmp + ghost_frame, 16, 14, WHITE);

  }
