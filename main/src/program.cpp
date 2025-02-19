#include "../include/program.h"

//static members
StaticList<Menu*> Program::menuStack = StaticList<Menu*>(10);
Screen* Program::screen;
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

void Program::SetScreen(Screen* newScreen){
    screen = newScreen;
}

StaticList<Input*> Program::SystemInputs(){
    return systemInputs;
}