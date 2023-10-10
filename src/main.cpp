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
	} else if (msg == "1") {
		Serial.println("Playing crow1.wav...");
		logic.sound.playRaven("crow1.wav");
	} else if (msg == "2") {
		Serial.println("Playing crow2.wav...");
  	  	logic.sound.playRaven("crow2.wav");
	} else if (msg == "3") {
		Serial.println("Playing crow3.wav...");
  	  	logic.sound.playRaven("crow3.wav");
	} else if (msg == "4") {
		Serial.println("Playing crow4.wav...");
  	  	logic.sound.playRaven("crow4.wav");	  
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