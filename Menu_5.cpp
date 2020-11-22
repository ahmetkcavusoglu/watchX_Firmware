#include <Arduino.h>
#include <Adafruit_GFX.h>
#include "Menu_5.h"
#include "State.h"


// Some graphics constants
#define BLACK 0
#define WHITE 1
#define WIDTH 128
#define HEIGHT 64

const int BTN_1_P = 8; // the number of the pushbutton pin
const int LONG_PRESS_TIME  = 2000; // 1000 milliseconds
int lastState = LOW;  // the previous state from the input pin
int currentState;     // the current reading from the input pin
unsigned long pressedTime  = 0;
unsigned long releasedTime = 0;

Menu5::Menu5()
  : Menu(MENU_5)


{}

bool Menu5::update() {

}

void Menu5::button1() {
  //  switchMenu(MENU_CLOCK);
}

void Menu5::button3() {
  //  switchMenu(MENU_CLOCK);
}

void Menu5::button2() {
  //  switchMenu(MENU_CLOCK);
}

void Menu5::draw(Adafruit_GFX* display) const {
  currentState = digitalRead(BTN_1_P);

  if (lastState == HIGH && currentState == LOW)       // button is pressed
    pressedTime = millis();
  else if (lastState == LOW && currentState == HIGH) { // button is released
    releasedTime = millis();

    long pressDuration = releasedTime - pressedTime;

    if ( pressDuration > LONG_PRESS_TIME ) {
      delay(100);
      switchMenu(MENU_START);
    }

  }
  lastState = currentState;

}
