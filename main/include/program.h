#ifndef UTILS_Program
#define UTILS_Program

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>

#include "staticList.h"
#include "input.h"
#include "output.h"
#include "screen.h"
#include "menu.h"

#define PROGRAM_AVAILABLE_INPUTS 200
#define PROGRAM_AVAILABLE_OUTPUTS 200
#define PROGRAM_AVAILABLE_IOMAPS 100

class Program {
private:
    Menu* currentMenu = NULL;
    static StaticList<Input*> systemInputs;
    static StaticList<Output*> systemOutputs;

protected:
    static Screen* screen;
    static StaticList<Menu*> menuStack;

    void SampleInputs();
    virtual bool SetupInputs() = 0;
    virtual bool SetupMenus() = 0;
    virtual bool SetupOutputs() = 0;

public:
    static void AddSystemInput(Input* newInput);
    static void AddSystemOutput(Output* newOutput);
    Menu* CurrentMenu();
    virtual StaticList<Input*> Inputs() = 0;
    virtual void Run() = 0;
    static void SetScreen(Screen* newScreen);
    static StaticList<Input*> SystemInputs();

};


#endif