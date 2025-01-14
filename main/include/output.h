#ifndef UTILS_Output
#define UTILS_Output

#include <string>
#include "mathUtil.h"

class Output {
private:
    double outputValueMax = 1;
    double outputValueMin = 0;

protected:

public:
    double OutputValueMax();
    double OutputValueMin();
    void SetOutputValueLimits(double newOutputValueMin, double newOutputValueMax);
    void SetOutputValueMax(double newOutputValueMax);
    void SetOutputValueMin(double newOutputValueMin);
    virtual bool SetOutputValue(double newOutputValue) = 0;

};

#endif