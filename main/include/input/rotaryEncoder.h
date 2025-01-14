#ifndef Utils_RotaryEncoder
#define Utils_RotaryEncoder

#include "../input.h"
#include <Wire.h>

/* this class can only handle up to 8 instances of a rotary encoder, but
why in the shit fuck would you ever need more than 8 instances of a rotary
encoder? Sucks for you, dweeb. */

class RotaryEncoder : public Input {
private:
    int clkPin;
    bool clkPinHigh;
    static int currentRotaryEncoderID;
    int dtPin;
    bool dtPinHigh;
    int encoderState;
    int lastPinChange = -1;
    int maxValue;
    int minValue;
    int rotaryEncoderID;
    double value;
    int vccPin;

    //map each instance of a rotary encoder to a static 
    static RotaryEncoder** rotaryEncoderReference;
protected:
    void Init(int vccPin, int clkPin, int dtPin, int value, int minValue, int maxValue);

    static void OnInterrupt(int rotaryEncoderReferenceID,bool isClkPin);
    static void OnInterrupt0Clk();
    static void OnInterrupt0Dt();

public:
    RotaryEncoder(char* name, int vccPin, int clkPin, int dtPin);
    RotaryEncoder(char* name, int vccPin, int clkPin, int dtPin, int value);
    RotaryEncoder(char* name, int vccPin, int clkPin, int dtPin, int value, int minValue, int maxValue);
    bool SampleValue();
    double Value();
    double* ValueRef();
    char ValueType();

};

#endif