#pragma once
#include "Arduino.h"

class Logic;

class CawDetect {
  public:
    CawDetect(Logic &logic);
    void setup();
    void handle();
    
  private:
    Logic &_logic;
};