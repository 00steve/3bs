#include "../../include/output/outputJackMCP4728.h"

Adafruit_MCP4728 OutputJackMCP4728::mcp;
bool OutputJackMCP4728::mcpInitialized = false;

bool OutputJackMCP4728::CheckConfiguration(){
    configured = channel != -1;
    if(!configured) return configured;
    //other configuration checks
    return configured;
}

bool OutputJackMCP4728::InitializeHardware(){
    return mcpInitialized = mcpInitialized || mcp.begin();
}

OutputJackMCP4728::OutputJackMCP4728(MCP4728_channel_t channel) :
        channel(channel){
    InitializeHardware();
    CheckConfiguration();
}

bool OutputJackMCP4728::SetOutputValue(double newOutputValue){
    if(newOutputValue == value) return true;
    if(newOutputValue > maxOutputValue) 
        newOutputValue = maxOutputValue;
    else 
        if (newOutputValue < minOutputValue) 
            newOutputValue = minOutputValue;
    if(!mcp.setChannelValue(channel,newOutputValue)) return false;
    value = newOutputValue;
    return true;
}