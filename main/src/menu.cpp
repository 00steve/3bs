#include "../include/menu.h"

//static members

void* Menu::ActionHandlerObject(){
    return actionHandlerObject;
}

bool Menu::AddOption(MenuOption* newOption){
    return options.Add(newOption);
}

StaticList<MenuOption*> Menu::Options(){
    return options;
}

void Menu::RemoveAllOptions(){
    options.Clear();
}

bool Menu::ScrollLoop(){
    return scrollLoop;
}

bool Menu::ScrollLoop(bool loop){
    return scrollLoop = loop;
}

void Menu::SetMenuAction(void (*newMenuActionHAndler)(MenuAction* menuAction,void* object), void* newActionHandlerObject){
    menuActionHandler = newMenuActionHAndler;
    actionHandlerObject = newActionHandlerObject;
}

