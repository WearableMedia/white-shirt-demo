#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif

#define PIN 1

// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(31, PIN, NEO_GRB + NEO_KHZ800);

// IMPORTANT: To reduce NeoPixel burnout risk, add 1000 uF capacitor across
// pixel power leads, add 300 - 500 Ohm resistor on first pixel's data input
// and minimize distance between Arduino and first pixel.  Avoid connecting
// on a live circuit...if you must, connect GND first.
int myPixels[12] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
//int myPixels[12] = {2, 3, 8, 9, 14, 15, 18, 19, 23, 24, 28, 29};//The pixels in the curve
int dimPixels[19] = {0, 1, 4, 5, 6, 7, 10, 11, 12, 13, 16, 17, 20, 21, 22, 25, 26, 27, 30};

float b = 0;
float s = 0.1;
void setup() {
  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
#if defined (__AVR_ATtiny85__)
  if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
#endif
  // End of trinket special code


  strip.begin();
  strip.setBrightness(150);
  strip.show(); // Initialize all pixels to 'off'
}

void loop() {


  int randomDelay = random(3, 20);
  int randomPulse = random(100, 1000);

  int randomBrightness = random(150, 255);

  for (int brightness = 0; brightness < randomBrightness; brightness++) {
    // Some example procedures showing how to display to the pixels:
    for (int i = 0; i < 31; i++) {
      strip.setPixelColor(i, 0, 0, 0);
    }
    for (int i = 0; i < 12; i++) {
      strip.setPixelColor(myPixels[i], brightness, brightness, brightness);
    }

    strip.show();
    delay(randomDelay);
  }

  for (int brightness = randomBrightness; brightness >= 0; brightness--) {
    for (int i = 0; i < 31; i++) {
      strip.setPixelColor(i, 0, 0, 0);
    }
    for (int i = 0; i < 12; i++) {
      strip.setPixelColor(myPixels[i], brightness, brightness, brightness);
    }
    strip.show();
    delay(randomDelay);
  }

  delay(randomPulse);

  strip.setPixelColor(0, 0, 255, 255);

}

