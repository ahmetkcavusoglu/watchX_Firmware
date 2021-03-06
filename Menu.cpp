#include <Arduino.h>
#include <Adafruit_GFX.h>
#include "Menu.h"
#include "Menu_Hello.h"
#include "Menu_Gyro.h"
#include "Menu_PressStart.h"
#include "Menu_Long.h"
#include "Menu_Free.h"
#include "Menu_Lets.h"
#include "Menu_USB.h"
#include "State.h"
#include "Menu_Pacman.h"
#include "Menu_Stop.h"
#include "Menu_Init.h"

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
      return ((StartMenu*)this)->update();
    case MENU_GYRO:
      return ((GyroMenu*)this)->update();
    case MENU_HELLO:
      return ((HelloMenu*)this)->update();
    case MENU_USB:
      return ((USBMenu*)this)->update();
    case MENU_FREE:
      return ((FreeMenu*)this)->update();
    case MENU_LETS:
      return ((LetsMenu*)this)->update();
    case MENU_PACMAN:
      return ((PacmanMenu*)this)->update();
    case MENU_LONG:
      return ((LongMenu*)this)->update();
    case MENU_STOP:
      return ((StopMenu*)this)->update();
    case MENU_INIT:
      return ((InitMenu*)this)->update();
  }
}

void Menu::draw(Adafruit_GFX* display)  {
  switch (type) {
    case MENU_START:
      ((StartMenu*)this)->draw(display);
      return;
    case MENU_HELLO:
      ((HelloMenu*)this)->draw(display);
      return;
    case MENU_GYRO:
      ((GyroMenu*)this)->draw(display);
      return;
    case MENU_FREE:
      ((FreeMenu*)this)->draw(display);
      return;
    case MENU_USB:
      ((USBMenu*)this)->draw(display);
      return;
    case MENU_LETS:
      ((LetsMenu*)this)->draw(display);
      return;
    case MENU_PACMAN:
      ((PacmanMenu*)this)->draw(display);
      return;
    case MENU_LONG:
      ((LongMenu*)this)->draw(display);
      return;
    case MENU_STOP:
      ((StopMenu*)this)->draw(display);
      return;
    case MENU_INIT:
      ((InitMenu*)this)->draw(display);
      return;
  }
}

void Menu::button1() {
  switch (type) {
    case MENU_HELLO:
      return ((HelloMenu*)this)->button1();
    case MENU_GYRO:
      return ((GyroMenu*)this)->button1();
    case MENU_START:
      return ((StartMenu*)this)->button1();
    case MENU_USB:
      return ((USBMenu*)this)->button1();
    case MENU_FREE:
      return ((FreeMenu*)this)->button1();
    case MENU_LETS:
      return ((LetsMenu*)this)->button1();
    case MENU_PACMAN:
      return ((PacmanMenu*)this)->button1();
    case MENU_LONG:
      return ((LongMenu*)this)->button1();
    case MENU_STOP:
      return ((StopMenu*)this)->button1();
    case MENU_INIT:
      return ((InitMenu*)this)->button1();
  }
}

void Menu::button3() {
  switch (type) {
    case MENU_HELLO:
      return ((HelloMenu*)this)->button3();
    case MENU_GYRO:
      return ((GyroMenu*)this)->button3();
    case MENU_START:
      return ((StartMenu*)this)->button3();
    case MENU_USB:
      return ((USBMenu*)this)->button3();
    case MENU_FREE:
      return ((FreeMenu*)this)->button3();
    case MENU_LETS:
      return ((LetsMenu*)this)->button3();
    case MENU_PACMAN:
      return ((PacmanMenu*)this)->button3();
    case MENU_LONG:
      return ((LongMenu*)this)->button3();
    case MENU_STOP:
      return ((StopMenu*)this)->button3();
    case MENU_INIT:
      return ((InitMenu*)this)->button3();
  }
}

void Menu::button2() {
  switch (type) {
    case MENU_HELLO:
      return ((HelloMenu*)this)->button2();
    case MENU_GYRO:
      return ((GyroMenu*)this)->button2();
    case MENU_START:
      return ((StartMenu*)this)->button2();
    case MENU_USB:
      return ((USBMenu*)this)->button2();
    case MENU_FREE:
      return ((FreeMenu*)this)->button2();
    case MENU_LETS:
      return ((LetsMenu*)this)->button2();
    case MENU_PACMAN:
      return ((PacmanMenu*)this)->button2();
    case MENU_LONG:
      return ((LongMenu*)this)->button2();
    case MENU_STOP:
      return ((StopMenu*)this)->button2();
    case MENU_INIT:
      return ((InitMenu*)this)->button2();
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
    
    menu = NULL;
  }

  // Make the new one.
  switch (nextMenu) {
    case MENU_HELLO:
      menu = new HelloMenu();
      break;
    case MENU_GYRO:
      menu = new GyroMenu();
      break;
    case MENU_START:
      menu = new StartMenu();
      break;
    case MENU_USB:
      menu = new USBMenu();
      break;
    case MENU_FREE:
      menu = new FreeMenu();
      break;
    case MENU_LETS:
      menu = new LetsMenu();
      break;
    case MENU_PACMAN:
      menu = new PacmanMenu();
      break;
    case MENU_LONG:
      menu = new LongMenu();
      break;
    case MENU_STOP:
      menu = new StopMenu();
      break;
    case MENU_INIT:
      menu = new InitMenu();
      break;
  }
}
