#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "Menu_3.h"
#include "State.h"

// Some graphics constants
#define BLACK 0
#define WHITE 1
#define WIDTH 128
#define HEIGHT 64



SettingsBrightnessMenu::SettingsBrightnessMenu()
: Menu(MENU_SETTINGS_BRIGHTNESS)
, selection(0)
{}

bool SettingsBrightnessMenu::update() {
}

void SettingsBrightnessMenu::button1() {
  switchMenu(MENU_SETTINGS_DATE);
}

void SettingsBrightnessMenu::button2() {
  switchMenu(MENU_SETTINGS_DATE);
}

void SettingsBrightnessMenu::button3() {
  switchMenu(MENU_SETTINGS_DATE);
}

void SettingsBrightnessMenu::draw(Adafruit_GFX* display) const {

}
