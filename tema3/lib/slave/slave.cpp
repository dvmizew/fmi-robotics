#include <SPI.h>
#include "LEDControl.h"

// SLAVE GAME CODE
void setup() {
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
            setPlayerRGBColor(1, 1); // set player 1 LED to RED
            break;
        case 2:
            setPlayerRGBColor(1, 2); // set player 1 LED to GREEN
            break;
        case 3:
            setPlayerRGBColor(1, 3); // set player 1 LED to BLUE
            break;
        case 4:
            setPlayerRGBColor(2, 1); // set player 2 LED to RED
            break;
        case 5:
            setPlayerRGBColor(2, 2); // set player 2 LED to GREEN
            break;
        case 6:
            setPlayerRGBColor(2, 3); // set player 2 LED to BLUE
            break;
        default:
            turnOffPlayerRGB(1); // turn off player 1 LED
            turnOffPlayerRGB(2); // turn off player 2 LED
            break;
    }
}