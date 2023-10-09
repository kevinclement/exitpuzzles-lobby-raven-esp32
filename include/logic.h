#pragma once

#include "Arduino.h"
#include "sound.h"
#include "cawDetect.h"

class Logic {
public:
  Logic();
  Sound sound;
  CawDetect cawDetect;

  void setup();
  void handle();
  void status();
  void reset();
  
private:
  
};