#ifndef STATE_H
#define STATE_H

#include <RTClib.h>

struct State {
  State();

  void update();
  DateTime now;

  uint8_t current_face;

};

extern State state;

#endif
