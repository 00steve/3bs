#ifndef UTILS_MenuConfiguration
#define UTILS_MenuConfiguration


#include "staticList.h"
#include "input.h"
//#include "program.h"

class MenuConfiguration{
public:
    StaticList<Input*> inputs = StaticList<Input*>(10);

};

#endif