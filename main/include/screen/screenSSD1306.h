#ifndef UTILS_Screen_SSD1306
#define UTILS_Screen_SSD1306

#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
#include "../screen.h"


class ScreenSSD1306 : public Screen{
private:
    Adafruit_SSD1306 screen;

public:
    void clearDisplay();
    void currentColor(int16_t);//if setting color as black and white, maybe? 
    void display();	
    void drawCircle(int16_t x0, int16_t y0, int16_t r, uint16_t color);
    void drawRect(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint16_t color);
    void fillRect(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint16_t color);
    void println(char* val);
    void println(double val);
    ScreenSSD1306();
    ScreenSSD1306(int screenWidth, int screenHeight, TwoWire* Wire, int oledReset);
    void setCursor(int col, int row);
    void setTextSize(int size);
    void setTextColor(uint16_t c);
};

#endif