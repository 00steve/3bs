#include "../include/menuOption.h"

Adafruit_SSD1306* MenuOption::display = NULL;

Adafruit_SSD1306* MenuOption::Display(){
    return display;
}

void MenuOption::SetDisplay(Adafruit_SSD1306* newDisplay){
    display = newDisplay;
}