#include <Arduino.h>
#include "Menu.h"

class SettingsMenu : public Menu {
public:
  SettingsMenu();
  bool update();
  void button1();
  void button2();
  void button3();
  void draw(Adafruit_GFX* display) const;

protected:

};
