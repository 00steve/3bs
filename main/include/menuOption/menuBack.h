#ifndef UTILS_Menu_Option_MenuBack
#define UTILS_Menu_Option_MenuBack

#include "../menuOption.h"
#include "../menuAction.h"

class MenuBack : public MenuOption {
private:
    AABB dimensions;
    char* label;
    MenuAction* menuAction;

public:
    AABB Dimensions();
    void Draw(AABB limits, bool selected);
    MenuAction* GetAction();
    MenuBack(char* label);
    void SetupMenuAction();

};

#endif