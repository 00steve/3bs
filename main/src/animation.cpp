#include "../include/animation.h"

AnimationSlew* Animation::AddSlew(double* valueRef, unsigned int CURVE_TYPE){
    AnimationSlew* as = new AnimationSlew();
    as->currentTime = 0;
    as->currentValue = *valueRef;
    as->curve = CURVE_TYPE;
    as->endingValue = valueRef;
    as->lastCurrentValue = as->currentValue;
    as->startingValue = 0;
    as->timeLength = 1;
    slews.Add(as);
    return as;
}

AnimationSlew* Animation::AddSlew(double* valueRef, unsigned int CURVE_TYPE, double timeLength){
    AnimationSlew* as = new AnimationSlew();
    as->currentTime = 0;
    as->currentValue = *valueRef;
    as->curve = CURVE_TYPE;
    as->endingValue = valueRef;
    as->lastCurrentValue = as->currentValue;
    as->startingValue = 0;
    as->timeLength = timeLength;
    slews.Add(as);
    return as;
}

void Animation::Run(){
    int i = slews.Count();
    double lst = Timer::LocalStepTime(); 
    while(i-->0){
        if((*slews[i]->endingValue) != slews[i]->lastEndingValue){
            slews[i]->startingValue = slews[i]->currentValue;
            slews[i]->lastEndingValue = (*slews[i]->endingValue);
            slews[i]->currentTime = 0;
        }

        if(slews[i]->currentTime < slews[i]->timeLength){
            slews[i]->currentTime += lst;
            if(slews[i]->currentTime > slews[i]->timeLength){
                slews[i]->currentTime = slews[i]->timeLength;
            }
        }
        switch(slews[i]->curve){
        case CURVE_LINEAR:

            slews[i]->currentValue = (slews[i]->startingValue * (1-(slews[i]->currentTime/slews[i]->timeLength))) 
                + (*slews[i]->endingValue * (slews[i]->currentTime/slews[i]->timeLength));
            break;
        }
        slews[i]->lastCurrentValue = slews[i]->currentValue;
    }
}
