#include "../../include/program/threeBody.h"

void ThreeBody::ApplyDragToVelocity(){
    for(int i = 0;i < bodyCount; i++){
        //body[i].velocity *= (1-(body[i].drag * timeStep));
    }
}

void ThreeBody::ApplyGravity(TBBody& a, TBBody& b){
    TB3F dist = a.position - b.position;
    double rsq = dist.x*dist.x + dist.y*dist.y + dist.z*dist.z;
    double f = G*( (a.mass*b.mass) / rsq);
    a.acceleration += dist / a.mass * f * timeStep* timeMult * -1.0f;
    b.acceleration += dist / a.mass * f * timeStep* timeMult;
}

TBBody ThreeBody::Body(int index){
    return body[index];
}

int ThreeBody::BodyCount(){
    return bodyCount;
}

void ThreeBody::BuildBodiesMenu(){
    bodiesMenu->RemoveAllOptions();
    bodiesMenu->AddOption(new MenuBack(CCTC("Back")));

    MenuVariable* ival = new MenuVariable(CCTC("Input 4"),Inputs()[6]->ValueRef());
    bodiesMenu->AddOption(ival);

    int m = bodyCount;
    int i = 0;
    while(i < m){
        std::string p1 = CCTC("B");
        std::string p2 = CCTC(std::to_string(i).c_str());
        std::string p3 = CCTC(" mass");

        std::string name = p1 + p2 + p3;
        MenuVariable* mv = new MenuVariable(CCTC(name.c_str()), &body[i].mass);
        bodiesMenu->AddOption(mv);

        p3 = CCTC(" vel x");
        name = p1 + p2 + p3;
        MenuVariable* vxv = new MenuVariable(CCTC(name.c_str()), &body[i].velocity.x);
        bodiesMenu->AddOption(vxv);





        ++i;
    }
}

void ThreeBody::CalculateDysonSphereAcceleration(){
    for(int i = 0;i < bodyCount; i++){
        TB3F rad = body[i].position.Normalized() * maxRadius;
        double radLen = rad.Length();
        double bLen = body[i].position.Length();
        if(radLen > bLen) continue; //check if position < rad, if so, continue
        body[i].position = body[i].position.Normalized()*maxRadius;
    }
}
    
void ThreeBody::CalculateGravityAcceleration(){
    for(int a = 0;a < bodyCount; a++){
        for(int b = a+1; b < bodyCount; b++){
            ApplyGravity(body[a],body[b]);
        }
    }
}

void ThreeBody::CalculatePosition(){
    for(int i = 0;i < bodyCount; i++){
        body[i].lastPosition = body[i].position;
        body[i].position += body[i].velocity * timeStep * timeMult;
    }
}

void ThreeBody::CalculateVelocity(){
    for(int i = 0;i < bodyCount; i++){
        body[i].velocity += body[i].acceleration * timeStep * timeMult;
    }
}

ThreeBody ThreeBody::CreateRandom(int newBodyCount,double sphereRadius){
    ThreeBody tb;
    tb.bodyCount = newBodyCount;
    tb.maxRadius = sphereRadius;
    tb.body = new TBBody[tb.bodyCount];
    for(int i = 0; i < tb.bodyCount; i++){
        tb.body[i].position = ThreeBody::RandomPointInSphere(tb.maxRadius);
        tb.body[i].position = tb.body[i].position.Normalized() * tb.maxRadius;
        tb.body[i].velocity = TB3F(0,0,0);
        tb.body[i].selected = false;
    }
    Init(tb);
    return tb;
}

ThreeBody ThreeBody::CreateRandom2D(int newBodyCount,double sphereRadius){
    ThreeBody tb;
    tb.bodyCount = newBodyCount;
    tb.maxRadius = sphereRadius;
    tb.body = new TBBody[tb.bodyCount];
    for(int i = 0; i < tb.bodyCount; i++){
        tb.body[i].position = ThreeBody::RandomPointInSphere(tb.maxRadius);
        tb.body[i].position.z = 0;
        tb.body[i].position = tb.body[i].position.Normalized() * tb.maxRadius;
        tb.body[i].velocity = TB3F(0,0,0);
        tb.body[i].selected = false;
    }
    Init(tb);
    return tb;
}

String ThreeBody::CurrentStateReport(){
    return 
      "" + String(body[0].position.x) + ", " + String(body[0].position.y) + ", " + String(body[0].position.z)  + ", "
      + String(body[1].position.x) + ", " + String(body[1].position.y) + ", " + String(body[1].position.z)  + ", "
      + String(body[2].position.x) + ", " + String(body[2].position.y) + ", " + String(body[2].position.z) + "\n"
    ;
}

void ThreeBody::Draw(){
    float pixelOffsetX = 64;
    float pixelOffsetY = 0;
    double maxSize = 7;
    double maxRadius = MaxRadius();
    float pixelScaleX = (float)screenHeight / maxRadius / 2.3;
    float pixelScaleY = (float)screenHeight / maxRadius / 2.3;
    float pixelScaleZ = maxSize / maxRadius;
    int screenHalf = (float)screenHeight *.5;
    float pixelX;
    float pixelY;
    float pixelZ;
    int i = bodyCount;
    display->clearDisplay();
    
    while(i --> 0){
        pixelX = body[i].position.x * pixelScaleX + screenHalf + pixelOffsetX;
        pixelY = body[i].position.y * pixelScaleY + screenHalf + pixelOffsetY;
        pixelZ = body[i].position.z * pixelScaleZ + (maxSize * .5) + 3;
        display->drawCircle(pixelX,pixelY,pixelZ,SSD1306_WHITE);
    }

    //line to seperate top and bottom, don't know why, just figuring stuff out
    //display->drawLine(0,11,127,11,WHITE);

    //display fps
    //display->fillRect(64,0,64,11,BLACK);
    display->setTextSize(1);
    display->setTextColor(WHITE);
    display->setCursor(66, 0);
    /*int p = FPS();
    display->println("fps:");
    display->setCursor(96, 0);
    display->println(p);
    */

    //if there is a menu, do that shit, don't be a fuck
    if(CurrentMenu()){
        CurrentMenu()->Draw();
    }
    //do the final update to the screen
    display->display();
}

int ThreeBody::FPS(){
    return fps;
}

void ThreeBody::Init(ThreeBody& newThreeBody){
    newThreeBody.SetupInputs();
    newThreeBody.InitializeDisplay();
    newThreeBody.SetupMenus();
}

void ThreeBody::InitializeDisplay(){
    //MenuOption::SetDisplay(display);
}

StaticList<Input*> ThreeBody::Inputs(){
    return programInputs;
}

TB3F ThreeBody::MaxExtent(){
    return maxExtent;
}

double ThreeBody::MaxRadius(){
    return maxRadius;
}

void ThreeBody::OnMenuAction(MenuAction* menuAction,void* object){
    switch(menuAction->MenuActionType()){
    case MENUACTION_MenuBack:
        menuStack.RemoveLast();
        break;
    case MENUACTION_MenuLink:
        Menu* menu = static_cast<Menu*>(menuAction->GetTarget());
        if(!menu) return;
        menuStack.Add(menu);
        break;
    }
}

TB3F ThreeBody::RandomPointInSphere(double sphereRadius){
    TB3F newTb3f = TB3F(MathUtil::RandomDouble(-sphereRadius,sphereRadius),
                        MathUtil::RandomDouble(-sphereRadius,sphereRadius),
                        MathUtil::RandomDouble(-sphereRadius,sphereRadius));
    return newTb3f;
}

TB3F ThreeBody::RandomPointOnSphere(double sphereRadius){
    TB3F newTb3f;
    return newTb3f;
}

void ThreeBody::ResetAcceleration(){
    for(int i = 0;i < bodyCount; i++){
        body[i].acceleration = TB3F(0,0,0);
    }
}

void ThreeBody::Run(){
    Timer::Update();
    double stepTime = Timer::StepTimeSeconds();
    timeUntilNextStep -= stepTime;
    if(timeUntilNextStep < 0){
        Simulate();
        timeUntilNextStep += timeStep;
        ++fpsCount;
    }
    secondCounter -= stepTime;
    if(secondCounter < 0){
        secondCounter += 1;
        fps = fpsCount;
        fpsCount = 0;
    }
    redrawTimer += Timer::StepTimeSeconds();
    if(redrawTimer > redrawTime){
        redrawTimer -= redrawTime;
        if(CurrentMenu()){
            CurrentMenu()->Run();
        }
        Draw();
    }
    SampleInputs();
}

bool ThreeBody::SetupInputs(){
    programInputs.Clear();
    programInputs.Add(SystemInputs());
    unsigned int labelAxisIndex = 18;
    for(int i = 0;i < bodyCount; i++){
        CStrUtil p = CStrUtil("Body _ : Position _");
        p.Insert((double)(i+1),5,0);
        p.Insert("X",labelAxisIndex);
        programInputs.Add(new InputSoftwareVariable(p.Value(), &body[i].position.x));
        p.Insert("Y",labelAxisIndex);
        programInputs.Add(new InputSoftwareVariable(p.Value(), &body[i].position.y));
        p.Insert("Z",labelAxisIndex);
        programInputs.Add(new InputSoftwareVariable(p.Value(), &body[i].position.z));

        CStrUtil v = CStrUtil("Body _ : Velocity _");
        v.Insert((double)(i+1),5,0);
        v.Insert("X",labelAxisIndex);
        programInputs.Add(new InputSoftwareVariable(v.Value(), &body[i].velocity.x));
        v.Insert("Y",labelAxisIndex);
        programInputs.Add(new InputSoftwareVariable(v.Value(), &body[i].velocity.y));
        v.Insert("Z",labelAxisIndex);
        programInputs.Add(new InputSoftwareVariable(v.Value(), &body[i].velocity.z));

        CStrUtil a = CStrUtil("Body _ : Accel _");
        a.Insert((double)(i+1),5,0);
        a.Insert("X",labelAxisIndex);
        programInputs.Add(new InputSoftwareVariable(a.Value(), &body[i].acceleration.x));
        a.Insert("Y",labelAxisIndex);
        programInputs.Add(new InputSoftwareVariable(a.Value(), &body[i].acceleration.y));
        a.Insert("Z",labelAxisIndex);
        programInputs.Add(new InputSoftwareVariable(a.Value(), &body[i].acceleration.z));
    }
    return false;
}

bool ThreeBody::SetupIOMaps(){
    //IOMap* iom1 = new IOMap();
    //ioMaps.Add()

    return false;
}

bool ThreeBody::SetupMenus(){
    //build default vertical list menu configuration
    //verticalListMenuDefault.inputs[MENU_INPUT_DOWN] = Inputs()[MENU_INPUT_DOWN_DEFAULT];
    //verticalListMenuDefault.inputs[MENU_INPUT_UP] = Inputs()[MENU_INPUT_UP_DEFAULT];
    //verticalListMenuDefault.inputs[MENU_INPUT_FORWARD] = Inputs()[MENU_INPUT_FORWARD_DEFAULT];

    //create menu objects
    bodiesMenu = new VerticalListMenu(verticalListMenuDefault);
    fileMenu = new VerticalListMenu(verticalListMenuDefault);
    mainMenu = new VerticalListMenu(verticalListMenuDefault);
    physicsMenu = new VerticalListMenu(verticalListMenuDefault);
    simMenu = new VerticalListMenu(verticalListMenuDefault);

    //set root menu
    menuStack.Add(mainMenu);

    //file menu
    fileMenu->AddOption(new MenuBack(CCTC("Back")));
    fileMenu->AddOption(new MenuLink(CCTC("Save")));
    fileMenu->AddOption(new MenuLink(CCTC("Load")));
    fileMenu->AddOption(new MenuLink(CCTC("Clear")));
    fileMenu->AddOption(new MenuLink(CCTC("Recent")));
    ((VerticalListMenu*)fileMenu)->SetInputDown(Inputs()[0]);
    ((VerticalListMenu*)fileMenu)->SetInputUp(Inputs()[1]);
    ((VerticalListMenu*)fileMenu)->SetInputSelect(Inputs()[2]);
    fileMenu->SetMenuAction(&ThreeBody::OnMenuAction, this);
    
    //main menu
    mainMenu->AddOption(new MenuLink(CCTC("3 Body")));
    mainMenu->AddOption(new MenuLink(CCTC("File"), fileMenu));
    mainMenu->AddOption(new MenuLink(CCTC("Sim"), simMenu));
    mainMenu->AddOption(new MenuLink(CCTC("I/O")));
    mainMenu->AddOption(new MenuLink(CCTC("Display")));
    //mainMenu->SetInputDown(Inputs().Find(CCTC("<- Button")));//figure out some way to search for objects in list based on a property
    ((VerticalListMenu*)mainMenu)->SetInputDown(Inputs()[0]);
    ((VerticalListMenu*)mainMenu)->SetInputUp(Inputs()[1]);
    ((VerticalListMenu*)mainMenu)->SetInputSelect(Inputs()[2]);
    mainMenu->SetMenuAction(&ThreeBody::OnMenuAction, this);

    //bodies menu
    BuildBodiesMenu();
    ((VerticalListMenu*)bodiesMenu)->SetInputDown(Inputs()[0]);
    ((VerticalListMenu*)bodiesMenu)->SetInputUp(Inputs()[1]);
    ((VerticalListMenu*)bodiesMenu)->SetInputSelect(Inputs()[2]);
    bodiesMenu->SetMenuAction(&ThreeBody::OnMenuAction, this);

    //physics menu
    physicsMenu->AddOption(new MenuBack(CCTC("Back")));
    physicsMenu->AddOption(new MenuLink(CCTC("Gravity")));
    physicsMenu->AddOption(new MenuLink(CCTC("Vel. Damp")));
    physicsMenu->AddOption(new MenuLink(CCTC("FPS")));
    ((VerticalListMenu*)physicsMenu)->SetInputDown(Inputs()[0]);
    ((VerticalListMenu*)physicsMenu)->SetInputUp(Inputs()[1]);
    ((VerticalListMenu*)physicsMenu)->SetInputSelect(Inputs()[2]);
    physicsMenu->SetMenuAction(&ThreeBody::OnMenuAction, this);

    //sim menu
    simMenu->AddOption(new MenuBack(CCTC("Back")));
    simMenu->AddOption(new MenuLink(CCTC("BodyCount")));
    simMenu->AddOption(new MenuLink(CCTC("Bodies"), bodiesMenu));
    simMenu->AddOption(new MenuLink(CCTC("Physics"), physicsMenu));
    ((VerticalListMenu*)simMenu)->SetInputDown(Inputs()[0]);
    ((VerticalListMenu*)simMenu)->SetInputUp(Inputs()[1]);
    ((VerticalListMenu*)simMenu)->SetInputSelect(Inputs()[2]);
    simMenu->SetMenuAction(&ThreeBody::OnMenuAction, this);




    //Serial.print("actual file menu address: " );
    //Serial.println(reinterpret_cast<intptr_t>(fileMenu));
    return true;
}

bool ThreeBody::SetupOutputs(){
    //programOutputs.Add(new SoftwareOutput)
    return false;
}

void ThreeBody::SetupVoltageSources(){
    for(int i = 0;i < bodyCount; i++){
        body[i].acceleration = TB3F(0,0,0);
    }
}

void ThreeBody::Simulate(){
    //reset acceleration
    ResetAcceleration();
    //calculate acceleration from gravity between all of the bodies
    CalculateGravityAcceleration();
    //apply drag coefficient
    ApplyDragToVelocity();
    //calculate acceleration from dyson sphere
    CalculateDysonSphereAcceleration();
    //calculate velocity of each body based on acceleration over time
    CalculateVelocity();
    //calculate new position of each body based on the velocity over time
    CalculatePosition();
    //check for collisions and apply new linear velocity

    //update bounds for data stuff
    //UpdateMaxExtent();
}

ThreeBody::ThreeBody(){
    Timer::Reset();
    maxRadius = 10;
}

ThreeBody::~ThreeBody(){
    //delete fileMenu;
    //delete mainMenu;
}

void ThreeBody::UpdateMaxExtent(){
    for(int i = 0; i < bodyCount; i++){
        TB3F pos = body[i].position;
        double x = std::abs(pos.x);
        double y = std::abs(pos.y);
        double z = std::abs(pos.z);
        if(x > maxExtent.x) maxExtent.x = x;
        if(y > maxExtent.y) maxExtent.y = y;
        if(z > maxExtent.z) maxExtent.z = z;
    }
}