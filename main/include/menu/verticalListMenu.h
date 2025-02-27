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
    double currentHideScroll = 0;
    MenuAction* currentMenuAction = NULL;
    double currentPixelScroll = 0;
    AnimationSlew* hideSlew;
    unsigned int previousCurrentIndex = 0;
    unsigned int rowPixelSize = 15;
    AnimationSlew* scrollSlew;
    Trigger triggerDown;
    Trigger triggerSelect;
    Trigger triggerUp;

    void SetCurrentPixelScroll();
    void Setup();

public:
    void Configure(MenuConfiguration newConfiguration);
    void Draw();
    MenuAction* GetAction();
    void Run();
    void SetInputAll(Input* newDownInput, Input* newUpInput, Input* newSelectInput);
    void SetInputDown(Input* newInput);
    void SetInputSelect(Input* newInput);
    void SetInputUp(Input* newInput);
    VerticalListMenu();
    VerticalListMenu(Input* newDownInput, Input* newUpInput, Input* newSelectInput);
    VerticalListMenu(MenuConfiguration newConfiguration);
};



#endif