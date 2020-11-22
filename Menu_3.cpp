#include <Arduino.h>
#include <Adafruit_GFX.h>
#include "Menu_3.h"
#include "State.h"
#include "Clockface_Pacman.h"

// Some graphics constants
#define BLACK 0
#define WHITE 1
#define WIDTH 128
#define HEIGHT 64

SettingsDateMenu::SettingsDateMenu()
  : Menu(MENU_AT)

{}

bool SettingsDateMenu::update()  {

}

void SettingsDateMenu::button1() {
  switchMenu(MENU_5);
}

void SettingsDateMenu::button3() {
  switchMenu(MENU_5);
}

void SettingsDateMenu::button2() {
  switchMenu(MENU_5);
}


void SettingsDateMenu::draw(Adafruit_GFX* display) const {

}
