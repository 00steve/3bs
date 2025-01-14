#ifndef UTILS_Animation
#define UTILS_Animation

#include "staticList.h"
#include "timer.h"

#define CURVE_LINEAR 0
#define CURVE_LOG 1

struct AnimationSlew {
    double currentTime;
    double currentValue;
    unsigned int curve;
    double* endingValue;//references a value that is updated
    double lastCurrentValue;
    double lastEndingValue;
    double startingValue;
    double timeLength; //(in seconds)
};

class Animation : public Timer {
private:
    StaticList<AnimationSlew*> slews = StaticList<AnimationSlew*>(10);

public:
    AnimationSlew* AddSlew(double* valueRef, unsigned int CURVE_TYPE);
    AnimationSlew* AddSlew(double* valueRef, unsigned int CURVE_TYPE, double timeLength);
    void Run();

};

#endif