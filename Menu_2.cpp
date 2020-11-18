#include <Arduino.h>
#include <Adafruit_GFX.h>
#include "Menu_2.h"
#include "State.h"

// Some graphics constants
#define BLACK 0
#define WHITE 1
#define WIDTH 128
#define HEIGHT 64

Settings24hMenu::Settings24hMenu()
  : Menu(MENU_SETTINGS_24H)
{}

bool Settings24hMenu::update()  {
  //  return state.timeMinuteUpdated;
}

void Settings24hMenu::button1() {
switchMenu(MENU_SETTINGS_TIME);
}

void Settings24hMenu::button3() {
switchMenu(MENU_SETTINGS_TIME);
}

void Settings24hMenu::button2() {
  switchMenu(MENU_SETTINGS_TIME);
}

void Settings24hMenu::draw(Adafruit_GFX* display) const {
  
}
