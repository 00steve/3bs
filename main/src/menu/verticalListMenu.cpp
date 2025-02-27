#include "../../include/menu/verticalListMenu.h"

void VerticalListMenu::Configure(MenuConfiguration newConfiguration){
    //SetInputDown(newConfiguration.inputs[MENU_INPUT_DOWN]);
    //SetInputSelect(newConfiguration.inputs[MENU_INPUT_FORWARD]);
    //SetInputUp(newConfiguration.inputs[MENU_INPUT_UP]);
}

void VerticalListMenu::Draw(){
    unsigned int optionCount = 4;
    unsigned int i = 0;//currentIndex;// > Options().Count()-optionCount ? Options().Count()-optionCount : currentIndex;
    unsigned int length = Options().Count();
    unsigned int sS = (int)scrollSlew->currentValue;
    unsigned int hS = (int)hideSlew->currentValue;
    AABB drawBox = AABB(hS,0-sS,60-hS,rowPixelSize-1);
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
    if(!newInput) return;
    triggerDown = Trigger(inputDown->ValueRef(),.9);
}

void VerticalListMenu::SetInputSelect(Input* newInput){
    inputSelect = newInput;
    if(!newInput) return;
    triggerSelect = Trigger(inputSelect->ValueRef(),.9);
}

void VerticalListMenu::SetInputUp(Input* newInput){
    inputUp = newInput;
    if(!newInput) return;
    triggerUp = Trigger(inputUp->ValueRef(),.9);
}

void VerticalListMenu::Setup(){
    scrollSlew = AddSlew(&currentPixelScroll,CURVE_LINEAR,.15);
    hideSlew = AddSlew(&currentHideScroll,CURVE_LINEAR,1);
}

VerticalListMenu::VerticalListMenu(){
    Setup();
}

VerticalListMenu::VerticalListMenu(Input* newDownInput, Input* newUpInput, Input* newSelectInput){
    Setup();
    SetInputAll(newDownInput,newUpInput,newSelectInput);
}

VerticalListMenu::VerticalListMenu(MenuConfiguration newConfiguration){
    Setup();
    Configure(newConfiguration);

}