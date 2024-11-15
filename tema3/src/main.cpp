#include "Buttons.h"
#include "LEDControl.h"
#include "Display.h"
#include "GameControl.h"

void setup() {
    initializeSPI();
    initializeLCD();
    initializeServo();
    initializeButtons();
    displayWelcomeMessage();
}

void loop() {
    if (isStartButtonPressed()) {
        startGame();
    }
    updateGame();
}