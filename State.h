#ifndef STATE_H
#define STATE_H

#include <RTClib.h>

/*
 * A global object holding state and settings.
 */
struct State {
  State();

  void update();
  DateTime now;

// Settings
  bool dim;
  uint8_t current_face;


};

extern State state;

#endif
