// EnableInterrupt Simple example sketch. Demonstrates operation on a single pin of your choice.
// See https://github.com/GreyGnome/EnableInterrupt and the README.md for more information.
//#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "RTClib.h"
///#include <Wire.h>
#include <MPU6050.h>

// Uncomment this block to use hardware SPI
#define OLED_DC     A3
#define OLED_CS     A5
#define OLED_RESET  A4

#define BUTTON1 8
#define VOLTAGEDIV 0.5
#define BATTERYENERGY 4
#define BATTERYINPUT A11

Adafruit_SSD1306 display(OLED_DC, OLED_RESET, OLED_CS);
RTC_DS3231 rtc;
MPU6050 mpu;

int count = 0;
int state = 0;
int progMode=1;

DateTime usbtime;
DateTime now;
uint32_t usbmillis;
float batteryLevel = 0;
float usbbatteryLevel = 0;


void setup() {
  rtc.begin();
  rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));

  display.begin(SSD1306_SWITCHCAPVCC);

  pinMode(BUTTON1, INPUT_PULLUP);

  // turn off accelerometer
  mpu.begin(MPU6050_SCALE_2000DPS, MPU6050_RANGE_2G);
  mpu.setSleepEnabled(true);

 // turnOffBluetooth();
  usbbatteryLevel = getBatteryPercent();

  display.setTextSize(1);
  display.setTextColor(WHITE);
}


float getBatteryPercent() {
  digitalWrite(BATTERYENERGY, HIGH);
  delay(50);
  float voltage = analogRead(BATTERYINPUT);
  voltage = (voltage / 1024) * 3.35;
  voltage = voltage / VOLTAGEDIV;
  delay(50);
  digitalWrite(BATTERYENERGY, LOW);
  batteryLevel = (voltage - 3.38) / 0.0084;
  return (batteryLevel);
}

void showBattery() {
  batteryLevel = getBatteryPercent();
  display.setCursor(0, 20);
  display.print("Bat:");
  display.print((int) batteryLevel);
  display.print("%");

  //uint32_t millissinceusb = millis() - usbmillis;
  TimeSpan rtcusb = rtc.now() - usbtime;
  display.setCursor(0, 30);
  display.print("SinceUSB:");
  float minsusb = rtcusb.totalseconds()/60;
  //millissinceusb/6000;
  display.print(minsusb);
  if (progMode > 9){
     display.print(" C");
  }
  display.setCursor(0, 40);
  display.print("BatChange:");
  float batdiff = (usbbatteryLevel - batteryLevel);
  display.print(batdiff);
  
//  int minsinceusb = 60 * (now.hour() - usbtime.hour()) + now.minute() - usbtime.minute();
  //  display.print(minsinceusb);
 // float batdiff = (usbbatteryLevel - batteryLevel);
  if (batdiff > 0 && minsusb > 0) {
    float minleft = batteryLevel * minsusb / batdiff;
    display.setCursor(0, 50);
    display.print("EstBatLifeMin:");
    display.print((int) minleft);
  }
}

void showTime(int colon) {
  display.setCursor(0, 0);
  now  = rtc.now();
  display.print(now.hour());
  if (colon > 0){
   display.print(":");
  }
  int m = now.minute();
  if (m < 10) {
    display.print(0);
  }
  display.print(m);
}

void showDate() {
  display.setCursor(0, 10);
  now  = rtc.now();

  display.print(now.year());
  display.print("/");
  display.print(now.month());
  display.print("/");
  display.print(now.day());
}


int lastButtonState = 0;     // previous state of the button


void loop() {
  int buttonState = digitalRead(BUTTON1);

  if (buttonState == LOW && lastButtonState==HIGH) {
    //&& buttonState != lastButtonState
    state = state+1;

    if (state > 2){
      state = 0;
    }
    delay(50);
  }
  lastButtonState = buttonState;

  display.clearDisplay();

  if (state == 0){
    showTime(0);
    drawGame();
  }else{
    if (state == 1){
    drawJapanese();
    }else{
      showTime(1);
      showDate();
      showBattery();
    }
  }

  display.display();

  setSleepStatusBasedonUSB();
  count++;
  count = count % 100000;

  
}

