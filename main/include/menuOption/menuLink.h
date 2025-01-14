#ifndef UTILS_Menu_Option_MenuLink
#define UTILS_Menu_Option_MenuLink

#include "../menuOption.h"
#include "../menuAction.h"

class MenuLink : public MenuOption {
private:
    AABB dimensions;
    char* label;
    void* linkedMenu;
    MenuAction* menuAction;

public:
    AABB Dimensions();
    void Draw(AABB limits, bool selected);
    MenuAction* GetAction();
    MenuLink(char* label);
    MenuLink(char* label, void* linkedMenu);
    void SetupMenuAction();

};

#endif