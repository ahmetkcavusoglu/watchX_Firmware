#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "Menu_4.h"
#include "Menu_Clockface.h"
#include "State.h"
#include "Clockface_Pacman.h"

// Some graphics constants
#define BLACK 0
#define WHITE 1
#define WIDTH 128
#define HEIGHT 64

SettingsClockfaceMenu::SettingsClockfaceMenu()
  : Menu(MENU_SETTINGS_CLOCKFACE)
  , blinky_xxxx(0)
  , dots_xxxx(0)

{}

bool SettingsClockfaceMenu::update() {
//  if (state.now.second() >= 5) {
    blinky_xxxx = map(state.now.second(), 5, 60, WIDTH / 2 + 16, 12);
    dots_xxxx = (dots_xxxx + 2) % 10;
//  }
}

void SettingsClockfaceMenu::button1() {
  switchMenu(MENU_CLOCK);
}

void SettingsClockfaceMenu::button3() {
  switchMenu(MENU_CLOCK);
}

void SettingsClockfaceMenu::button2() {
  switchMenu(MENU_CLOCK);
}
int xPos2 = 0;
void SettingsClockfaceMenu::draw(Adafruit_GFX* display) const {

  uint8_t pac_framee = dots_xxxx < 2 ? 52 : (dots_xxxx < 6 ? 26 : 0);
  uint8_t ghost_framee = dots_xxxx < 5 ? 0 : 28;

  // Approach

  display->drawBitmap(xPos2, HEIGHT - 35, pacman_bmp + pac_framee, 16, 13, WHITE);
  display->drawBitmap(xPos2 - blinky_xxxx + 50, HEIGHT - 35, blinky_bmp + ghost_framee, 16, 14, WHITE);
  xPos2 += 1;
  if (xPos2 > 127) {
    xPos2 = 0;
  }
  display->setTextColor(WHITE);
  display->setTextSize(1);
  display->setCursor(11, 10);
  display->print(F("Let's play a game"));
  display->setCursor(13, 56);
  display->print(F("Press any button"));
}
