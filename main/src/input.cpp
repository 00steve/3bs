#include "../include/input.h"


double Input::InputValueMax(){
    return inputValueMax;
}

double Input::InputValueMin(){
    return inputValueMin;
}

char* Input::Name(){
    return CStrUtil::Value();
}

void Input::SetInputValueLimits(double newInputValueMin, double newInputValueMax){
    SetInputValueMax(newInputValueMax);
    SetInputValueMin(newInputValueMin);
}

void Input::SetInputValueMax(double newInputValueMax){
    inputValueMax = newInputValueMax;
}

void Input::SetInputValueMin(double newInputValueMin){
    inputValueMin = newInputValueMin;
}

double Input::VoltageValueMax(){
    return voltageValueMax;
}

double Input::VoltageValueMin(){
    return voltageValueMin;
}