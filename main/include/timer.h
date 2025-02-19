#ifndef UTILS_Timer
#define UTILS_Timer

#include <Arduino.h>

class Timer{
private:
    static double MicrosAsDouble();
    static unsigned long currentMicroseconds;
    static double currentOffsetTime;
    static double elapsedTime;
    double lastLocalElapsedTime;
    double localStartTime;
    double localStepTime;
    static unsigned long maxMicroseconds;
    static unsigned long previousMicroseconds;
    static int step;
    static unsigned long stepMicroseconds;
    static double stepTime;
    

public:
    static unsigned long ElapsedMicroseconds();
    static double ElapsedSeconds();
    double LastStepLength();
    double LocalElapsedTime();
    double LocalStepTime();
    static void Reset();
    static int Step();
    static unsigned long StepTime();
    static double StepTimeSeconds();
    Timer();
    static void Update();
};


#endif