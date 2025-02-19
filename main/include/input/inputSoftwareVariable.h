#ifndef UTILS_INPUT_SoftwareVariable
#define UTILS_INPUT_SoftwareVariable

#include <string>
#include "../input.h"

class InputSoftwareVariable : public Input {
private:
    double* variableRef;

public:
    InputSoftwareVariable(char* name, double* variable);
    bool SampleValue();
    double Value();
    double* ValueRef();

};



#endif