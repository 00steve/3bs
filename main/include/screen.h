
#ifndef UTILS_Screen
#define UTILS_Screen

#include "Adafruit_GFX.h"

class Screen{
protected:
    bool initialized = false;

public:
    virtual void clearDisplay();
    virtual void display();	
    virtual void drawCircle(int16_t x0, int16_t y0, int16_t r, uint16_t color);
    virtual void drawRect(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint16_t color);
    virtual void fillRect(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint16_t color);
    virtual void println(char* val);
    virtual void println(double val);
    virtual void setCursor(int col, int row);
    virtual void setTextSize(int size);
    virtual void setTextColor(uint16_t c);
};


#endif