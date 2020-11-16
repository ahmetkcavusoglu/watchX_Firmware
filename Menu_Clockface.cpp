#include <Arduino.h>
#include <Adafruit_GFX.h>
#include "Menu_Clockface.h"
#include "Menu.h"
#include "State.h"
#include "Clockface_Pacman.h"
#include "Clockface_FirstScreen.h"
#include "Clockface_Hello.h"
#include "Clockface_Gyro.h"
#include "Clockface_Button.h"
#include "Clockface_Longpress.h"


ClockfaceMenu::ClockfaceMenu()
  : Menu(MENU_CLOCK)
  , faceType(FACE_LONG)
  , face(NULL)
{
  faceType = state.current_face;
  if (faceType >= FACE_MAX) faceType = 0;
  changeMenu();

}

ClockfaceMenu::~ClockfaceMenu() {
  delete(face);
}

bool ClockfaceMenu::update() {
  uint8_t a;
  face->update(a, state.now.minute());
  // Always render
  return true;
}

void ClockfaceMenu::draw(Adafruit_GFX* display) const {
  face->draw(display);
}

void ClockfaceMenu::button1() {
  do {
    faceType = (faceType + 1) % FACE_MAX;
  } while (!(state.enabled_faces & _BV(faceType)));
  changeMenu();
}
//void ClockfaceMenu::button2() {
//  do {
//    faceType = (faceType + 1) % FACE_MAX;
//  } while (!(state.enabled_faces & _BV(faceType)));
//  changeMenu();
//}
//void ClockfaceMenu::button3() {
//  do {
//    faceType = (faceType + 1) % FACE_MAX;
//  } while (!(state.enabled_faces & _BV(faceType)));
//  changeMenu();
//}

void ClockfaceMenu::changeMenu() {
  // Switch object
  if (face) {
    delete(face);
    face = NULL;
  }
  switch (faceType) {
    case FACE_LONG:
      face = new ClockfaceLongpress();
      break;
    case FACE_FIRSTSCREEN:
      face = new ClockfaceFirstScreen();
      break;
    case FACE_HELLO:
      face = new ClockfaceHello();
      break;
    case FACE_BUTTON:
      face = new ClockfaceButton();
      break;
    case FACE_GYRO:
      face = new ClockfaceGyro();
      break;
    case FACE_PACMAN:
      face = new ClockfacePacman();
      break;

  }
}
