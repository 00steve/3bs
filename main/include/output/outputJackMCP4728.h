#ifndef OUTPUT_JACKMCP4728
#define OUTPUT_JACKMCP4728

#include <Adafruit_MCP4728.h>
#include <Wire.h>

#include "../output.h"

class OutputJackMCP4728 : public Output {
private:
    MCP4728_channel_t           channel;
    bool                        configured = false;
    const double                maxOutputValue = 4095;
    const double                minOutputValue = 0;
    static Adafruit_MCP4728     mcp;
    static bool                 mcpInitialized;
double                          value = 0;

    bool CheckConfiguration();
    bool InitializeHardware();

public:
    /*
        available channel values :
        - MCP4728_CHANNEL_A
        - MCP4728_CHANNEL_B
        - MCP4728_CHANNEL_C
        - MCP4728_CHANNEL_D
     */
    OutputJackMCP4728(char* outputName, MCP4728_channel_t channel);
    bool SetOutputValue(double newOutputValue);
};


#endif