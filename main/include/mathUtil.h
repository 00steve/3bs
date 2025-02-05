#ifndef UTIL_Math
#define UTIL_Math

#include <Arduino.h>
#include "aabb.h"

class MathUtil {
private:

public:
    //static bool IsInteger(std::string string);
    //static bool IsNumeric(std::string string);
    //static bool IsNumeric(std::string string,bool ignoreCommas,bool& hasDecimal);
    static bool Bit(unsigned int input, unsigned int bitPosition);
    static double RandomDouble(double min, double max);
    //static float RandomFloat(float min,float max);
    //static unsigned int RandomUnsignedInt(unsigned int min, unsigned int max);
    static double ValueMap(double inputValue, double inputMin, double inputMax, double outputMin, double outputMax);
};



#endif