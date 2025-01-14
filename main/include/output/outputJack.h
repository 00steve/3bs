#ifndef OUTPUT_JACK
#define OUTPUT_JACK

#include "../output.h"

class OutputJack : public Output {
private:
    int channel = -1;
    bool configured = false;
    bool CheckConfiguration();
    double value = 0;

public:
    OutputJack();
    OutputJack(int channel);
    void Run();
    bool SetValue(double newValue);
};


#endif