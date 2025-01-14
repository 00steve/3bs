#include "../include/menu.h"

//static members
Adafruit_SSD1306* Menu::display;

void* Menu::ActionHandlerObject(){
    return actionHandlerObject;
}

bool Menu::AddOption(MenuOption* newOption){
    return options.Add(newOption);
}

StaticList<MenuOption*> Menu::Options(){
    return options;
}

bool Menu::ScrollLoop(){
    return scrollLoop;
}

bool Menu::ScrollLoop(bool loop){
    return scrollLoop = loop;
}

void Menu::SetDisplay(Adafruit_SSD1306* newDisplay){
    display = newDisplay;
}

void Menu::SetMenuAction(void (*newMenuActionHAndler)(MenuAction* menuAction,void* object), void* newActionHandlerObject){
    menuActionHandler = newMenuActionHAndler;
    actionHandlerObject = newActionHandlerObject;
}

