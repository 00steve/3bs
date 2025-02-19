#ifndef UTILS_IOMap
#define UTILS_IOMap

#include <string>
#include "mathUtil.h"
#include "input.h"
#include "output.h"

class IOMap {
private:
    Input* input = NULL;
    Output* output = NULL;

public:
    bool SetInput(Input *input);
    bool SetOutput(Output *output);
    bool Update();
};

#endif