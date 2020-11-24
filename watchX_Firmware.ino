#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include "Buttons.h"
#include "Menu.h"
#include "State.h"

#define Button1   10
#define Button2 11
#define Button3 8

#define OLED_DC     A3
#define OLED_CS     A5
#define OLED_RESET  A4
#define WIDTH      128
#define HEIGHT     64
Adafruit_SSD1306 display(OLED_DC, OLED_RESET, OLED_CS);

Button btn1(Button1);
Button btn2 (Button2);
Button btn3(Button3);

void setRandom();

State state;
Menu* menu = NULL;

void button1Pressed() {
  btn1.interrupt();
}
void button2Pressed() {
  btn2.interrupt();
}
void button3Pressed() {
  btn3.interrupt();
}




void setup(void) {

  display.begin(SSD1306_SWITCHCAPVCC);
  display.clearDisplay();
  tone(9, 1000, 300);

  // Setup buttons
  pinMode(Button1, INPUT_PULLUP);
  pinMode(Button2, INPUT_PULLUP);
  pinMode(Button3, INPUT_PULLUP);
  pinMode(13, OUTPUT);
  pinMode(6, OUTPUT);

  setRandom();
  switchMenu(MENU_FREE);


}

void loop() {

  bool draw = false;

  // Buttons
  if (btn1.update() && btn1.read()) {
    menu->button1();
    draw = true;
  }
  if (btn2.update() && btn2.read()) {
    menu->button3();
    draw = true;
  }
  if (btn3.update() && btn3.read()) {
    menu->button2();
    draw = true;
  }

  // Switch menu if indicated.
  updateMenuSelection();

  // Update
  if (menu->update()) {
    draw = true;
  }

  // Display
  if (draw) {
    display.clearDisplay();
    menu->draw(&display);
    display.display();
  }

}

