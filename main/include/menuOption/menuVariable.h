#ifndef UTILS_MenuVariable
#define UTILS_MenuVariable

#include "../menuOption.h"

class MenuVariable : public MenuOption {
private:
    char* label;
    double* variableRef;

public:
    void Draw(AABB limits,bool selected);
    MenuAction* GetAction();
    MenuVariable(char* label, double* variableRef);
};

#endif