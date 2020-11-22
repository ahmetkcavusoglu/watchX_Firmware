#include <Arduino.h>
#include <Adafruit_GFX.h>
#include "Menu.h"
#include "Menu_1.h"
#include "Menu_2.h"
#include "Menu_PressStart.h"
#include "Menu_5.h"
#include "Menu_3.h"
#include "Menu_4.h"
#include "Menu_Clockface.h"
#include "State.h"
#include "Clockface_Pacman.h"

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
    case MENU_START:
      return ((SettingsTimeMenu*)this)->update();
    case MENU_CANAVAR:
      return ((Settings24hMenu*)this)->update();
    case MENU_HELLO:
      return ((SettingsMenu*)this)->update();
    case MENU_CLOCK:
      return ((ClockfaceMenu*)this)->update();
    case MENU_AT:
      return ((SettingsDateMenu*)this)->update();
    case MENU_SETTINGS_CLOCKFACE:
      return ((SettingsClockfaceMenu*)this)->update();
    case MENU_PACMAN:
      return ((ClockfacePacman*)this)->update();
    case MENU_5:
      return ((Menu5*)this)->update();
  }
}

void Menu::draw(Adafruit_GFX* display) const {
  switch (type) {
    case MENU_START:
      ((SettingsTimeMenu*)this)->draw(display);
      return;
    case MENU_HELLO:
      ((SettingsMenu*)this)->draw(display);
      return;
    case MENU_CANAVAR:
      ((Settings24hMenu*)this)->draw(display);
      return;

    case MENU_AT:
      ((SettingsDateMenu*)this)->draw(display);
      return;
    case MENU_CLOCK:
      ((ClockfaceMenu*)this)->draw(display);
      return;
    case MENU_SETTINGS_CLOCKFACE:
      ((SettingsClockfaceMenu*)this)->draw(display);
      return;
    case MENU_PACMAN:
      ((ClockfacePacman*)this)->draw(display);
      return;
    case MENU_5:
      ((Menu5*)this)->draw(display);
      return;

  }
}

void Menu::button1() {
  switch (type) {
    case MENU_HELLO:
      return ((SettingsMenu*)this)->button1();
    case MENU_CANAVAR:
      return ((Settings24hMenu*)this)->button1();
    case MENU_START:
      return ((SettingsTimeMenu*)this)->button1();
    case MENU_CLOCK:
      return ((ClockfaceMenu*)this)->button1();
    case MENU_AT:
      return ((SettingsDateMenu*)this)->button1();
    case MENU_SETTINGS_CLOCKFACE:
      return ((SettingsClockfaceMenu*)this)->button1();
    case MENU_PACMAN:
      return ((ClockfacePacman*)this)->button1();
    case MENU_5:
      return ((Menu5*)this)->button1();
  }
}

void Menu::button3() {
  switch (type) {
    case MENU_HELLO:
      return ((SettingsMenu*)this)->button3();
    case MENU_CANAVAR:
      return ((Settings24hMenu*)this)->button3();
    case MENU_START:
      return ((SettingsTimeMenu*)this)->button3();
    case MENU_CLOCK:
      return ((ClockfaceMenu*)this)->button3();
    case MENU_AT:
      return ((SettingsDateMenu*)this)->button3();
    case MENU_SETTINGS_CLOCKFACE:
      return ((SettingsClockfaceMenu*)this)->button3();
    case MENU_PACMAN:
      return ((ClockfacePacman*)this)->button3();
    case MENU_5:
      return ((Menu5*)this)->button3();
  }
}

void Menu::button2() {
  switch (type) {
    case MENU_HELLO:
      return ((SettingsMenu*)this)->button2();
    case MENU_CANAVAR:
      return ((Settings24hMenu*)this)->button2();
    case MENU_START:
      return ((SettingsTimeMenu*)this)->button2();
    case MENU_CLOCK:
      return ((ClockfaceMenu*)this)->button2();
    case MENU_AT:
      return ((SettingsDateMenu*)this)->button2();
    case MENU_SETTINGS_CLOCKFACE:
      return ((SettingsClockfaceMenu*)this)->button2();
    case MENU_PACMAN:
      return ((ClockfacePacman*)this)->button2();
    case MENU_5:
      return ((Menu5*)this)->button2();
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
    menu = NULL;
  }

  // Make the new one.
  switch (nextMenu) {
    case MENU_HELLO:
      menu = new SettingsMenu();
      break;
    case MENU_CANAVAR:
      menu = new Settings24hMenu();
      break;
    case MENU_START:
      menu = new SettingsTimeMenu();
      break;
    case MENU_CLOCK:
      menu = new ClockfaceMenu();
      break;
    case MENU_AT:
      menu = new SettingsDateMenu();
      break;
    case MENU_SETTINGS_CLOCKFACE:
      menu = new SettingsClockfaceMenu();
      break;
    case MENU_PACMAN:
      menu = new ClockfacePacman();
      break;
       case MENU_5:
      menu = new Menu5();
      break;
  }
}
