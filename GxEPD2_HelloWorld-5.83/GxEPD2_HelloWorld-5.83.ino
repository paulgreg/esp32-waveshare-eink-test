// GxEPD2_HelloWorld.ino by Jean-Marc Zingg

// see GxEPD2_wiring_examples.h for wiring suggestions and examples
// if you use a different wiring, you need to adapt the constructor parameters!

// uncomment next line to use class GFX of library GFX_Root instead of Adafruit_GFX
//#include <GFX.h>

#include <GxEPD2_BW.h>
#include <GxEPD2_3C.h>
#include <Fonts/FreeMonoBold9pt7b.h>

// select the display class and display driver class in the following file (new style):
#include "GxEPD2_display_selection_new_style.h"

// or select the display constructor line in one of the following files (old style):
//#include "GxEPD2_display_selection.h"
//#include "GxEPD2_display_selection_added.h"

// alternately you can copy the constructor from GxEPD2_display_selection.h or GxEPD2_display_selection_added.h to here
// e.g. for Wemos D1 mini:
// GxEPD2_3C<GxEPD2_583c_Z83, MAX_HEIGHT_3C(GxEPD2_583c_Z83)> display(GxEPD2_583c_Z83(/*CS=10*/ SS, /*DC=*/ 8, /*RST=*/ 9, /*BUSY=*/ 7)); // GDEW0583Z83 648x480, GD7965

// #include "bitmaps/Bitmaps3c648x480.h" // 5.83" b/w/r


void setup()
{
  Serial.begin(115200); 
  display.init(115200);
  delay(500);

  Serial.println("Start");
  helloWorld();
  Serial.println("Done");
  display.hibernate();
}

const char HelloWorld[] = "Hello World!";

void helloWorld()
{
  Serial.println("Hello World 1");
  display.setRotation(1);
  display.setFont(&FreeMonoBold9pt7b);
  display.setTextColor(GxEPD_BLACK);
  int16_t tbx, tby; uint16_t tbw, tbh;
  Serial.println("Hello World 2");
  display.getTextBounds(HelloWorld, 0, 0, &tbx, &tby, &tbw, &tbh);
  // center the bounding box by transposition of the origin:
  uint16_t x = ((display.width() - tbw) / 2) - tbx;
  uint16_t y = ((display.height() - tbh) / 2) - tby;
  Serial.println("Hello World 3");
  display.setFullWindow();
  display.firstPage();
  Serial.println("Hello World 4");
  do
  {
    Serial.println("Hello World loop");
    display.fillScreen(GxEPD_WHITE);
    display.setCursor(x, y);
    display.print(HelloWorld);
  }
  while (display.nextPage());
  Serial.println("Hello World 5");
}

void loop() {};
