#ifndef UTILS_Program
#define UTILS_Program

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>

#include "staticList.h"
#include "input.h"
#include "output.h"
#include "menu.h"

#define PROGRAM_AVAILABLE_INPUTS 200
#define PROGRAM_AVAILABLE_OUTPUTS 200

class Program {
private:
    Menu* currentMenu = NULL;
    static StaticList<Input*> systemInputs;
    static StaticList<Output*> systemOutputs;

protected:
    static Adafruit_SSD1306* display;
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
    static void SetDisplay(Adafruit_SSD1306* newDisplay);
    static StaticList<Input*> SystemInputs();

};


#endif