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
  switch(type) {
    case MENU_HELLO:
      return ((SettingsMenu*)this)->update();
    case MENU_SETTINGS_24H:
      return ((Settings24hMenu*)this)->update();
    case MENU_START:
      return ((SettingsTimeMenu*)this)->update();
//    case MENU_SETTINGS_DATE:
//      return ((SettingsDateMenu*)this)->update();
//    case MENU_SETTINGS_BRIGHTNESS:
//      return ((SettingsBrightnessMenu*)this)->update();
  //  case MENU_SETTINGS_CLOCKFACE:
    //  return ((SettingsClockfaceMenu*)this)->update();
    case MENU_CLOCK:
      return ((ClockfaceMenu*)this)->update();
  }
}

void Menu::draw(Adafruit_GFX* display) const {
  switch(type) {
    case MENU_HELLO:
      ((SettingsMenu*)this)->draw(display);
      return;
    case MENU_SETTINGS_24H:
      ((Settings24hMenu*)this)->draw(display);
      return;
    case MENU_START:
      ((SettingsTimeMenu*)this)->draw(display);
      return;
//    case MENU_SETTINGS_DATE:
//      ((SettingsDateMenu*)this)->draw(display);
//      return;
//    case MENU_SETTINGS_BRIGHTNESS:
//      ((SettingsBrightnessMenu*)this)->draw(display);
//      return;
  //  case MENU_SETTINGS_CLOCKFACE:
    //  ((SettingsClockfaceMenu*)this)->draw(display);
    //  return;
    case MENU_CLOCK:
      ((ClockfaceMenu*)this)->draw(display);
      return;
  }
}

void Menu::button1() {
  switch(type) {
    case MENU_HELLO:
      return ((SettingsMenu*)this)->button1();
    case MENU_SETTINGS_24H:
      return ((Settings24hMenu*)this)->button1();
    case MENU_START:
      return ((SettingsTimeMenu*)this)->button1();
//    case MENU_SETTINGS_DATE:
//      return ((SettingsDateMenu*)this)->button1();
//    case MENU_SETTINGS_BRIGHTNESS:
//      return ((SettingsBrightnessMenu*)this)->button1();
    //case MENU_SETTINGS_CLOCKFACE:
      //return ((SettingsClockfaceMenu*)this)->button1();
    case MENU_CLOCK:
      return ((ClockfaceMenu*)this)->button1();
  }
}

void Menu::button3() {
  switch(type) {
    case MENU_HELLO:
      return ((SettingsMenu*)this)->button3();
    case MENU_SETTINGS_24H:
      return ((Settings24hMenu*)this)->button3();
    case MENU_START:
      return ((SettingsTimeMenu*)this)->button3();
//    case MENU_SETTINGS_DATE:
//      return ((SettingsDateMenu*)this)->button3();
//    case MENU_SETTINGS_BRIGHTNESS:
//      return ((SettingsBrightnessMenu*)this)->button3();
    //case MENU_SETTINGS_CLOCKFACE:
      //return ((SettingsClockfaceMenu*)this)->button3();
    case MENU_CLOCK:
      return ((ClockfaceMenu*)this)->button3();
  }
}

void Menu::button2() {
  switch(type) {
    case MENU_HELLO:
      return ((SettingsMenu*)this)->button2();
    case MENU_SETTINGS_24H:
      return ((Settings24hMenu*)this)->button2();
    case MENU_START:
      return ((SettingsTimeMenu*)this)->button2();
//    case MENU_SETTINGS_DATE:
//      return ((SettingsDateMenu*)this)->button2();
//    case MENU_SETTINGS_BRIGHTNESS:
//      return ((SettingsBrightnessMenu*)this)->button2();
    //case MENU_SETTINGS_CLOCKFACE:
      //return ((SettingsClockfaceMenu*)this)->button2();
    case MENU_CLOCK:
      return ((ClockfaceMenu*)this)->button2();
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
  switch(nextMenu) {
    case MENU_HELLO:
      menu = new SettingsMenu();
      break;
    case MENU_SETTINGS_24H:
      menu = new Settings24hMenu();
      break;
    case MENU_START:
      menu = new SettingsTimeMenu();
      break;
//    case MENU_SETTINGS_DATE:
//      menu = new SettingsDateMenu();
//      break;
//    case MENU_SETTINGS_BRIGHTNESS:
//      menu = new SettingsBrightnessMenu();
//      break;
    case MENU_CLOCK:
      menu = new ClockfaceMenu();
      break;
  }
}

