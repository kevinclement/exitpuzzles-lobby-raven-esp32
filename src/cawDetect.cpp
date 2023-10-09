
#include "Arduino.h"
#include "logic.h"

#define CAW_INPUT_PIN 21

CawDetect::CawDetect(Logic &logic)
: _logic(logic)
{
}

void CawDetect::setup() {
  pinMode(CAW_INPUT_PIN, INPUT_PULLDOWN);
}

void CawDetect::handle() {
    int cawState = digitalRead(CAW_INPUT_PIN);
    Serial.print("caw: ");
    Serial.println(cawState);
    delay(1000);
}