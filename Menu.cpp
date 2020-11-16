#include <Arduino.h>
#include <Adafruit_GFX.h>
#include "Menu.h"
#include "Menu_Clockface.h"
#include "State.h"
#include "Buttons.h"

extern Menu* menu;

// Where should I change to on next update.
// Check switchMenu() and updateMenu().
Menu_selection nextMenu;

// Some graphics constants
#define BLACK 0
#define WHITE 1
#define WIDTH 128
#define HEIGHT 64


// Unfortunately I couldnt use virtual methods in here
// because it was taking up way to much RAM.
// So here I do manual virtual methods...
bool Menu::update() {
  switch (type) {
    case MENU_CLOCK:
      return ((ClockfaceMenu*)this)->update();
  }
}

void Menu::draw(Adafruit_GFX* display) const {
  switch (type) {
    case MENU_CLOCK:
      ((ClockfaceMenu*)this)->draw(display);
      return;
  }
}

void Menu::button1() {
  switch(type) {
    case MENU_CLOCK:
      return ((ClockfaceMenu*)this)->button1();
  }
}

void Menu::button2() {
  switch(type) {
    case MENU_CLOCK:
      return ((ClockfaceMenu*)this)->button2();
  }
}

void Menu::button3() {
  switch(type) {
    case MENU_CLOCK:
      return ((ClockfaceMenu*)this)->button3();
  }
}
// Function called to indicate that we want to change the menu
// It does not actually change it now, we do that later so that
// we dont delete the class that is calling this function from
// underneath it.
void switchMenu(Menu_selection s) {
  nextMenu = s;
}

void updateMenuSelection() {
  if (nextMenu >= MENU_MAX) return;
  if (menu && menu->getType() == nextMenu) return;

  // Okay we need to change. delete the old one.
  if (menu) {
    // If the menu needs a destructor, you need to do this.
    
      if (menu->getType() == MENU_CLOCK) {
      delete (ClockfaceMenu*)menu;
      } else {
      delete menu;
      }
    delete(menu);
    menu = NULL;
  }

  // Make the new one.
  switch (nextMenu) {
    case MENU_CLOCK:
      menu = new ClockfaceMenu();
      break;
  }
}

void Menu::drawLayout(Adafruit_GFX* display, const __FlashStringHelper* title) const {
}
