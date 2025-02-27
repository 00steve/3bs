#include "../../include/menuOption/menuVariable.h"

void MenuVariable::Draw(AABB limits,bool selected){

    if(selected){
        screen->fillRect(limits.min.x,limits.min.y,limits.max.x,limits.max.y,1);
        screen->fillRect(limits.max.x+2 ,limits.min.y,limits.max.x + 64,limits.max.y,1);
        screen->setTextColor(0);
        screen->setCursor(limits.max.x+4, limits.min.y+3);
        screen->println((*variableRef));
    } else {
        screen->drawRect(limits.min.x,limits.min.y,limits.max.x,limits.max.y,1);
        screen->setTextColor(1);
    }
    screen->setCursor(limits.min.x+2, limits.min.y+3);
    screen->println(label);

}

MenuAction* MenuVariable::GetAction(){
    return NULL;
}

MenuVariable::MenuVariable(char* label, double* variableRef) :
        label(label),
        variableRef(variableRef){  
}
