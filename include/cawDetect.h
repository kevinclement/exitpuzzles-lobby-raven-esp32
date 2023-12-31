#pragma once
#include "Arduino.h"

class Logic;

class CawDetect {
  public:
    CawDetect(Logic &logic);
    void setup();
    void handle();

    bool cawed = false;
    
  private:
    Logic &_logic;
};