#include <EnableInterrupt.h>
#include <avr/sleep.h>


bool IsUSBConnected() {
  return (UDADDR & _BV(ADDEN));
}


void interruptFunction() {
  display.ssd1306_command(SSD1306_DISPLAYON);
}

void sleepNow()         // here we put the arduino to sleep
{
  lastButtonState=LOW;
  display.ssd1306_command(SSD1306_DISPLAYOFF);
  /* Now is the time to set the sleep mode. In the Atmega8 datasheet
     http://www.atmel.com/dyn/resources/prod_documents/doc2486.pdf on page 35
     there is a list of sleep modes which explains which clocks and
     wake up sources are available in which sleep mode.

     In the avr/sleep.h file, the call names of these sleep modes are to be found:

     The 5 different modes are:
         SLEEP_MODE_IDLE         -the least power savings
         SLEEP_MODE_ADC
         SLEEP_MODE_PWR_SAVE
         SLEEP_MODE_STANDBY
         SLEEP_MODE_PWR_DOWN     -the most power savings

     For now, we want as much power savings as possible, so we
     choose the according
     sleep mode: SLEEP_MODE_PWR_DOWN

  */
  set_sleep_mode(SLEEP_MODE_PWR_DOWN);   // sleep mode is set here

  sleep_enable();          // enables the sleep bit in the mcucr register
  // so sleep is possible. just a safety pin

  /* Now it is time to enable an interrupt. We do it here so an
     accidentally pushed interrupt button doesn't interrupt
     our running program. if you want to be able to run
     interrupt code besides the sleep function, place it in
     setup() for example.

     In the function call attachInterrupt(A, B, C)
     A   can be either 0 or 1 for interrupts on pin 2 or 3.

     B   Name of a function you want to execute at interrupt for A.

     C   Trigger mode of the interrupt pin. can be:
                 LOW        a low level triggers
                 CHANGE     a change in level triggers
                 RISING     a rising edge of a level triggers
                 FALLING    a falling edge of a level triggers

     In all but the IDLE sleep modes only LOW can be used.
  */
  enableInterrupt(BUTTON1, interruptFunction, CHANGE);

  sleep_mode();            // here the device is actually put to sleep!!
  // THE PROGRAM CONTINUES FROM HERE AFTER WAKING UP

  sleep_disable();         // first thing after waking from sleep:
  // disable sleep...
  disableInterrupt(BUTTON1);      // disables interrupt 0 on pin 2 so the
  // wakeUpNow code will not be executed
  // during normal running time.
  //state=0;

}


void setSleepStatusBasedonUSB() {
  if (IsUSBConnected()) { // check if USB is connected.
    progMode=10;
   
    if (count >= 2000) {
      count = 0;
      display.ssd1306_command(SSD1306_DISPLAYOFF);
    }
    if (digitalRead(BUTTON1) == 0) {
      display.ssd1306_command(SSD1306_DISPLAYON);
    }
  } else {
    if (progMode > 0){
      progMode=progMode-1;
    }
    if (progMode == 1){
    //   usbmillis = millis();
       usbtime = rtc.now();
       usbbatteryLevel = getBatteryPercent();//record battery level after USB has been removed
    }
    if (count >= 100) {
      delay(500);     // this delay is needed, the sleep
      count = 0;
      sleepNow();     // sleep function called here
    }
  }
}
