#include "../../include/menuOption/menuBack.h"

AABB MenuBack::Dimensions(){
    return dimensions;
}

void MenuBack::Draw(AABB limits, bool selected){
    if(selected){
        screen->fillRect(limits.min.x,limits.min.y,limits.max.x,limits.max.y,WHITE);
        screen->setTextColor(0);
    } else {
        screen->drawRect(limits.min.x,limits.min.y,limits.max.x,limits.max.y,WHITE);
        screen->setTextColor(WHITE);
    }
    screen->setCursor(limits.min.x+2, limits.min.y+3);
    screen->println(label);
}

MenuAction* MenuBack::GetAction(){
    return menuAction;
}

MenuBack::MenuBack(char* label) : 
        label(label){  
    SetupMenuAction();
}

void MenuBack::SetupMenuAction(){
    menuAction = new MenuAction(MENUACTION_MenuBack);
}