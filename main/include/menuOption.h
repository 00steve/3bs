#ifndef UTILS_Menu_MenuOption
#define UTILS_Menu_MenuOption

#define CCTC CStrUtil::ConstCStrToCStr
#define MENU_OPTION_TYPE_UNDEFINED 0
#define MENU_OPTION_TYPE_MENULINK 1

#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
#include "aabb.h"
#include "cstrUtil.h"
#include "menuAction.h"


class MenuOption{
private:
    char optionTypeID = MENU_OPTION_TYPE_UNDEFINED;

protected:
    static Adafruit_SSD1306* display;//reference to the true display

public:
    static Adafruit_SSD1306* Display();
    virtual void Draw(AABB limits,bool selected) = 0;
    static void SetDisplay(Adafruit_SSD1306* newDisplay);
    virtual MenuAction* GetAction() = 0;

};

#endif