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

  if (!handledCaw && cawDetect.cawed) {
    Serial.println("CAW detected.  Playing audio...");
    handledCaw = true;
    
    // Play caw audio file
    sound.playRaven("crow1.wav");
  }

  // Once we've handled the caw and it's signal fell back down
  // reset our state
  if (handledCaw && !cawDetect.cawed) {
    handledCaw = false;
  }
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