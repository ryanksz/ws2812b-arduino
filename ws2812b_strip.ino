//This is a simple script for a ws2812b led script 
//Use with pin 5
//along with 5v and ground
#include <FastLED.h>
#include <time.h>
#include <stdlib.h>

#define LED_PIN     5
//this may be different from where u buy it
#define NUM_LEDS    60
#define BRIGHTNESS  32
#define LED_TYPE    WS2811
#define COLOR_ORDER GRB
CRGB leds[NUM_LEDS];

#define UPDATES_PER_SECOND 100


void setup() {
  // put your setup code here, to run once:
  delay( 3000 ); // power-up safety delay
    FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
    FastLED.setBrightness(  BRIGHTNESS );

}
//loop through the strip
void loop() {
  // put your main code here, to run repeatedly:
  int r = randomRed();
  int b = randomBlue();
  int g = randomGreen();
  delay(10000);
  for(int i = 0; i < NUM_LEDS; i++) {
    leds[i].setRGB( r, g, b);
        FastLED.show();
  }
  
}

//generate random red value
int randomRed(){
  int r = rand() % 255;
  return r;
}
//generate random green value
int randomGreen(){
  int g = rand() % 255;
  return g;
}
//generate random blue value
int randomBlue(){
  int b = rand() % 255;
  return b;
}
