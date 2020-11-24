#include <Arduino.h>
#include <Adafruit_GFX.h>
#include "Menu_Gyro.h"
#include "State.h"

// Some graphics constants
#define BLACK 0
#define WHITE 1
#define WIDTH 128
#define HEIGHT 64

GyroMenu::GyroMenu()
  : Menu(MENU_GYRO)

{}

bool GyroMenu::update()  {

}

void GyroMenu::button1() {
  switchMenu(MENU_PACMAN);
}

void GyroMenu::button3() {
  switchMenu(MENU_PACMAN);
}

void GyroMenu::button2() {
  switchMenu(MENU_PACMAN);
}


void GyroMenu::draw(Adafruit_GFX* display) const {

  MPU();
  GyroGame();

}
