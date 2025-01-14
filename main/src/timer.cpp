#include "../include/timer.h"

unsigned long Timer::maxMicroseconds = 4294967295;
//double Timer::currentGlfwTime = Timer::MicrosAsDouble();
double Timer::currentOffsetTime = 0;
double Timer::elapsedTime = 0;
unsigned long Timer::currentMicroseconds = 0;
//double Timer::previousGlfwTime = Timer::currentGlfwTime;
unsigned long Timer::previousMicroseconds = 0;
int Timer::step = 0;
unsigned long Timer::stepMicroseconds = 0;
double Timer::stepTime = 0;


unsigned long Timer::ElapsedMicroseconds(){
    return currentMicroseconds;
}

double Timer::ElapsedSeconds(){
    return currentMicroseconds * .000001;
}

double Timer::MicrosAsDouble(){
    return ((double)currentMicroseconds) * .000001;
}

double Timer::LocalElapsedTime(){
    elapsedTime = MicrosAsDouble();
    return elapsedTime - localStartTime;
}

double Timer::LocalStepTime(){
    double newStepTime = LocalElapsedTime() - lastLocalElapsedTime;
    lastLocalElapsedTime = LocalElapsedTime();
    return newStepTime;
}

void Timer::Reset(){
    currentMicroseconds = micros();
    stepMicroseconds = 0;
    currentOffsetTime = MicrosAsDouble();
}

int Timer::Step(){
    return step;
}

unsigned long Timer::StepTime(){
    return stepMicroseconds;
}

double Timer::StepTimeSeconds(){
    return stepMicroseconds * .000001;
}

Timer::Timer() : 
        localStartTime(elapsedTime),
        localStepTime(0) {
}

void Timer::Update(){
    previousMicroseconds = currentMicroseconds;
    currentMicroseconds = micros();
    
    //if(currentMicroseconds < previousMicroseconds){
    //    stepMicroseconds = (maxMicroseconds - previousMicroseconds) + stepMicroseconds;
    //} else {
        stepMicroseconds = currentMicroseconds - previousMicroseconds;
    //}

    //previousGlfwTime = currentGlfwTime;
    //currentGlfwTime = MicrosAsDouble();
    //stepTime = currentGlfwTime - previousGlfwTime;
    //elapsedTime = currentGlfwTime - currentOffsetTime;
    ++step;
}