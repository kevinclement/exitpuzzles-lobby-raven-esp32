#pragma once
#include "Arduino.h"

class Logic;

class Sound {
  public:
    Sound(Logic &logic);
    void setup();
    void handle();
    void playRaven(const char * fName);
    bool isPlaying();
    
  private:
    Logic &_logic;
};