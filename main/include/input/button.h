#ifndef BUTTON_H
#define BUTTON_H

#include "../input.h"
#include <Wire.h>

#define BUTTON_NORMALLY_OPEN false
#define BUTTON_NORMALLY_CLOSED true

class Button : public Input {
private:
    unsigned int digitalPowerPin;
    unsigned int digitalReadPin;
    //normally open or normally closed.
    //normally open == no power until the button is pressed
    //normally closed == power is cut while the button is pressed
    bool nONC = BUTTON_NORMALLY_OPEN; 
    double pinValue;

public:
    //Button(char* name, unsigned int digitalReadPin);
    Button(char* name, unsigned int digitalReadPin, unsigned int digitalPowerPin);
    Button(char* name, unsigned int digitalReadPin, unsigned int digitalPowerPin, bool nONC);
    bool SampleValue();
    double Value();
    double ValueMax();
    double ValueMin();
    double* ValueRef();

};




#endif