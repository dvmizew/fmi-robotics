#include "Buttons.h"
#include "LEDControl.h"
#include "Display.h"
#include "GameControl.h"

// MASTER GAME CODE
void setup() {
    initializeButtons();
    initializeLEDs();
    initializeLCD();
    initializeServo();
    initializeSerial();
    startGame();
}

void loop() {
    updateGame();
}