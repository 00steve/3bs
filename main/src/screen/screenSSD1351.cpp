#include "../../include/screen/screenSSD1351.h"


void ScreenSSD1351::clearDisplay(){
    screen.fillScreen(BLACK);
}

void ScreenSSD1351::display(){
    //screen.display();
}

void ScreenSSD1351::drawCircle(int16_t x0, int16_t y0, int16_t r, uint16_t color){
    screen.drawCircle(x0, y0, r, color);
}

void ScreenSSD1351::drawRect(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint16_t color){
    screen.drawRect(x0, y0, x1, y1, color);
}

void ScreenSSD1351::fillRect(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint16_t color){
    screen.fillRect(x0, y0, x1, y1, color);
}

void ScreenSSD1351::println(char* val){
    screen.println(val);
}

void ScreenSSD1351::println(double val){
    screen.println(val);
}

ScreenSSD1351::ScreenSSD1351(){
    initialized = false;
}

ScreenSSD1351::ScreenSSD1351(int screenWidth, int screenHeight, int csPin, int dcPin, int mosiPin, int sclkPin, int rstPin) {
    initialized = true;
    pinMode(csPin,OUTPUT);
    //screen = Adafruit_SSD1351(screenWidth, screenHeight, csPin, dcPin, mosiPin, sclkPin, rstPin);
    screen = Adafruit_SSD1351(screenWidth, screenHeight, &SPI, csPin, dcPin, rstPin);
    screen.begin();
}

void ScreenSSD1351::setCursor(int col, int row){
    screen.setCursor(col, row);
}

void ScreenSSD1351::setTextSize(int size){
    screen.setTextSize(size);
}

void ScreenSSD1351::setTextColor(uint16_t c){
    screen.setTextColor(c);
}