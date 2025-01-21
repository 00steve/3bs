#include "../../include/menu/verticalListMenu.h"

void VerticalListMenu::Draw(){
    unsigned int optionCount = 4;
    unsigned int i = 0;//currentIndex;// > Options().Count()-optionCount ? Options().Count()-optionCount : currentIndex;
    unsigned int length = Options().Count();
    unsigned int sS = (int)scrollSlew->currentValue;
    AABB drawBox = AABB(0,0-sS,60,rowPixelSize-1);
    while(i < (currentIndex+optionCount+1) && i < length){
        Options()[i]->Draw(drawBox,i == currentIndex);
        ++i;
        drawBox.min.y += rowPixelSize;
    }
    
}

MenuAction* VerticalListMenu::GetAction(){
    return NULL;
}

void VerticalListMenu::Run(){
    
    if(triggerDown.Fire()){
        switch(ScrollLoop()){
        case 0:
            currentIndex ? --currentIndex : 0;
            break;
        case 1:
            if(!currentIndex){
                currentIndex = Options().Count()-1;
            } else {
                --currentIndex;
            }
            break;
        }
        SetCurrentPixelScroll();
    }
    if(triggerUp.Fire()){
        ++currentIndex;
        if(currentIndex == Options().Count()){
            currentIndex = ScrollLoop() ? 0 : Options().Count()-1;
        }
        SetCurrentPixelScroll();
    }
    if(triggerSelect.Fire()){
        currentMenuAction = Options()[currentIndex]->GetAction();
    } else {
        currentMenuAction = NULL;
    }
    if(actionHandlerObject && currentMenuAction && menuActionHandler){
        menuActionHandler(currentMenuAction, actionHandlerObject);
    }
    Animation::Run();
    
}

void VerticalListMenu::SetCurrentPixelScroll(){
    currentPixelScroll = (double)currentIndex * rowPixelSize;
}

void VerticalListMenu::SetInputAll(Input* newDownInput, Input* newUpInput, Input* newSelectInput){
    SetInputDown(newDownInput);
    SetInputUp(newUpInput);
    SetInputSelect(newSelectInput);
}

void VerticalListMenu::SetInputDown(Input* newInput){
    inputDown = newInput;
    triggerDown = Trigger(inputDown->ValueRef(),.9);
}

void VerticalListMenu::SetInputSelect(Input* newInput){
    inputSelect = newInput;
    triggerSelect = Trigger(inputSelect->ValueRef(),.9);
}

void VerticalListMenu::SetInputUp(Input* newInput){
    inputUp = newInput;
    triggerUp = Trigger(inputUp->ValueRef(),.9);
}

void VerticalListMenu::Setup(){
    scrollSlew = AddSlew(&currentPixelScroll,CURVE_LINEAR,.15);
}

VerticalListMenu::VerticalListMenu(){
    Setup();
}

VerticalListMenu::VerticalListMenu(Input* newDownInput, Input* newUpInput, Input* newSelectInput){
    Setup();
    SetInputAll(newDownInput,newUpInput,newSelectInput);
}
