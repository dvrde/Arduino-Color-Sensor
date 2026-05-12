#include <Wire.h>
#include "Adafruit_TCS34725.h"

//#include "pitches.h"

/* Example code for the Adafruit TCS34725 breakout library */

/* Connect SCL    to analog 5
 Connect SDA    to analog 4
 Connect VDD    to 3.3V DC
 Connect GROUND to common ground */

/* Initialise with default values (int time = 2.4ms, gain = 1x) */
// Adafruit_TCS34725 tcs = Adafruit_TCS34725();

/* Initialise with specific int time and gain values */
Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_2_4MS, TCS34725_GAIN_1X);

void setup(void) {
  Serial.begin(9600);

  if (tcs.begin()) {
    Serial.println("Found sensor");
  } 
  else {
    Serial.println("No TCS34725 found ... check your connections");
    while (1);
  }

  tone(8, 1760);
  delay(240);
  tone(8, 196);
  delay(250);
  tone(8, 247);
  delay(250);
  noTone(8);

  // Now we're ready to get readings!
}

void loop(void) {
  uint16_t r, g, b, c, colorTemp, lux;

  tcs.getRawData(&r, &g, &b, &c);
  colorTemp = tcs.calculateColorTemperature(r, g, b);
  //  lux = tcs.calculateLux(r, g, b);

  //  Serial.print("Color Temp: "); Serial.print(colorTemp, DEC); Serial.print(" K - ");
  //  Serial.print("Lux: "); Serial.print(lux, DEC); Serial.print(" - ");
  //  Serial.print("R: "); Serial.print(r, DEC); Serial.print(" ");
  //  Serial.print("G: "); Serial.print(g, DEC); Serial.print(" ");
  //  Serial.print("B: "); Serial.print(b, DEC); Serial.print(" ");
  //  Serial.print("C: "); Serial.print(c, DEC); Serial.print(" ");
  //  Serial.println(" ");

  //  if (r>40000) { // we see major red
  //    tone(8, 1760);
  //  } else if (g>20000) { // major green
  //    tone(8, 196);
  //  } else if (b>20000) {
  //    tone(8, 247);
  //  } else {
  //    noTone(8);
  //  }
  
  tone(8,map(colorTemp,0,10000,100,1700));

}

