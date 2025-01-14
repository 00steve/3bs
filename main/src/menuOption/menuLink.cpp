#include "../../include/menuOption/menuLink.h"

AABB MenuLink::Dimensions(){
    return dimensions;
}

void MenuLink::Draw(AABB limits, bool selected){
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

MenuAction* MenuLink::GetAction(){
    return menuAction;
}

MenuLink::MenuLink(char* label) : 
        label(label),
        linkedMenu(NULL){  
    SetupMenuAction();
}

MenuLink::MenuLink(char* label, void* linkedMenu) : 
        label(label),
        linkedMenu(linkedMenu){
    SetupMenuAction();
}

void MenuLink::SetupMenuAction(){
    if(!linkedMenu){
        menuAction = NULL;
        return;
    } 
    menuAction = new MenuAction(MENUACTION_MenuLink);
    menuAction->SetTarget(linkedMenu);
}