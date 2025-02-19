#include "../include/output.h"

double Output::OutputValueMax(){
    return outputValueMax;
}

double Output::OutputValueMin(){
    return outputValueMin;
}

void Output::SetOutputValueLimits(double newOutputValueMin, double newOutputValueMax){
    SetOutputValueMax(newOutputValueMax);
    SetOutputValueMin(newOutputValueMin);
}

void Output::SetOutputValueMax(double newOutputValueMax){
    outputValueMax = newOutputValueMax;
}

void Output::SetOutputValueMin(double newOutputValueMin){
    outputValueMin = newOutputValueMin;
}