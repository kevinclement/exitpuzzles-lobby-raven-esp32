#include "Arduino.h"
#include "logic.h"

Logic::Logic()
  : sound(*this)
{
}

void Logic::setup() {
  sound.setup();
}

void Logic::handle() {
  sound.handle();
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