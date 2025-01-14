#include "../include/trigger.h"

bool Trigger::Fire(){
    if(!value) return false;
    currentValue = *value;
    fire = previousValue < highThreshold && currentValue >= highThreshold;
    previousValue = currentValue;
    return fire;
}

Trigger::Trigger(){
}

Trigger::Trigger(double* refValue, double triggerThreshold) : 
        highThreshold(triggerThreshold),
        value(refValue){
}
