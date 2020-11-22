#ifndef STATE_H
#define STATE_H

#include <RTClib.h>

/*
   A global object holding state and settings.
*/
struct State {
  State();

  void update();
  DateTime now;

//  // Settings
  uint8_t current_face;
//  uint8_t enabled_faces;

};

extern State state;

#endif
