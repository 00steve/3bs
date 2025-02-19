#include "../../include/input/inputJackTeensyAnalog.h"


InputJackTeensyAnalog::InputJackTeensyAnalog(char* name, unsigned int analogReadPin) : 
        Input(name),
        analogReadPin(analogReadPin),
        pinValueMax(1024),
        pinValueMin(0){
    pinMode(analogReadPin,INPUT);
}

double InputJackTeensyAnalog::PinValueMax(){
    return pinValueMax;
}

double InputJackTeensyAnalog::PinValueMin(){
    return pinValueMin;
}

bool InputJackTeensyAnalog::SampleValue(){
    pinValue = analogRead(analogReadPin);
    inputValue = MathUtil::ValueMap(pinValue, pinValueMin, pinValueMax, InputValueMin(), InputValueMax());
    return true;
}

double InputJackTeensyAnalog::Value(){
    return inputValue;
}

double* InputJackTeensyAnalog::ValueRef(){
    return &inputValue;
}