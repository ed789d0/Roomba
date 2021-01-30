/*
  A trivial Arduino sketch to mimic iRobot Virtual Wall for Roomba, this time with low power enhancements
  YouTube: https://www.youtube.com/mkmeorg Website, Forum and store are at http://mkme.org
  Parts needed
  Arduino Nano https://amzn.to/2EaMzZI
  IR LED https://amzn.to/2QOqUgE
  Resistor https://amzn.to/2EhIbsf
  ----------------------------------------------------------------
  Based on information found at:
  http://sites.google.com/site/irobotcreate2/createanirbeacon
  
  Uses "A Multi-Protocol Infrared Remote Library for the Arduino":
  http://www.arcfn.com/2009/08/multi-protocol-infrared-remote-library.html
*/
#include <avr/sleep.h>
#include <avr/power.h>
#include <IRremote.h>

// Initiate IRremote on Pin 3.
IRsend irsend;

void setup()
{
  irsend.enableIROut(38); // Lib function
  // turns off stuff that's not needed for the circuit, saving power
  ADCSRA = 0;
  power_adc_disable();
  power_spi_disable();
  power_twi_disable();
}

void loop()
{
  irsend.mark(1000);
  irsend.space(1000);
}
