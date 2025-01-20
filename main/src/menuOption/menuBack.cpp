#include "../../include/menuOption/menuBack.h"

AABB MenuBack::Dimensions(){
    return dimensions;
}

void MenuBack::Draw(AABB limits, bool selected){
    if(selected){
        display->fillRect(limits.min.x,limits.min.y,limits.max.x,limits.max.y,WHITE);
        display->setTextColor(BLACK);
    } else {
        display->drawRect(limits.min.x,limits.min.y,limits.max.x,limits.max.y,WHITE);
        display->setTextColor(WHITE);
    }
    display->setCursor(limits.min.x+2, limits.min.y+3);
    display->println(label);
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