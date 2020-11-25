#include <Adafruit_GFX.h>
#include "Menu.h"
#include "State.h"
#include "Menu_Pacman.h"

#define WHITE 1
#define BLACK 0
#define WIDTH 128
#define HEIGHT 64

#define DOTS_SPACE 10

PacmanMenu::PacmanMenu()
  : Menu(MENU_PACMAN)
  , blinky_x(0)
  , dots_x(0)
{}

bool PacmanMenu::update() {

  blinky_x = map(state.now.second(), 5, 60, WIDTH / 2 + 16, 12);
  dots_x = (dots_x + 2) % DOTS_SPACE;

}
void PacmanMenu::button1() {
  switchMenu(MENU_USB);
}

void PacmanMenu::button3() {
  switchMenu(MENU_USB);
}

void PacmanMenu::button2() {
  switchMenu(MENU_USB);
}


void PacmanMenu::draw(Adafruit_GFX* display) const {

  display->setCursor(0, 0);
  display->print(F("Now we will learn how"));
  display->setCursor(8, 10);
  display->print(F("to code the watchX"));
  display->setCursor(15, 20);
  display->print(F("press any button"));
  display->setCursor(30, 30);
  display->print(F("to continue"));


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
