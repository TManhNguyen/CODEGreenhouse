#line 1 "c:\\Users\\thanhlongb\\Documents\\Arduino\\code-iot-firmware\\led.cpp"
//#include <Adafruit_NeoPixel.h>
//#ifdef __AVR__
// #include <avr/power.h>
//#endif
#include "led.h"

#define PIN_LED_CONTROL 5
#define LED_COUNT 15

//Adafruit_NeoPixel strip = Adafruit_NeoPixel(
//    LED_COUNT, 
//    PIN_LED_CONTROL, 
//    NEO_GRB + NEO_KHZ800
//);
//
//void initLedControl() {
//  // Parameter 1 = number of pixels in strip
//  // Parameter 2 = Arduino pin number (most are valid)
//  // Parameter 3 = pixel type flags, add together as needed:
//  //   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//  //   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//  //   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//  //   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//  //   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)
//  strip.begin();
//  strip.setBrightness(255);
//  strip.show(); // Initialize all pixels to 'off'
//}
//
//// Input a value 0 to 255 to get a color value.
//// The colours are a transition r - g - b - back to r.
//uint32_t Wheel(byte WheelPos) {
// WheelPos = 255 - WheelPos;
// if(WheelPos < 85) {
//   return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
// }
// if(WheelPos < 170) {
//   WheelPos -= 85;
//   return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
// }
// WheelPos -= 170;
// return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
//}
//
//
//// Fill the dots one after the other with a color
//void colorWipe(uint32_t c, uint8_t wait) {
// for(uint16_t i=0; i<strip.numPixels(); i++) {
//   strip.setPixelColor(i, c);
//   strip.show();
//   delay(wait);
// }
//}
//
//void rainbow(uint8_t wait) {
// uint16_t i, j;
//
// for(j=0; j<256; j++) {
//   for(i=0; i<strip.numPixels(); i++) {
//     strip.setPixelColor(i, Wheel((i+j) & 255));
//   }
//   strip.show();
//   delay(wait);
// }
//}
//
//// Slightly different, this makes the rainbow equally distributed throughout
//void rainbowCycle(uint8_t wait) {
// uint16_t i, j;
//
// for(j=0; j<256*5; j++) { // 5 cycles of all colors on wheel
//   for(i=0; i< strip.numPixels(); i++) {
//     strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
//   }
//   strip.show();
//   delay(wait);
// }
//}
//
////Theatre-style crawling lights.
//void theaterChase(uint32_t c, uint8_t wait) {
// for (int j=0; j<10; j++) {  //do 10 cycles of chasing
//   for (int q=0; q < 3; q++) {
//     for (uint16_t i=0; i < strip.numPixels(); i=i+3) {
//       strip.setPixelColor(i+q, c);    //turn every third pixel on
//     }
//     strip.show();
//
//     delay(wait);
//
//     for (uint16_t i=0; i < strip.numPixels(); i=i+3) {
//       strip.setPixelColor(i+q, 0);        //turn every third pixel off
//     }
//   }
// }
//}
//
////Theatre-style crawling lights with rainbow effect
//void theaterChaseRainbow(uint8_t wait) {
// for (int j=0; j < 256; j++) {     // cycle all 256 colors in the wheel
//   for (int q=0; q < 3; q++) {
//     for (uint16_t i=0; i < strip.numPixels(); i=i+3) {
//       strip.setPixelColor(i+q, Wheel( (i+j) % 255));    //turn every third pixel on
//     }
//     strip.show();
//
//     delay(wait);
//
//     for (uint16_t i=0; i < strip.numPixels(); i=i+3) {
//       strip.setPixelColor(i+q, 0);        //turn every third pixel off
//     }
//   }
// }
//}
//
//void setStripColor(uint32_t color) {
//  for (uint16_t i=0; i < strip.numPixels(); ++i) {
//    strip.setPixelColor(i, color);       
//  }
//  strip.show();
//  Serial.println("Color set");
//}

CRGB leds[LED_COUNT];

void initLedControl() {
  FastLED.addLeds<WS2812, PIN_LED_CONTROL, GRB>(leds, LED_COUNT).setCorrection(TypicalLEDStrip); 
  FastLED.setBrightness(200); 
}

void setLight(bool status) {
  for (int i = 0; i < LED_COUNT; ++i) {
    if (status) {
      leds[i] = CRGB::Purple;
    } else {
      leds[i] = CRGB::Black;      
    }
  }
  FastLED.show();
}

void ledControlManager() {
//  rainbowCycle(20);
}
