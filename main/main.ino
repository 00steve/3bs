#include "include/program/threeBody.h"
#include "include/input/button.h"
#include "include/input/rotaryEncoder.h"
#include "include/input/inputJackTeensyAnalog.h"
#include "include/input/inputSoftwareVariable.h"
#include "include/output/outputJackMCP4728.h"
#include "include/ioMap.h"


Adafruit_SSD1306 display;
ThreeBody threeBody;
Timer timer;


//outputs
Output* outputJack0 = new OutputJackMCP4728(MCP4728_CHANNEL_A);
Output* outputJack1 = new OutputJackMCP4728(MCP4728_CHANNEL_B);
Output* outputJack2 = new OutputJackMCP4728(MCP4728_CHANNEL_C);
Output* outputJack3 = new OutputJackMCP4728(MCP4728_CHANNEL_D);

//IOmaps
//IOMap iom;

int count;
bool blinkOn;

bool rte0IsPressed;
bool rte0CWTurn;
bool rte0CCWTurn;
bool prevRte0CWTurn;
int rte0Value = 0;


double redrawTime = .05;
double redrawTimer = 0;

double testOutput = 0;

RotaryEncoder* r;

void setup() {
    //definitely need this shit. Pass the display to the 
    //other classes and stuff so they're all referencing
    //the same shit and it just works. Don't change this 
    //shit unless you're smarter than the dum dum who wrote
    //this garbage.
    Program::SetDisplay(&display);
    Menu::SetDisplay(&display);
    MenuOption::SetDisplay(&display);

    //add all of the inputs/outputs, etc. that are available based on 
    //the hardware and how it is wired up.
    Program::AddSystemInput(new Button(CCTC("<- Button"),0,1));
    Program::AddSystemInput(new Button(CCTC("-> Button"),2,1));
    Program::AddSystemInput(new Button(CCTC("Rotary button"),10,9,BUTTON_NORMALLY_CLOSED));
    Program::AddSystemInput(new InputJackTeensyAnalog(CCTC("Input Jack 1"),20));
    Program::AddSystemInput(new InputJackTeensyAnalog(CCTC("Input Jack 2"),21));
    Program::AddSystemInput(new InputJackTeensyAnalog(CCTC("Input Jack 3"),22));
    Program::AddSystemInput(new InputJackTeensyAnalog(CCTC("Input Jack 4"),23));
    //Program::AddSystemInput(new RotaryEncoder(CCTC("Rotary Encoder"),9,10,11));


    //Program::AddSystemOutput(Output *newOutput)


    //setup what the inputs and outputs look like, eventually this shit
    //should be part of a program depending on it's own parameters.
    //inputJack0->SetInputValueLimits(-5,5);
    //outputJack0->SetOutputValueLimits(-1,1);

    //set up some mapping
    //iom.SetInput(inputJack0);
    //iom.SetOutput(outputJack1);


    //some default bullshit for testing
    pinMode(13, OUTPUT);
    pinMode(7, OUTPUT);
    pinMode(8, OUTPUT);


    Serial.begin(9600);
    //while (!Serial)
      //delay(10); // will pause Zero, Leonardo, etc until serial console opens
    //randomSeed(inputJack0->GetValue());



    int oledReset = -1;
    int screenAddress = 0x3c;
    int screenWidth = 128;
    int screenHeight = 64;
    display = Adafruit_SSD1306(screenWidth, screenHeight, &Wire, oledReset);
    if(!display.begin(SSD1306_SWITCHCAPVCC, screenAddress)) {
        Serial.println(F("SSD1306 allocation failed"));
        for(;;); // Don't proceed, loop forever
    }


    blinkOn = false;


    //initialize threeBody and other junk last because it FUCKS UP everything else
    //before it in memory like if there are pointers or anything interesting.
    // put your setup code here, to run once:
    threeBody = ThreeBody::CreateRandom(3,1);
    //delay(100);
    Timer::Reset();
}

void loop() {

    //three body simulation. It's pretty important, chump:
    threeBody.Run();

    //rte0IsPressed = !digitalRead(10);
    //rte0CWTurn = !digitalRead(11);
    //rte0CCWTurn = !digitalRead(12);

    //pint some input for more testing
    //Serial.println((*inputJack0).GetValue());

    //code to redraw the screen. Pretty fucking janky. This should be 
    //fixed by someone who knows what they're doing at some point.
    
    //write to some random LEDs for testing buttons and shit.
    //Program::SystemInputs()[2]->SampleValue();
    digitalWriteFast(13,Program::SystemInputs()[2]->Value());
    //digitalWriteFast(13, forwardButton->GetValue() || backButton->GetValue() || rte0IsPressed ? HIGH : LOW);
    //digitalWriteFast(7, rte0CCWTurn ? HIGH : LOW);
    //digitalWriteFast(8, rte0CWTurn ? HIGH : LOW);
}
