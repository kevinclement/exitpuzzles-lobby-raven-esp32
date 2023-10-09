#include <Arduino.h>
#include "logic.h"

Logic logic;

void readAnySerialMessage() {
	if (!Serial.available()) {
    	return;
  	}

	// read and handle message from serial
	String msg = Serial.readStringUntil('\n');
	Serial.print("got '");
	Serial.print(msg);
	Serial.println("' command");

	if (msg == "reset" || msg == "reboot" || msg == "r") {
    	logic.reset();
	} else if (msg == "status" || msg == "s") {
  	  logic.status();
	} else {
    	Serial.print("unknown command: ");
    	Serial.println(msg);
 	}
}

void setup() {
	Serial.begin(115200);
	Serial.setTimeout(10);
	Serial.println("READY");
	Serial.println("Raven by kevinc...\n");

	logic.setup();
}

void loop() {
	readAnySerialMessage();
  	logic.handle();
	delay(15);
}