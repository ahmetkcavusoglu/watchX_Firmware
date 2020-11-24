#include <Arduino.h>
#include <Adafruit_GFX.h>
#include "Menu_Free.h"
#include "State.h"
#include "Menu_Pacman.h"

// Some graphics constants
#define BLACK 0
#define WHITE 1
#define WIDTH 128
#define HEIGHT 64

FreeMenu::FreeMenu()
  : Menu(MENU_FREE)

{}

bool FreeMenu::update()  {

}

void FreeMenu::button1() {
  switchMenu(MENU_LONG);
}

void FreeMenu::button3() {
  switchMenu(MENU_LONG);
}

void FreeMenu::button2() {
  switchMenu(MENU_LONG);
}


void FreeMenu::draw(Adafruit_GFX* display) const {

}
