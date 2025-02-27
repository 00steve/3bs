#include "../../include/screen/screenSSD1306.h"

void ScreenSSD1306::clearDisplay(){
    screen.clearDisplay();
}

void ScreenSSD1306::display(){
    screen.display();
}

void ScreenSSD1306::drawCircle(int16_t x0, int16_t y0, int16_t r, uint16_t color){
    screen.drawCircle(x0, y0, r, color);
}

void ScreenSSD1306::drawRect(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint16_t color){
    screen.drawRect(x0, y0, x1, y1, color);
}

void ScreenSSD1306::fillRect(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint16_t color){
    screen.fillRect(x0, y0, x1, y1, color);
}

void ScreenSSD1306::println(char* val){
    screen.println(val);
}

void ScreenSSD1306::println(double val){
    screen.println(val);
}

ScreenSSD1306::ScreenSSD1306(){
    initialized = false;

}

ScreenSSD1306::ScreenSSD1306(int screenWidth, int screenHeight, TwoWire* Wire, int oledReset) {
    initialized = true;
    screen = Adafruit_SSD1306(screenWidth, screenHeight, Wire, oledReset);

    int screenAddress = 0x3c;
    if(!screen.begin(SSD1306_SWITCHCAPVCC, screenAddress)) {
        Serial.println(F("SSD1306 allocation failed"));
        for(;;); // Don't proceed, loop forever
    }
}

void ScreenSSD1306::setCursor(int col, int row){
    screen.setCursor(col, row);
}

void ScreenSSD1306::setTextSize(int size){
    screen.setTextSize(size);
}

void ScreenSSD1306::setTextColor(uint16_t c){
    screen.setTextColor(c);
}