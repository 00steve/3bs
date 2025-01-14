#include "../include/ioMap.h"

bool IOMap::SetInput(Input *input){
    this->input = input;
    return true;
}

bool IOMap::SetOutput(Output *output){
    this->output = output;
    return true;
}

bool IOMap::Update(){
    if(!input || !output) return false;
    output->SetOutputValue(input->Value());
    return true;
}