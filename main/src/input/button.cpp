#include "../../include/input/button.h"

/*
Button::Button(char* name, unsigned int digitalReadPin) : 
        Input(name),
        digitalReadPin(digitalReadPin),
        pinValue(0){
    pinMode(digitalReadPin, INPUT);
}*/

Button::Button(char* name, unsigned int digitalReadPin, unsigned int digitalPowerPin) : 
        Input(name),
        digitalPowerPin(digitalPowerPin),
        digitalReadPin(digitalReadPin),
        pinValue(0){
    pinMode(digitalReadPin, INPUT);
    pinMode(digitalPowerPin, OUTPUT);
    digitalWrite(digitalPowerPin, HIGH);
}

Button::Button(char* name, unsigned int digitalReadPin, unsigned int digitalPowerPin, bool nONC) : 
        Input(name),
        digitalPowerPin(digitalPowerPin),
        digitalReadPin(digitalReadPin),
        nONC(nONC),
        pinValue(0){
    pinMode(digitalReadPin, INPUT);
    pinMode(digitalPowerPin, OUTPUT);
    digitalWrite(digitalPowerPin, HIGH);
}

bool Button::SampleValue(){
    pinValue = digitalReadFast(digitalReadPin) != nONC;
    return true;
}

double Button::Value(){
    return pinValue;
}

double Button::ValueMax(){
    return 1;
}

double Button::ValueMin(){
    return 0;
}

double* Button::ValueRef(){
    return &pinValue;
}