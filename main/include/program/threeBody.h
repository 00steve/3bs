#ifndef THREEBODY
#define THREEBODY

#include <string>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>

#include "../tb3f.h"
#include "../mathUtil.h"
#include "../timer.h"
#include "../program.h"
#include "../cstrUtil.h"

#include "../input/inputSoftwareVariable.h"
#include "../input/inputJackTeensyAnalog.h"

#include "../menuConfiguration.h"
#include "../menuOption/menuBack.h"
#include "../menuOption/menuLink.h"
#include "../menuOption/menuVariable.h"

#include "../menu/verticalListMenu.h"
#include "../menu/ioMapMenu.h"


struct TBBody {
    TB3F    acceleration; //m/s^2
    double   bounciness;
    bool    destroyOnCollision;
    double   drag = .002;
    TB3F    lastPosition;
    double   mass = 100; //kg
    TB3F    position;
    double   radius; //m
    TB3F    velocity; //m/s
    bool    selected;

};


class ThreeBody : public Timer, public Program {
private:
    //simulation
    int bodyCount = 3;
    TBBody* body = new TBBody[bodyCount];
    int fps = 0;
    int fpsCount = 0;
    double G = 25.66743; //default G x 10^7
    double maxRadius = 2;
    TB3F maxExtent = TB3F(0,0,0);
    double redrawTime = .05;
    double redrawTimer = 0;
    double secondCounter = 1;
    double timeStep = .0005; //200fps
    double timeMult = 1.0;
    double timeUntilNextStep = 0;

    //IO
    StaticList<Input*> programInputs = StaticList<Input*>(PROGRAM_AVAILABLE_INPUTS);
    StaticList<Input*> programOutputs = StaticList<Input*>(PROGRAM_AVAILABLE_OUTPUTS);
    StaticList<IOMap*> ioMaps = StaticList<IOMap*>(PROGRAM_AVAILABLE_IOMAPS);

    //display
    int oledReset = -1;
    float refreshRateMicros = 1000000 / 30;
    int screenAddress = 0x3c;
    int screenWidth = 128;
    int screenHeight = 64;
    int steps = 40;
    int stepsLeft = 20;
    float timeUntilNextRefreshMicros = 0;

    //menus
    MenuConfiguration verticalListMenuDefault;

    Menu* bodiesMenu = NULL;
    Menu* fileMenu = NULL;
    StaticList<Menu*> ioMenus = StaticList<Menu*>(PROGRAM_AVAILABLE_INPUTS + PROGRAM_AVAILABLE_OUTPUTS);
    Menu* mainMenu = NULL;
    Menu* physicsMenu = NULL;
    Menu* simMenu = NULL;

    //private internal delicious functions of glorious goodness.
    void ApplyDragToVelocity();
    void ApplyGravity(TBBody& a, TBBody& b);
    void BuildBodiesMenu();
    void CalculateDysonSphereAcceleration();
    void CalculateGravityAcceleration();
    void CalculatePosition();
    void CalculateVelocity();
    void InitializeDisplay();
    void ResetAcceleration();
    void SetupVoltageSources();
    void UpdateMaxExtent();

protected:
    void Draw();
    static TB3F RandomPointInSphere(double sphereRadius);
    static TB3F RandomPointOnSphere(double sphereRadius);
    bool SetupInputs();
    bool SetupIOMaps();
    bool SetupMenus();
    bool SetupOutputs();
    void Simulate();

public:
    TBBody Body(int index);
    int BodyCount();
    static ThreeBody CreateRandom(int bodyCount,double radius);
    static ThreeBody CreateRandom2D(int bodyCount,double radius);
    String CurrentStateReport();
    int FPS();
    /*Should only be called when a 3body simulation is loaded or a new simulation 
    is created (e.g. using CreateRandom(), CreateRandom2D(), etc.) */
    static void Init(ThreeBody& newThreeBody);
    StaticList<Input*> Inputs();
    TB3F MaxExtent();
    double MaxRadius();
    static void OnMenuAction(MenuAction* menuAction,void* object);
    void Run();
    ThreeBody();
    ~ThreeBody();
};

#endif