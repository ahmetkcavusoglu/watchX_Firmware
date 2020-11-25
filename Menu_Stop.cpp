#include <Arduino.h>
#include <RTClib.h>
#include <Adafruit_GFX.h>
#include "Menu_Stop.h"
#include "Menu.h"
#include "State.h"



StopMenu::StopMenu()
  : Menu(MENU_STOP)

{}

bool StopMenu::update() {
  return true;
}


void StopMenu::draw(Adafruit_GFX* display) const {
  tone(9, 1000, 300);
    while(1){/*empty*/}
}

void StopMenu::button1() {

}

void StopMenu::button2() {
 
}

void StopMenu::button3() {

}
