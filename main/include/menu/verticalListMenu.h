#ifndef UTILS_Menu_VerticalListMenu
#define UTILS_Menu_VerticalListMenu

#include "../menu.h"
#include "../menuAction.h"
#include "../trigger.h"
#include "../animation.h"


class VerticalListMenu : public Menu, public Animation {
private:
    
    Input* inputDown = NULL;
    Input* inputSelect = NULL;
    Input* inputUp = NULL;
    unsigned int currentIndex = 0;
    MenuAction* currentMenuAction = NULL;
    double currentPixelScroll = 0;
    unsigned int previousCurrentIndex = 0;
    unsigned int rowPixelSize = 15;
    AnimationSlew* scrollSlew;
    Trigger triggerDown;
    Trigger triggerSelect;
    Trigger triggerUp;

    void SetCurrentPixelScroll();

public:
    void Draw();
    MenuAction* GetAction();
    void Run();
    void SetInputDown(Input* newInput);
    void SetInputSelect(Input* newInput);
    void SetInputUp(Input* newInput);
    VerticalListMenu();

};



#endif