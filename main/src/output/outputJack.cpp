#include "../../include/output/outputJack.h"

bool OutputJack::CheckConfiguration(){
    configured = channel != -1;
    if(!configured) return configured;
    //other configuration checks
    return configured;
}

OutputJack::OutputJack(){
    CheckConfiguration();
}

OutputJack::OutputJack(int channel) :
        channel(channel){
    CheckConfiguration();
}

bool OutputJack::SetValue(double newValue){
    return false;
}