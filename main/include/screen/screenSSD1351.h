#ifndef UTILS_Screen_SSD1306
#define UTILS_Screen_SSD1306

#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1351.h>
#include "../screen.h"

#define	BLACK           0x0000
#define	BLUE            0x001F
#define	RED             0xF800
#define	GREEN           0x07E0
#define CYAN            0x07FF
#define MAGENTA         0xF81F
#define YELLOW          0xFFE0  
#define WHITE           0xFFFF

class ScreenSSD1351 : public Screen{
private:
    Adafruit_SSD1351 screen = Adafruit_SSD1351(0,0,0);

public:
    void clearDisplay();
    void currentColor(int16_t);//if setting color as black and white, maybe? 
    void display();	
    void drawCircle(int16_t x0, int16_t y0, int16_t r, uint16_t color);
    void drawRect(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint16_t color);
    void fillRect(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint16_t color);
    void println(char* val);
    void println(double val);
    ScreenSSD1351();
    ScreenSSD1351(int screenWidth, int screenHeight, int csPin, int dcPin, int mosiPin, int sclkPin, int rstPin);
    void setCursor(int col, int row);
    void setTextSize(int size);
    void setTextColor(uint16_t c);
};

#endif