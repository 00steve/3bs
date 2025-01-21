#ifndef UTILS_Menu_H
#define UTILS_Menu_H

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>


#define MENU_INPUT_UP 0
#define MENU_INPUT_DOWN 1
#define MENU_INPUT_LEFT 2
#define MENU_INPUT_RIGHT 3
#define MENU_INPUT_FORWARD 4
#define MENU_INPUT_BACK 5

#define MENU_INPUT_TYPE_COUNT 6

#define MENU_INPUT_UP_DEFAULT 1
#define MENU_INPUT_DOWN_DEFAULT 0
#define MENU_INPUT_FORWARD_DEFAULT 2


#include "menuConfiguration.h"
#include "menuOption.h"
#include "menuAction.h"
#include "staticList.h"
#include "input.h"


class Menu{
private:
    StaticList<MenuOption*> options = StaticList<MenuOption*>(50);
    bool scrollLoop = false;

protected:
    void* actionHandlerObject = NULL;
    static Adafruit_SSD1306* display;
    void (*menuActionHandler)(MenuAction* menuAction,void* object);

public:
    void* ActionHandlerObject();
    bool AddOption(MenuOption* newOption);
    virtual void Draw() = 0;
    virtual MenuAction* GetAction() = 0;
    StaticList<MenuOption*> Options();
    virtual void Run() = 0;
    bool ScrollLoop();
    bool ScrollLoop(bool loop);
    static void SetDisplay(Adafruit_SSD1306* newDisplay);
    void SetMenuAction(void (*newMenuActionHandler)(MenuAction* menuAction,void* object), void* newActionHandlerObject);
};

#endif