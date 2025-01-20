#include "../include/program.h"

//static members
Adafruit_SSD1306* Program::display;
StaticList<Menu*> Program::menuStack = StaticList<Menu*>(10);
StaticList<Input*> Program::systemInputs = StaticList<Input*>(PROGRAM_AVAILABLE_INPUTS);
StaticList<Output*> Program::systemOutputs = StaticList<Output*>(PROGRAM_AVAILABLE_OUTPUTS);



void Program::AddSystemInput(Input* newInput){
    systemInputs.Add(newInput);
}

void Program::AddSystemOutput(Output* newOutput){
    systemOutputs.Add(newOutput);
}

Menu* Program::CurrentMenu(){
    return menuStack[menuStack.Count()-1];
}

void Program::SampleInputs(){
    unsigned int i = systemInputs.Count();
    while(i --> 0){
        systemInputs[i]->SampleValue();
    }
}

void Program::SetDisplay(Adafruit_SSD1306* newDisplay){
    display = newDisplay;
}

StaticList<Input*> Program::SystemInputs(){
    return systemInputs;
}