#pragma once
#include "Arduino.h"

class Logic;

class Sound {
  public:
    Sound(Logic &logic);
    void setup();
    void handle();
    // void playMail();
    // void playJetsons();
    // void playWorms();
    // bool isPlaying();
    
  private:
    Logic &_logic;
};