#include <Arduino.h>
#include <Adafruit_GFX.h>
#include "Menu_2.h"
#include "State.h"
#include "Clockface_Pacman.h"

// Some graphics constants
#define BLACK 0
#define WHITE 1
#define WIDTH 128
#define HEIGHT 64

Settings24hMenu::Settings24hMenu()
  : Menu(MENU_SETTINGS_24H)
  , blinky_xx(0)
  , dots_xx(0)
{}

bool Settings24hMenu::update()  {
  if (state.now.second() >= 5) {
    blinky_xx = map(state.now.second(), 5, 60, WIDTH / 2 + 16, 12);
    dots_xx = (dots_xx + 2) % 10;
  }
}

void Settings24hMenu::button1() {
  switchMenu(MENU_START);
}

void Settings24hMenu::button3() {
  switchMenu(MENU_CLOCK);
}

void Settings24hMenu::button2() {
  switchMenu(MENU_START);
}

void Settings24hMenu::draw(Adafruit_GFX* display) const {
  
    uint8_t pac_framee = dots_xx < 2 ? 52 : (dots_xx < 6 ? 26 : 0);
    uint8_t ghost_framee = dots_xx < 5 ? 0 : 28;
  
    // Approach
    display->drawBitmap(WIDTH / 2, HEIGHT - 40, pacman_bmp + pac_framee, 16, 13, WHITE);
    display->drawBitmap(WIDTH / 2 - blinky_xx + 50, HEIGHT - 40, blinky_bmp + ghost_framee, 16, 14, WHITE);
}
