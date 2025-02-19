#include "../include/menuAction.h"

void* MenuAction::GetTarget(){
    return target;
}

MenuAction::MenuAction(unsigned int menuActionType) : 
        menuActionType(menuActionType) {
}

unsigned int MenuAction::MenuActionType(){
    return menuActionType;
}

void MenuAction::SetTarget(void* newTarget){
    target = newTarget;
}