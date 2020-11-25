#include <Arduino.h>
#include <Adafruit_GFX.h>
#include "Menu_Long.h"
#include "State.h"


// Some graphics constants
#define BLACK 0
#define WHITE 1
#define WIDTH 128
#define HEIGHT 64

const int button = 8;
const int press_time  = 2000;
int lastState = LOW;  // the previous state from the input pin
int currentState;     // the current reading from the input pin
unsigned long pressedTime  = 0;
unsigned long releasedTime = 0;

LongMenu::LongMenu()
  : Menu(MENU_LONG)


{}

bool LongMenu::update() {

}

void LongMenu::button1() {
  //  switchMenu(MENU_START);
}

void LongMenu::button3() {
//  switchMenu(MENU_START);
}

void LongMenu::button2() {
  delay(2000);
  switchMenu(MENU_INIT);
}

void LongMenu::draw(Adafruit_GFX* display) const {
}
