#include <Arduino.h>
#include <RTClib.h>
#include <Adafruit_GFX.h>
#include "Menu_Empty.h"
#include "Menu.h"
#include "State.h"

EmptyMenu::EmptyMenu()
  : Menu(MENU_EMPTY)

{}

bool EmptyMenu::update() {
  return true;
}


void EmptyMenu::draw(Adafruit_GFX* display) const {
}

void EmptyMenu::button1() {
  switchMenu(MENU_PACMAN);
}

void EmptyMenu::button2() {
  switchMenu(MENU_PACMAN);
}

void EmptyMenu::button3() {
  switchMenu(MENU_PACMAN);
}
