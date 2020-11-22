#include <Arduino.h>
#include <Adafruit_SSD1306.h>
#include "Menu_1.h"
#include "State.h"

// Some graphics constants
#define BLACK 0
#define WHITE 1
#define WIDTH 128
#define HEIGHT 64

const unsigned char PROGMEM saat_bmp [] = {
  0x00, 0x1F, 0xFF, 0xFF, 0xFF, 0xFF, 0xF8, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00,
  0x00, 0x43, 0xFF, 0xFF, 0xFF, 0xFF, 0xC2, 0x00, 0x00, 0x44, 0x00, 0x00, 0x00, 0x00, 0x22, 0x00,
  0x00, 0x48, 0x00, 0x00, 0x00, 0x00, 0x12, 0x00, 0x00, 0x48, 0x00, 0x00, 0x00, 0x00, 0x12, 0x00,
  0x00, 0x88, 0x00, 0x00, 0x00, 0x00, 0x11, 0x00, 0x01, 0x04, 0x00, 0x00, 0x00, 0x00, 0x20, 0x80,
  0x02, 0x03, 0xFF, 0xFF, 0xFF, 0xFF, 0xC0, 0x40, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20,
  0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x11, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x88,
  0x21, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x84, 0x21, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x84,
  0x21, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x84, 0x21, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x84,
  0x61, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x86, 0xE1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x87,
  0xE1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x87, 0xE1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x87,
  0x61, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x86, 0x21, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x84,
  0x21, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x84, 0x21, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x84,
  0x21, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x84, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x88,
  0x09, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x90, 0x09, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x90,
  0x09, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x90, 0x09, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x90,
  0x09, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x90, 0x09, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x90,
  0x09, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x90, 0x09, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x90,
  0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x88, 0x21, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x84,
  0x21, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x84, 0x21, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x84,
  0x21, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x84, 0x61, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x86,
  0xE1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x87, 0xE1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x87,
  0xE1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x87, 0x61, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x86,
  0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04,
  0x20, 0x78, 0x00, 0x00, 0x00, 0x00, 0x1E, 0x04, 0x20, 0x78, 0x00, 0x00, 0x00, 0x00, 0x1E, 0x04,
  0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x08, 0x00, 0x1F, 0xFF, 0xFF, 0xF8, 0x00, 0x10,
  0x04, 0x00, 0x20, 0x00, 0x00, 0x04, 0x00, 0x20, 0x02, 0x03, 0xC0, 0x00, 0x00, 0x03, 0xC0, 0x40,
  0x01, 0x04, 0x00, 0x00, 0x00, 0x00, 0x20, 0x80, 0x00, 0x88, 0x00, 0x00, 0x00, 0x00, 0x11, 0x00,
  0x00, 0x48, 0x00, 0x00, 0x00, 0x00, 0x12, 0x00, 0x00, 0x48, 0x00, 0x00, 0x00, 0x00, 0x12, 0x00,
  0x00, 0x44, 0x00, 0x00, 0x00, 0x00, 0x22, 0x00, 0x00, 0x43, 0xFF, 0xFF, 0xFF, 0xFF, 0xC2, 0x00,
  0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00,
  0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x1F, 0xFF, 0xFF, 0xFF, 0xFF, 0xF8, 0x00

};

//const unsigned char PROGMEM sun [] = {
//  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00,
//  0x01, 0x00, 0x80, 0x00, 0x01, 0x00, 0x00, 0x30, 0x01, 0x80, 0x00, 0xE0, 0x00, 0x80, 0x00, 0xC0,
//  0x00, 0x0F, 0xC0, 0x00, 0x00, 0x1F, 0xF0, 0x00, 0x00, 0x30, 0x1C, 0x00, 0x00, 0x60, 0x06, 0x00,
//  0x20, 0xC0, 0x02, 0x00, 0x38, 0xDF, 0xFB, 0x00, 0x09, 0xBE, 0x71, 0x3C, 0x01, 0x9C, 0x79, 0xB0,
//  0x01, 0x80, 0x01, 0x80, 0x01, 0x90, 0x19, 0x80, 0x00, 0x9F, 0xF1, 0x00, 0x00, 0xC3, 0x83, 0x00,
//  0x00, 0x60, 0x03, 0x00, 0x04, 0x70, 0x06, 0x00, 0x0C, 0x3C, 0x3C, 0x00, 0x18, 0x1F, 0xF0, 0x1C,
//  0x00, 0x00, 0x00, 0x0C, 0x00, 0x00, 0x08, 0x00, 0x00, 0x08, 0x0C, 0x00, 0x00, 0x08, 0x0C, 0x00,
//  0x00, 0x08, 0x04, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
//};


const unsigned char PROGMEM akc [] = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x1F, 0xF8, 0x00, 0x00, 0x00, 0x00, 0xFC, 0x3F, 0x00, 0x00, 0x00, 0x03, 0xC0, 0x03, 0xC0, 0x00,
  0x00, 0x07, 0x00, 0x00, 0xE0, 0x00, 0x00, 0x1C, 0x00, 0x00, 0x38, 0x00, 0x07, 0xFF, 0xC0, 0x03,
  0xFF, 0xE0, 0x3F, 0x01, 0xF0, 0x0F, 0x80, 0xFC, 0x70, 0x00, 0x3C, 0x3C, 0x00, 0x1E, 0xC0, 0x00,
  0x6F, 0xF0, 0x00, 0x1B, 0xC0, 0x00, 0x47, 0xE0, 0x00, 0x33, 0xC0, 0x00, 0xC6, 0x60, 0x00, 0x23,
  0xC0, 0x01, 0x84, 0x20, 0x00, 0x63, 0xC0, 0x01, 0x84, 0x20, 0x00, 0xC3, 0xC0, 0x03, 0x0C, 0x30,
  0x00, 0xC3, 0x40, 0x03, 0x0C, 0x30, 0x01, 0x82, 0x60, 0x06, 0x08, 0x10, 0x01, 0x86, 0x60, 0x04,
  0x18, 0x18, 0x03, 0x06, 0x30, 0x0C, 0x30, 0x0C, 0x02, 0x0C, 0x18, 0x18, 0x60, 0x06, 0x06, 0x18,
  0x0E, 0x18, 0xC0, 0x03, 0x04, 0x70, 0x07, 0xFF, 0x80, 0x01, 0xEF, 0xE0, 0x07, 0xFE, 0x00, 0x00,
  0x7F, 0xE0, 0x06, 0x00, 0x00, 0x00, 0x00, 0x60, 0x06, 0x00, 0x00, 0x00, 0x00, 0x60, 0x02, 0x00,
  0x00, 0x00, 0x00, 0x40, 0x03, 0x0F, 0xFF, 0xFF, 0xF0, 0xC0, 0x03, 0x0F, 0xFF, 0xFF, 0xF0, 0xC0,
  0x01, 0x8C, 0x00, 0x00, 0x31, 0x80, 0x01, 0x86, 0x00, 0x00, 0x61, 0x80, 0x00, 0xC3, 0x80, 0x01,
  0xC3, 0x00, 0x00, 0x61, 0xC0, 0x03, 0x86, 0x00, 0x00, 0x70, 0x78, 0x1E, 0x0E, 0x00, 0x00, 0x38,
  0x1F, 0xF8, 0x1C, 0x00, 0x00, 0x1C, 0x00, 0x00, 0x38, 0x00, 0x00, 0x07, 0x00, 0x00, 0xE0, 0x00,
  0x00, 0x03, 0xC0, 0x03, 0xC0, 0x00, 0x00, 0x00, 0xFC, 0x3F, 0x00, 0x00, 0x00, 0x00, 0x1F, 0xF8,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

const unsigned char PROGMEM frame0 [] = {0x00, 0x01, 0x40, 0x00, 0x00, 0x1F, 0xF8, 0x00, 0x00, 0x7C, 0x1E, 0x00, 0x00, 0xC0, 0x03, 0x00, 0x03, 0x80, 0x01, 0xC0, 0x06, 0x00, 0x00, 0x60, 0x0C, 0x00, 0x00, 0x30, 0x08, 0x00, 0x00, 0x10, 0x18, 0x00, 0x00, 0x18, 0x10, 0x00, 0x00, 0x0C, 0x3F, 0xFF, 0xFF, 0xFC, 0x3F, 0xFF, 0x7F, 0xFC, 0x3F, 0xFE, 0xFF, 0xFE, 0x7F, 0xFF, 0x7F, 0xFC, 0x7F, 0xFE, 0x7F, 0xFE, 0x4F, 0xFE, 0x7F, 0xFE, 0x6F, 0xFE, 0x7F, 0xF2, 0x63, 0xF8, 0x1F, 0xC6, 0x20, 0xA0, 0x02, 0x04, 0x20, 0x00, 0x00, 0x04, 0x20, 0x00, 0x00, 0x84, 0x30, 0x00, 0x01, 0x8C, 0x10, 0x00, 0x03, 0x18, 0x0C, 0x1C, 0x7C, 0x30, 0x04, 0x07, 0xE0, 0x20, 0x06, 0x00, 0x00, 0x60, 0x03, 0x00, 0x00, 0xC0, 0x01, 0xC0, 0x03, 0x80, 0x00, 0x70, 0x0E, 0x00, 0x00, 0x3E, 0xFC, 0x00, 0x00, 0x03, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00};

const unsigned char PROGMEM frame1 [] = {0x00, 0x01, 0x4B, 0xF8, 0x00, 0x1F, 0xFF, 0xFC, 0x00, 0xFF, 0xFF, 0xF8, 0x1F, 0xFE, 0xFF, 0xF8, 0x3F, 0xFE, 0xFF, 0xF8, 0x3F, 0xFE, 0xFF, 0xF8, 0x1F, 0xFE, 0x7F, 0xF0, 0x1F, 0xFE, 0x3F, 0xF0, 0x1F, 0xFE, 0x3F, 0xD8, 0x1F, 0xFC, 0x0F, 0x08, 0x33, 0xF8, 0x00, 0x0C, 0x20, 0x20, 0x00, 0x04, 0x60, 0x70, 0x00, 0x06, 0x20, 0x78, 0x1E, 0x04, 0x60, 0x78, 0x08, 0x06, 0x40, 0x20, 0x00, 0x06, 0x60, 0x00, 0x00, 0x02, 0x60, 0x00, 0x00, 0x06, 0x20, 0x00, 0x00, 0x24, 0x20, 0x00, 0x00, 0x64, 0x20, 0x00, 0x00, 0xC4, 0x30, 0x00, 0x01, 0x8C, 0x10, 0x00, 0x03, 0x18, 0x0C, 0x00, 0x7C, 0x30, 0x04, 0x03, 0xE0, 0x20, 0x06, 0x00, 0x00, 0x60, 0x03, 0x00, 0x00, 0xC0, 0x01, 0xC0, 0x03, 0x80, 0x00, 0x70, 0x0E, 0x00, 0x00, 0x3E, 0xFC, 0x00, 0x00, 0x03, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00};

const unsigned char PROGMEM frame2 [] = {0x00, 0x01, 0x40, 0x00, 0x00, 0x1F, 0xF8, 0x00, 0x00, 0x7C, 0x1E, 0x00, 0x00, 0xC0, 0x03, 0x00, 0x03, 0x80, 0x01, 0xC0, 0x06, 0x00, 0x00, 0x60, 0x0C, 0x00, 0x00, 0x30, 0x08, 0x00, 0x00, 0x10, 0x18, 0x00, 0x00, 0x18, 0x10, 0x00, 0x00, 0x0C, 0x3F, 0xFF, 0xFF, 0xFC, 0x3F, 0xFF, 0x7F, 0xFC, 0x3F, 0xFE, 0xFF, 0xFE, 0x7F, 0xFF, 0x7F, 0xFC, 0x7F, 0xFE, 0x7F, 0xFE, 0x4F, 0xFE, 0x7F, 0xFE, 0x6F, 0xFE, 0x7F, 0xF2, 0x63, 0xF8, 0x1F, 0xC6, 0x20, 0xA0, 0x02, 0x04, 0x20, 0x00, 0x00, 0x04, 0x20, 0x00, 0x00, 0x84, 0x30, 0x00, 0x01, 0x8C, 0x10, 0x00, 0x03, 0x18, 0x0C, 0x1C, 0x7C, 0x30, 0x04, 0x07, 0xE0, 0x20, 0x06, 0x00, 0x00, 0x60, 0x03, 0x00, 0x00, 0xC0, 0x01, 0xC0, 0x03, 0x80, 0x00, 0x70, 0x0E, 0x00, 0x00, 0x3E, 0xFC, 0x00, 0x00, 0x03, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00};



SettingsMenu::SettingsMenu()
  : Menu(MENU_HELLO)


{}

bool SettingsMenu::update() {
}

void SettingsMenu::button1() {
  switchMenu(MENU_SETTINGS_CLOCKFACE);
}

void SettingsMenu::button3() {
  switchMenu(MENU_SETTINGS_CLOCKFACE);
}

void SettingsMenu::button2() {
  switchMenu(MENU_SETTINGS_CLOCKFACE);
}



void SettingsMenu::draw(Adafruit_SSD1306* display) const {


  display->drawBitmap(6, 6, akc, 48, 48, 1);
  //  display->drawBitmap(0, 0, saat_bmp, 64, 64, 1);
  //  display->drawBitmap  (15, 12, sun, 32, 32, 1);
  display->setTextColor(WHITE);
  display->setTextSize(1);
  display->setCursor(85, 0);
  display->print(F("Hello"));
  display->setCursor(75, 10);
  display->print(F("I'm your"));
  display->setCursor(80, 20);
  display->print(F("watchX!"));
  display->setCursor(73, 35);
  display->print(F("Press any"));
  display->setCursor(83, 45);
  display->print(F("button"));
  display->setCursor(62, 55);
  display->print(F("to continue"));
  digitalWrite(13, HIGH);
  digitalWrite(13, LOW);
  digitalWrite(6, HIGH);
  digitalWrite(6, LOW);
  digitalWrite(13, HIGH);
  delay(30);
  digitalWrite(13, LOW);
  digitalWrite(6, HIGH);
  delay(30);
  digitalWrite(6, LOW);
//  for (int i=0; i<=1;i++){
//    if(i==1){
//  tone(9,784);
//  delay(100);
//  noTone(9);
//  tone(9,784);
//  delay(400);
//  noTone(9);
//  }
//  }



}
