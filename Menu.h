#ifndef MENU_H
#define MENU_H

#include <Arduino.h>
#include <Adafruit_GFX.h>

enum Menu_selection {
  MENU_SETTINGS_24H,
  MENU_CLOCK,
  MENU_START,
  MENU_HELLO,
  MENU_MAX
};

class Menu {
  public:
    Menu(Menu_selection t) : type(t) {}
    bool update();
    void draw(Adafruit_GFX* display) const;
    void button1();
    void button2();
    void button3();

    Menu_selection getType() const {
      return type;
    }
  protected:
    Menu_selection type;

};

// Change the current menu
void switchMenu(Menu_selection);
// To be called from the .ino to actually do the menu switch.
void updateMenuSelection();

#endif
