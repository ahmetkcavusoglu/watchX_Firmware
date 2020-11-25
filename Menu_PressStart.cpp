#include <Arduino.h>
#include <Adafruit_GFX.h>
#include "Menu_PressStart.h"
#include "State.h"

// Some graphics constants
#define BLACK 0
#define WHITE 1
#define WIDTH 128
#define HEIGHT 64

StartMenu::StartMenu()
  : Menu(MENU_START)

{}

bool StartMenu::update() {
}

void StartMenu::button1() {
  delay(500);
  switchMenu(MENU_HELLO);

}

void StartMenu::button3() {
  delay(500);
  switchMenu(MENU_HELLO);

}

void StartMenu::button2() {
  delay(500);
  switchMenu(MENU_HELLO);

}

void StartMenu::draw(Adafruit_GFX* display) const {

  display->drawBitmap(0, 0, wxlogo_bmp, 128, 32, 1);
  display->setCursor(15, 56);
  display->print(F("PRESS ANY BUTTON"));
  
}
