#ifndef UTILS_Menu_IOMapMenu
#define UTILS_Menu_IOMapMenu

#include "../menu.h"
#include "../menuAction.h"
#include "../trigger.h"
#include "../animation.h"
#include "../ioMap.h"

#define IOMap_NoEdit 0
#define IOMap_InputEdit 1
#define IOMap_OutputEdit 2
#define IOMap_IOEdit 3

class IOMapMenu : public Menu, public Animation{
private:
    bool inputEditable;
    bool outputEditable;

public:
    void Draw();
    IOMapMenu(unsigned int editConfig);
    MenuAction* GetAction();
    void Run();

};


#endif