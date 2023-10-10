
#include "Arduino.h"
#include "logic.h"

#define CAW_INPUT_PIN 21
#define BOUNCE_TIME_MS 10

unsigned long cawTime = 0;

CawDetect::CawDetect(Logic &logic)
: _logic(logic)
{
}

void CawDetect::setup() {
  pinMode(CAW_INPUT_PIN, INPUT_PULLDOWN);
}

void CawDetect::handle() {
    int cawState = digitalRead(CAW_INPUT_PIN);

    if (!cawState) {
        cawTime = 0;
        cawed = false;
    }
    else {
        if (cawTime == 0) {
            cawTime = millis();
        }
        else if (millis() - cawTime > BOUNCE_TIME_MS) {
            cawed = true;
        }
    }
}