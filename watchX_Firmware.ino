#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
//#include <Fonts\FreeMono9pt7b.h>
#include "Menu.h"
#include "Menu_Clockface.h"
#include "State.h"
#include "Clockface.h"
#include "Clockface_Pacman.h"
#include "Kalman.h"
#include "Buttons.h"

#define LEDL 13
#define LEDR 6

#define OLED_DC     A3
#define OLED_CS     A5
#define OLED_RESET  A4
#define WIDTH      128
#define HEIGHT     64

#define BUTTON_1   8
#define BUTTON_2  10
#define BUTTON_3  11
Button btn_1(BUTTON_1);
Button btn_2(BUTTON_2);
Button btn_3(BUTTON_3);

Adafruit_SSD1306 display(OLED_DC, OLED_RESET, OLED_CS);

const unsigned char PROGMEM wxlogo_bmp [] = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x80, 0x00, 0x00, 0x07,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xFC, 0x00, 0x00, 0xFE,
  0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0x00, 0x00, 0x00, 0x78, 0x00, 0x03, 0xFF, 0x00, 0x0F, 0xFC,
  0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0x00, 0x00, 0x00, 0x78, 0x00, 0x01, 0xFF, 0x80, 0x3F, 0xF8,
  0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0x00, 0x00, 0x00, 0x78, 0x00, 0x00, 0xFF, 0xC0, 0x7F, 0xF0,
  0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0x00, 0x00, 0x00, 0x78, 0x00, 0x00, 0x7F, 0xE0, 0x7F, 0xE0,
  0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0x00, 0x00, 0x00, 0x78, 0x00, 0x00, 0x3F, 0xE0, 0xFF, 0xC0,
  0xF1, 0xE3, 0xC3, 0xFF, 0xF8, 0xFF, 0xE1, 0xFF, 0xF8, 0x7F, 0xFF, 0x00, 0x3F, 0xF1, 0xFF, 0x80,
  0xF1, 0xE3, 0xC3, 0xFF, 0xF8, 0xFF, 0xE1, 0xFF, 0xF8, 0x7F, 0xFF, 0x00, 0x1F, 0xF9, 0xFF, 0x00,
  0xF1, 0xE3, 0xC3, 0xFF, 0xF8, 0xFF, 0xE1, 0xFF, 0xF8, 0x7F, 0xFF, 0x00, 0x0F, 0xFF, 0xFE, 0x00,
  0xF1, 0xE3, 0xC3, 0xFF, 0xF8, 0xFF, 0xE1, 0xFF, 0xF8, 0x7F, 0xFF, 0x00, 0x07, 0xEF, 0xFC, 0x00,
  0xF1, 0xE3, 0xC0, 0x00, 0x78, 0xF0, 0x01, 0xE0, 0x00, 0x78, 0x0F, 0x00, 0x03, 0xEF, 0xF8, 0x00,
  0xF1, 0xE3, 0xC0, 0x00, 0x78, 0xF0, 0x01, 0xE0, 0x00, 0x78, 0x0F, 0x00, 0x01, 0xDF, 0xF0, 0x00,
  0xF1, 0xE3, 0xC3, 0xFF, 0xF8, 0xF0, 0x01, 0xE0, 0x00, 0x78, 0x0F, 0x00, 0x00, 0xBF, 0xE0, 0x00,
  0xF1, 0xE3, 0xC3, 0xFF, 0xF8, 0xF0, 0x01, 0xE0, 0x00, 0x78, 0x0F, 0x00, 0x00, 0x7F, 0xD0, 0x00,
  0xF1, 0xE3, 0xC3, 0xFF, 0xF8, 0xF0, 0x01, 0xE0, 0x00, 0x78, 0x0F, 0x00, 0x00, 0xFF, 0xB0, 0x00,
  0xF1, 0xE3, 0xC3, 0xC0, 0x78, 0xF0, 0x01, 0xE0, 0x00, 0x78, 0x0F, 0x00, 0x01, 0xFF, 0x70, 0x00,
  0xF1, 0xE3, 0xC3, 0xC0, 0x78, 0xF0, 0x01, 0xE0, 0x00, 0x78, 0x0F, 0x00, 0x03, 0xFE, 0xF8, 0x00,
  0xFF, 0xFF, 0xC3, 0xFF, 0xF8, 0xFF, 0xE1, 0xFF, 0xF8, 0x78, 0x0F, 0x00, 0x07, 0xFE, 0xFC, 0x00,
  0xFF, 0xFF, 0xC3, 0xFF, 0xF8, 0xFF, 0xE1, 0xFF, 0xF8, 0x78, 0x0F, 0x00, 0x0F, 0xFF, 0xFE, 0x00,
  0xFF, 0xFF, 0xC3, 0xFF, 0xF8, 0xFF, 0xE1, 0xFF, 0xF8, 0x78, 0x0F, 0x00, 0x1F, 0xF9, 0xFF, 0x00,
  0xFF, 0xFF, 0xC3, 0xFF, 0xF8, 0xFF, 0xE1, 0xFF, 0xF8, 0x78, 0x0F, 0x00, 0x3F, 0xF0, 0xFF, 0x80,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7F, 0xE0, 0xFF, 0xC0,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xC0, 0x7F, 0xE0,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xFF, 0xC0, 0x3F, 0xF0,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xFF, 0x00, 0x1F, 0xF8,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xFE, 0x00, 0x0F, 0xFC,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F, 0xC0, 0x00, 0x03, 0xFE,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1C, 0x00, 0x00, 0x00, 0x1C,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

#define RESTRICT_PITCH // Comment out to restrict roll to Â±90deg instead - please read: http://www.freescale.com/files/sensors/doc/app_note/AN3461.pdf

Kalman kalmanX; // Create the Kalman instances
Kalman kalmanY;

double accX, accY, accZ;
double gyroX, gyroY, gyroZ;
int16_t tempRaw;

double gyroXangle, gyroYangle; // Angle calculate using the gyro only
double compAngleX, compAngleY; // Calculated angle using a complementary filter
double kalAngleX, kalAngleY; // Calculated angle using a Kalman filter

float roll;
float pitch;
int centerX = 64;
int centerY = 32;
float posX = centerX;
float posY = centerY;
int targetX;
int targetY;
int success_counter = 0;
long start_time;
boolean basic;
int sec = 10;

uint32_t timer;
uint8_t i2cData[14]; // Buffer for I2C data

State state;
Menu* menu = NULL;

void button1Pressed() {
  btn_1.interrupt();
}
void button2Pressed() {
  btn_2.interrupt();
}
void button3Pressed() {
  btn_3.interrupt();
}

void MPU() {

  Serial.begin(115200);
  Wire.begin();
  TWBR = ((F_CPU / 400000L) - 16) / 2; // Set I2C frequency to 400kHz

  i2cData[0] = 7; // Set the sample rate to 1000Hz - 8kHz/(7+1) = 1000Hz
  i2cData[1] = 0x00; // Disable FSYNC and set 260 Hz Acc filtering, 256 Hz Gyro filtering, 8 KHz sampling
  i2cData[2] = 0x00; // Set Gyro Full Scale Range to Â±250deg/s
  i2cData[3] = 0x00; // Set Accelerometer Full Scale Range to Â±2g
  while (i2cWrite(0x19, i2cData, 4, false)); // Write to all four registers at once
  while (i2cWrite(0x6B, 0x01, true)); // PLL with X axis gyroscope reference and disable sleep mode

  while (i2cRead(0x75, i2cData, 1));
  if (i2cData[0] != 0x68) { // Read "WHO_AM_I" register
    Serial.print(F("Error reading sensor"));
    while (1);
  }

  //  delay(100); // Wait for sensor to stabilize

  /* Set kalman and gyro starting angle */
  while (i2cRead(0x3B, i2cData, 6));
  accX = (i2cData[0] << 8) | i2cData[1];
  accY = (i2cData[2] << 8) | i2cData[3];
  accZ = (i2cData[4] << 8) | i2cData[5];

  // Source: http://www.freescale.com/files/sensors/doc/app_note/AN3461.pdf eq. 25 and eq. 26
  // atan2 outputs the value of -Ï€ to Ï€ (radians) - see http://en.wikipedia.org/wiki/Atan2
  // It is then converted from radians to degrees
#ifdef RESTRICT_PITCH // Eq. 25 and 26
  roll  = atan2(accY, accZ) * RAD_TO_DEG;
  pitch = atan(-accX / sqrt(accY * accY + accZ * accZ)) * RAD_TO_DEG;
#else // Eq. 28 and 29
  roll  = atan(accY / sqrt(accX * accX + accZ * accZ)) * RAD_TO_DEG;
  pitch = atan2(-accX, accZ) * RAD_TO_DEG;
#endif

  kalmanX.setAngle(roll); // Set starting angle
  kalmanY.setAngle(pitch);
  gyroXangle = roll;
  gyroYangle = pitch;
  compAngleX = roll;
  compAngleY = pitch;

  timer = micros();
  start_time = millis();
}
void GyroGame(void) {

  getIMU();

  drawIMUbasic();
}

void setup(void) {

  pinMode(LEDL, OUTPUT); // sets the digital pin as output
  pinMode(LEDR, OUTPUT); // sets the digital pin as output
  pinMode(BUTTON_1, INPUT_PULLUP);
  pinMode(BUTTON_2, INPUT_PULLUP);
  pinMode(BUTTON_3, INPUT_PULLUP);


  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC);
  display.clearDisplay();
  display.setRotation(0);
  tone(9, 1000, 300);
  display.display();
  display.clearDisplay();
  //display.setFont(&FreeMono9pt7b);


  randomSeed(analogRead(0));
  setRandom();
  MPU();
}

void loop() {

  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(15, 55);
//  for (int i = 0; i <= 10; i++)
//  {
//    if (i <= 10) {
//      digitalWrite(LEDL, HIGH);
//      delay(100);
//      digitalWrite(LEDL, LOW);
//      digitalWrite(LEDR, LOW);
//      delay(100);
//      digitalWrite(LEDR, HIGH);
//      digitalWrite(LEDL, HIGH);
//      delay(100);
//      digitalWrite(LEDL, LOW);
//      digitalWrite(LEDR, HIGH);
//      delay(100);
//      digitalWrite(LEDR, LOW);
//      display.drawBitmap(0, 0, wxlogo_bmp, 128, 32, 1);
//      //    display.display();
//      display.println("PRESS ANY BUTTON!");
//      delay(100);
//      display.display();
//      delay(100);
//      display.clearDisplay();
//      delay(100);
//      display.display();
//      display.setCursor(15, 55);
//    }
//  }

  bool draw = false;
  // Buttons
  if (btn_1.update() && btn_1.read()) {
    menu->button1();
    draw = true;
  }
//     if (btn_2.update() && btn_2.read()) {
//      menu->button2();
//      draw = true;
//    }
//     if (btn_3.update() && btn_3.read()) {
//      menu->button3();
//      draw = true;
//    }

  //   Hello text
  //  display.setTextSize(2);
  //  display.setTextColor(WHITE);
  //  for (int i = 32; i <= 35; i++)
  //  {
  //    digitalWrite(LEDL, HIGH);
  //    delay(200);
  //    digitalWrite(LEDL, LOW);
  //    digitalWrite(LEDR, LOW);
  //    delay(200);
  //    digitalWrite(LEDR, HIGH);
  //    digitalWrite(LEDL, HIGH);
  //    delay(200);
  //    digitalWrite(LEDL, LOW);
  //    digitalWrite(LEDR, HIGH);
  //    delay(200);
  //    digitalWrite(LEDR, LOW);
  //    display.setCursor(i, 25);
  //    display.print(F("Hello"));
  //    display.display();
  //    delay(1000);
  //  }
  //  display.clearDisplay();


  updateMenuSelection();

  // Update
  state.update();
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
void getIMU() {
  /* Update all the values */
  while (i2cRead(0x3B, i2cData, 14));
  accX = ((i2cData[0] << 8) | i2cData[1]);
  accY = ((i2cData[2] << 8) | i2cData[3]);
  accZ = ((i2cData[4] << 8) | i2cData[5]);
  tempRaw = (i2cData[6] << 8) | i2cData[7];
  gyroX = (i2cData[8] << 8) | i2cData[9];
  gyroY = (i2cData[10] << 8) | i2cData[11];
  gyroZ = (i2cData[12] << 8) | i2cData[13];

  double dt = (double)(micros() - timer) / 1000000; // Calculate delta time
  timer = micros();

  // Source: http://www.freescale.com/files/sensors/doc/app_note/AN3461.pdf eq. 25 and eq. 26
  // atan2 outputs the value of -Ï€ to Ï€ (radians) - see http://en.wikipedia.org/wiki/Atan2
  // It is then converted from radians to degrees
#ifdef RESTRICT_PITCH // Eq. 25 and 26
  roll  = atan2(accY, accZ) * RAD_TO_DEG;
  pitch = atan(-accX / sqrt(accY * accY + accZ * accZ)) * RAD_TO_DEG;
#else // Eq. 28 and 29
  roll  = atan(accY / sqrt(accX * accX + accZ * accZ)) * RAD_TO_DEG;
  pitch = atan2(-accX, accZ) * RAD_TO_DEG;
#endif

  double gyroXrate = gyroX / 131.0; // Convert to deg/s
  double gyroYrate = gyroY / 131.0; // Convert to deg/s

#ifdef RESTRICT_PITCH
  // This fixes the transition problem when the accelerometer angle jumps between -180 and 180 degrees
  if ((roll < -90 && kalAngleX > 90) || (roll > 90 && kalAngleX < -90)) {
    kalmanX.setAngle(roll);
    compAngleX = roll;
    kalAngleX = roll;
    gyroXangle = roll;
  } else
    kalAngleX = kalmanX.getAngle(roll, gyroXrate, dt); // Calculate the angle using a Kalman filter

  if (abs(kalAngleX) > 90)
    gyroYrate = -gyroYrate; // Invert rate, so it fits the restriced accelerometer reading
  kalAngleY = kalmanY.getAngle(pitch, gyroYrate, dt);
#else
  // This fixes the transition problem when the accelerometer angle jumps between -180 and 180 degrees
  if ((pitch < -90 && kalAngleY > 90) || (pitch > 90 && kalAngleY < -90)) {
    kalmanY.setAngle(pitch);
    compAngleY = pitch;
    kalAngleY = pitch;
    gyroYangle = pitch;
  } else
    kalAngleY = kalmanY.getAngle(pitch, gyroYrate, dt); // Calculate the angle using a Kalman filter

  if (abs(kalAngleY) > 90)
    gyroXrate = -gyroXrate; // Invert rate, so it fits the restriced accelerometer reading
  kalAngleX = kalmanX.getAngle(roll, gyroXrate, dt); // Calculate the angle using a Kalman filter
#endif

  gyroXangle += gyroXrate * dt; // Calculate gyro angle without any filter
  gyroYangle += gyroYrate * dt;
  //gyroXangle += kalmanX.getRate() * dt; // Calculate gyro angle using the unbiased rate
  //gyroYangle += kalmanY.getRate() * dt;

  compAngleX = 0.93 * (compAngleX + gyroXrate * dt) + 0.07 * roll; // Calculate the angle using a Complimentary filter
  compAngleY = 0.93 * (compAngleY + gyroYrate * dt) + 0.07 * pitch;

  // Reset the gyro angle when it has drifted too much
  if (gyroXangle < -180 || gyroXangle > 180)
    gyroXangle = kalAngleX;
  if (gyroYangle < -180 || gyroYangle > 180)
    gyroYangle = kalAngleY;
}

void setRandom() {
  targetX = random(68, 125);
  targetY = random(2, 61);
}

void drawIMUbasic() {
  int a = (sec - (millis() - start_time) / 1000.0);
  display.drawRect(66, 0, 62, 64, WHITE);
  display.drawRect(targetX - 2, targetY - 2, 6, 6, WHITE);
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.print("p: ");
  display.setCursor(0, 10);
  display.print(pitch);
  display.setCursor(0, 20);
  display.print("r: ");
  display.setCursor(0, 30);
  display.print(roll);
  display.setCursor(0, 40);
  display.print("score: ");
  display.setCursor(37, 40);
  display.print(success_counter);
  display.setCursor(0, 50);
  display.print(a);
  display.print("s");



  posX += roll / 10.0;
  posY -= pitch / 10.0;
  posX = constrain(posX, 67, 126);
  posY = constrain(posY, 1, 62);
  display.fillCircle(posX, posY, 4, WHITE);

  if (posX > (targetX - 2) && posX < (targetX + 2) && posY > (targetY - 2) && posY < (targetY + 2)) {
    success_counter++;
    digitalWrite(6, HIGH);
    setRandom();
    tone(9, 1000, 100);
  }
  else {
    digitalWrite(6, LOW);
  }
  if (a <= 0) {

    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0, 0);
    display.print("Your score: ");
    display.print(success_counter);
    display.setCursor(10, 10);
    display.print("Press BUTTON 1");

  }


}
