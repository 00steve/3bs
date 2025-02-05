#include "../../include/menu/ioMapMenu.h"


void IOMapMenu::Draw(){

}

MenuAction* IOMapMenu::GetAction(){
    return NULL;
}

IOMapMenu::IOMapMenu(unsigned int editConfig){
    inputEditable = MathUtil::Bit(editConfig,IOMap_InputEdit);
    outputEditable = MathUtil::Bit(editConfig,IOMap_OutputEdit);
}

void IOMapMenu::Run(){
    
}