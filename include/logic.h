#pragma once

#include "Arduino.h"
#include "sound.h"

// enum State { WAITING, STARTING, DROPPING, SETTLING, ALERTING, DONE };

class Logic {
public:
  Logic();
  Sound sound;

  void setup();
  void handle();
  void trigger();
  void status();
  void reset();
  
private:
  
};