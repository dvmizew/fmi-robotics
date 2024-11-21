#include <SPI.h>
#include "slave.h"
#include "LEDControl.h"

// SLAVE GAME CODE
void setup() {
    pinMode(MISO, OUTPUT);
    SPI.begin();
    pinMode(SS, INPUT);
    initializeButtonLEDs(); // initialize the button LEDs and turn them on
    initializeRGBLEDs(); // initialize the RGB LEDs for both players
}

void loop() {
    if (digitalRead(SS) == LOW) { // if the slave select pin is enabled
        int command = SPI.transfer(0); // read the command from the master (0 is a dummy byte)
        handleMasterCommand(command);
    }
}

void handleMasterCommand(int command) {
    // handle the command received from the master
    switch (command) {
        case 1:
            setPlayerRGBColor(1, PLAYER1_RED);
            break;
        case 2:
            setPlayerRGBColor(1, PLAYER1_GREEN);
            break;
        case 3:
            setPlayerRGBColor(1, PLAYER1_BLUE);
            break;
        case 4:
            setPlayerRGBColor(2, PLAYER2_RED);
            break;
        case 5:
            setPlayerRGBColor(2, PLAYER2_GREEN);
            break;
        case 6:
            setPlayerRGBColor(2, PLAYER2_BLUE);
            break;
        default:
            turnOffPlayerRGB(1);
            turnOffPlayerRGB(2);
            break;
    }
}