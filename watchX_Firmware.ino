#include <SPI.h>
#include <Wire.h>
#include <EEPROM.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "Buttons.h"
#include "Menu.h"
#include "Menu_1.h"
#include "Menu_2.h"
#include "Menu_PressStart.h"
#include "Menu_3.h"
#include "Menu_Clockface.h"
#include "State.h"
#include "Kalman.h"

#define NEXT_PIN   10
#define PREV_PIN 11
#define SELECT_PIN 8

#define OLED_DC     A3
#define OLED_CS     A5
#define OLED_RESET  A4
#define WIDTH      128
#define HEIGHT     64
Adafruit_SSD1306 display(OLED_DC, OLED_RESET, OLED_CS);

Button btnNext(NEXT_PIN);
Button btnSelect(SELECT_PIN);
Button btnPrev (PREV_PIN);


void buttonNextPressed() {
  btnNext.interrupt();
}
void buttonPrevPressed() {
  btnPrev.interrupt();
}
void buttonSelectPressed() {
  btnSelect.interrupt();
}

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
int sec = 40;

uint32_t timer;
uint8_t i2cData[14]; // Buffer for I2C data

State state;
Menu* menu = NULL;

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

//  while (i2cRead(0x75, i2cData, 1));
//  if (i2cData[0] != 0x68) { // Read "WHO_AM_I" register
//    //    Serial.print(F("Error reading sensor"));
//    while (1);
//  }

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

}
void GyroGame(void) {


  getIMU();

  drawIMUbasic();
}

void setup(void) {
  randomSeed(analogRead(A3));
  display.begin(SSD1306_SWITCHCAPVCC);
  display.clearDisplay();
  display.setRotation(0);
  pinMode(9, OUTPUT);
  tone(9, 1000, 300);


  // Setup buttons
  pinMode(NEXT_PIN, INPUT_PULLUP);
  pinMode(PREV_PIN, INPUT_PULLUP);
  pinMode(SELECT_PIN, INPUT_PULLUP);
  pinMode(13, OUTPUT);
  pinMode(6, OUTPUT);
  

  switchMenu(MENU_AT);
  setRandom();

}

void loop() {
  
  bool draw = false;

  // Buttons
  if (btnNext.update() && btnNext.read()) {
    menu->button1();
    draw = true;
  }
  if (btnPrev.update() && btnPrev.read()) {
    menu->button3();
    draw = true;
  }
  if (btnSelect.update() && btnSelect.read()) {
    menu->button2();
    draw = true;
  }

  // Switch menu if indicated.
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

  double dt = (double)(micros() - state.now.second()) / 1000000; // Calculate delta time
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
  int a = (sec - (millis() - state.now.second()) / 1000.0);
  display.drawRect(66, 0, 62, 64, WHITE);
  display.drawCircle(targetX - 1, targetY - 1, 3, WHITE);
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.print("pitch: ");
  display.setCursor(0, 10);
  display.print(pitch);
  display.setCursor(0, 20);
  display.print("roll: ");
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
  display.fillCircle(posX, posY, 2, WHITE);

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
    display.setCursor(40, 15);
    display.print("Score:");
    display.print(success_counter);
    display.setCursor(30, 42);
    display.print("Press Button");

  }
}
