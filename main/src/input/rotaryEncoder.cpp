#include "../../include/input/rotaryEncoder.h"

//static variables
int RotaryEncoder::currentRotaryEncoderID = 0;
RotaryEncoder** RotaryEncoder::rotaryEncoderReference = new RotaryEncoder*[8];


void RotaryEncoder::Init(int vccPin, int clkPin, int dtPin, int value, int minValue, int maxValue){
    this->vccPin = vccPin;
    this->clkPin = clkPin;
    this->dtPin = dtPin;
    this->encoderState = 0;
    this->minValue = minValue;
    this->maxValue = maxValue;
    this->value = 0; 

    pinMode(vccPin, OUTPUT);
    digitalWrite(vccPin, HIGH);
    pinMode(clkPin, INPUT);
    pinMode(dtPin, INPUT);

    //setup intrrupt stuff
    rotaryEncoderID = currentRotaryEncoderID++;
    rotaryEncoderReference[rotaryEncoderID] = this;
    switch(rotaryEncoderID){
        case 0:
            attachInterrupt(digitalPinToInterrupt(clkPin),RotaryEncoder::OnInterrupt0Clk,CHANGE);
            attachInterrupt(digitalPinToInterrupt(dtPin),RotaryEncoder::OnInterrupt0Dt,CHANGE);
            break;
        default:
            Serial.println("couldn't assign rotary encoder ID");
    }
}

void RotaryEncoder::OnInterrupt(int rotaryEncoderReferenceID,bool isClkPin){
    volatile RotaryEncoder* re = rotaryEncoderReference[rotaryEncoderReferenceID];

    volatile int pin = isClkPin ? re->clkPin : re->dtPin;
    volatile bool pinHigh = !digitalRead(pin);

    //Serial.print(isClkPin ? " clk[pin " : " dt[pin ");
    //Serial.print(pin);
    //Serial.print(pinHigh ? "] == [high]. " : "] == [low]. ");

    if(re->lastPinChange == pin){
        return;
    }
    re->lastPinChange = pin;

    if(isClkPin){
        re->clkPinHigh = pinHigh;
    } else {
        re->dtPinHigh = pinHigh;
    }

    switch(re->encoderState){
    case 0: //default state
        if(!re->dtPinHigh && re->clkPinHigh){
            re->encoderState = 1;
            break;
        }
        if(re->dtPinHigh && !re->clkPinHigh){
            re->encoderState = 2;
            break;
        }

        break;
    case 1: //turning towards clk
        if(re->dtPinHigh && re->clkPinHigh){
            re->encoderState = 5;
            break;
        }
        break;
    case 2: //turning towards clk
        if(re->dtPinHigh && re->clkPinHigh){
            re->encoderState = 6;
            break;
        }
        break;
    case 5: //turning towards clk, dt now high
        if(re->dtPinHigh && !re->clkPinHigh){
            re->encoderState = 8;
            break;
        }
        break;
    case 6: //turning towards clk, dt now high
        if(!re->dtPinHigh && re->clkPinHigh){
            re->encoderState = 9;
            break;
        }
        break;
    case 8:
        if(!re->dtPinHigh && !re->clkPinHigh){
            re->encoderState = 0;
            re->value++;
        }
        break;
    case 9:
        if(!re->dtPinHigh && !re->clkPinHigh){
            re->encoderState = 0;
            re->value--;
        }
        break;
    }

    //output some human crap for the dumdum doing the programming
    if(re->encoderState != 0 ){
        return;
    }

    Serial.print(" state = ");
    Serial.print(re->encoderState);
    Serial.print(" value = ");
    Serial.println(re->value);

}

void RotaryEncoder::OnInterrupt0Clk(){ OnInterrupt(0,true); }

void RotaryEncoder::OnInterrupt0Dt(){ OnInterrupt(0,false); }

RotaryEncoder::RotaryEncoder(char* name, int vccPin, int clkPin, int dtPin) : 
        Input(name){
    Init(vccPin,clkPin,dtPin,0,0,100);
}

RotaryEncoder::RotaryEncoder(char* name, int vccPin, int clkPin, int dtPin, int value) : 
        Input(name){
    Init(vccPin,clkPin,dtPin,value,0,100);
}

RotaryEncoder::RotaryEncoder(char* name, int vccPin, int clkPin, int dtPin, int value, int minValue, int maxValue) : 
        Input(name){
    Init(vccPin,clkPin,dtPin,value,minValue,maxValue);
}

bool RotaryEncoder::SampleValue() {
    return false;
}

double RotaryEncoder::Value(){
    return 0;
}

double* RotaryEncoder::ValueRef(){
    return &value;
}

/*
char RotaryEncoder::ValueType(){
    return 'a';
}*/
