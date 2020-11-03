#include <Arduino.h>
//#include <RTClib.h>
#include <Adafruit_GFX.h>
#include "Menu_Clockface.h"
#include "Menu.h"
#include "State.h"
#include "Clockface_Pacman.h"

ClockfaceMenu::ClockfaceMenu()
: Menu(MENU_CLOCK)
, faceType(FACE_PACMAN)
, face(NULL)
{
  faceType = state.current_face;
  if (faceType >= FACE_MAX) faceType = 0;
  changeMenu();

}

ClockfaceMenu::~ClockfaceMenu() {
  delete face;
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

void ClockfaceMenu::changeMenu() {
  // Switch object
  if (face) {
    delete face;
    face = NULL;
  }
  switch(faceType) {
  case FACE_PACMAN:
    face = new ClockfacePacman();
    break;

  }
}
