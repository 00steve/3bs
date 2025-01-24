#include "../../include/menuOption/menuVariable.h"

void MenuVariable::Draw(AABB limits,bool selected){

    if(selected){
        display->fillRect(limits.min.x,limits.min.y,limits.max.x + 64,limits.max.y,WHITE);
        display->setTextColor(BLACK);
        display->setCursor(limits.max.x+2, limits.min.y+3);
        display->println((*variableRef));
    } else {
        display->drawRect(limits.min.x,limits.min.y,limits.max.x,limits.max.y,WHITE);
        display->setTextColor(WHITE);
    }
    display->setCursor(limits.min.x+2, limits.min.y+3);
    display->println(label);

}

MenuAction* MenuVariable::GetAction(){
    return NULL;
}

MenuVariable::MenuVariable(char* label, double* variableRef) :
        label(label),
        variableRef(variableRef){  
}
