#ifndef UTILS_Screen
#define UTILS_Screen

#include "Adafruit_GFX.h"

#define	BLACK           0x0000
#define	BLUE            0x001F
#define	RED             0xF800
#define	GREEN           0x07E0
#define CYAN            0x07FF
#define MAGENTA         0xF81F
#define YELLOW          0xFFE0  
#define WHITE           0xFFFF

class Screen{
protected:
    int height = 0;    
    bool initialized = false;
    int width = 0;

public:
    virtual void clearDisplay();
    virtual void display();	
    virtual void drawCircle(int16_t x0, int16_t y0, int16_t r, uint16_t color);
    virtual void drawRect(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint16_t color);
    virtual void fillRect(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint16_t color);
    virtual int getHeight(){
        return height;
    }
    virtual int getWidth(){
        return width;
    }
    virtual void println(char* val);
    virtual void println(double val);
    Screen(int width, int height) : 
        height(height),
        width(width){
    }
    virtual void setCursor(int col, int row);
    virtual void setTextSize(int size);
    virtual void setTextColor(uint16_t c);
};

#endif