#include <Arduino.h>
#include <Adafruit_GFX.h>
#include "Menu_PressStart.h"
#include "Menu_Init.h"
#include "State.h"

// Some graphics constants
#define BLACK 0
#define WHITE 1
#define WIDTH 128
#define HEIGHT 64

InitMenu::InitMenu()
  : Menu(MENU_INIT)

{}

bool InitMenu::update() {
}

void InitMenu::button1() {
  delay(2000);
  switchMenu(MENU_START);
}

void InitMenu::button3() {
  delay(2000);
  switchMenu(MENU_START);
}

void InitMenu::button2() {
  delay(2000);
  switchMenu(MENU_START);
}



void InitMenu::draw(Adafruit_GFX* display) const {

  display->setTextColor(WHITE);
  display->setCursor(40, 56);
  display->print(F("Loading..."));
  tone(9, 1000, 300);

}
