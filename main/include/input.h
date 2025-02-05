#ifndef UTILS_Input
#define UTILS_Input

#include <Arduino.h>
#include <string>
#include "cstrUtil.h"


class Input : public CStrUtil {
private:
    //sets and tells the end user the min and max values that can be sent from 
    //this input. If it is updated, the mapping from whatever hardware input 
    //values are updated to map to this new min and max value.
    double inputValueMax = 1;
    double inputValueMin = -1;

    //just used to tell the UI what the voltage min/max are, should be set based 
    //on the hardware of the specific implementing class. This is only to give the 
    //end user information, don't do shit with this that matters in the actual code.
    double voltageValueMax = 5;
    double voltageValueMin = -5;

public:
                    Input(char* inputName) : 
                            CStrUtil(inputName){
                    };
    double          InputValueMax();
    double          InputValueMin();
    char*           Name();
    //String GetName(){
     //   return name;
    //}
    virtual bool    SampleValue();
    void            SetInputValueLimits(double newInputValueMin, double newInputValueMax);
    void            SetInputValueMax(double newInputValueMax);
    void            SetInputValueMin(double newInputValueMin);
    virtual double  Value() = 0;
    virtual double* ValueRef() = 0;
    double          VoltageValueMax();
    double          VoltageValueMin();

};



#endif