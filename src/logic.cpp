#include "Arduino.h"
#include "logic.h"

Logic::Logic()
  : sound(*this),
    cawDetect(*this)
{
}

void Logic::setup() {
  sound.setup();
  cawDetect.setup();
}

void Logic::handle() {
  sound.handle();
  cawDetect.handle();
}

void Logic::status() {
  char cMsg[254];
  sprintf(cMsg, 
    "status="
      "foo:%s"
      
      "\r\n"
    ,
      "bar"
  );

  Serial.print(cMsg);
}

void Logic::reset() {
  ESP.restart();
}