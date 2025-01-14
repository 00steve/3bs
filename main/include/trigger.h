#ifndef UTILS_Trigger
#define UTILS_Trigger

class Trigger {
private:
    double currentValue = 0;
    bool fire = false;
    double previousValue = 0;
    bool primed = true;
    double highThreshold;
    double* value;

public:
    bool Fire();
    Trigger();
    Trigger(double* refValue, double triggerThreshold);
};

#endif