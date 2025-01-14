#ifndef INPUTJACK_HTeensyAnalog
#define INPUTJACK_HTeensyAnalog

#include "../input.h"
#include "../mathUtil.h"

class InputJackTeensyAnalog : public Input {
private:
    unsigned int        analogReadPin;
    double              inputValue = 0;
    const double        pinValueMax = 1024;
    const double        pinValueMin = 0;
    double              pinValue;


public:
    InputJackTeensyAnalog(char* name, unsigned int analogReadPin);
    bool SampleValue();
    double PinValueMax();
    double PinValueMin();
    double Value();
    double* ValueRef();

};

#endif