#include "../../include/input/inputSoftwareVariable.h"

//InputSoftwareVariable::InputSoftwareVariable(String inputName, double* variable) : 
InputSoftwareVariable::InputSoftwareVariable(char* name,double* variable) : 
        Input(name),
        variableRef(variable){

}

bool InputSoftwareVariable::SampleValue(){
    return variableRef != NULL;
}

double InputSoftwareVariable::Value(){
    return *variableRef;
}

double* InputSoftwareVariable::ValueRef(){
    return variableRef;
}