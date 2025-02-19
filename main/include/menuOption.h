#ifndef UTILS_Menu_MenuOption
#define UTILS_Menu_MenuOption

#define CCTC CStrUtil::ConstCStrToCStr
#define MENU_OPTION_TYPE_UNDEFINED 0
#define MENU_OPTION_TYPE_MENULINK 1

#include <Adafruit_GFX.h>
#include "screen.h"
#include "aabb.h"
#include "cstrUtil.h"
#include "menuAction.h"


class MenuOption{
private:
    char optionTypeID = MENU_OPTION_TYPE_UNDEFINED;

protected:
    static Screen* screen;

public:
    //static Screen* Screen();
    virtual void Draw(AABB limits,bool selected) = 0;
    static void SetScreen(Screen* newScreen);
    virtual MenuAction* GetAction() = 0;

};

#endif