#ifndef UTILS_Output
#define UTILS_Output

#include <string>
#include "mathUtil.h"
#include "cstrUtil.h"

class Output : public CStrUtil {
private:
    double outputValueMax = 1;
    double outputValueMin = 0;

protected:

public:
    Output(char* outputName) : 
            CStrUtil(outputName){
    };
    double OutputValueMax();
    double OutputValueMin();
    void SetOutputValueLimits(double newOutputValueMin, double newOutputValueMax);
    void SetOutputValueMax(double newOutputValueMax);
    void SetOutputValueMin(double newOutputValueMin);
    virtual bool SetOutputValue(double newOutputValue) = 0;

};

#endif