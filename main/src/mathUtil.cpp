#include "../include/mathUtil.h"



bool MathUtil::Bit(unsigned int input, unsigned int bitPosition){
    return (input & (1 << bitPosition)) != 0;
}

/*
bool MathUtil::IsInteger(std::string string){
    bool decimal;
    return IsNumeric(string, true, decimal) && !decimal;
}

bool MathUtil::IsNumeric(std::string string){
    bool decimal;
    return IsNumeric(string, true, decimal);
}
bool MathUtil::IsNumeric(std::string string,bool ignoreCommas,bool& hasDecimal){
    hasDecimal = false;
    unsigned int i = 0;
    unsigned int stringLength = string.length();
    //bool isNegitive = false;
    if(stringLength < 1) return false;
    if(string[0] == '-'){
        //isNegitive = true;
        ++i;
    }
    while(i < stringLength){
        if(string[i] < '0' || string[i] > '9'){
            return false;
        }
        if(ignoreCommas && string[i] == ',') {
            ++i;
            continue;
        }
        if(string[i] == '.'){
            if(hasDecimal){
                return false;
            } else {
                hasDecimal = true;
                ++i;
                continue;
            }
        }
        ++i;
    }
    return true;
}
*/
double MathUtil::RandomDouble(double min, double max){
    double size = max - min;
    double steps = 1000;
    double op = (double)random(0,(size*steps)+1) * ((double)1.0 / steps) + min;
    return op;
}
/*
float MathUtil::RandomFloat(float min,float max){
    return 0;
}

unsigned int MathUtil::RandomUnsignedInt(unsigned int min, unsigned int max){
    return 0;
}
*/


double MathUtil::ValueMap(double inputValue, double inputMin, double inputMax, double outputMin, double outputMax){
    double iP = (inputValue - inputMin) / (inputMax - inputMin);
    return (outputMax - outputMin) * iP + outputMin;
}