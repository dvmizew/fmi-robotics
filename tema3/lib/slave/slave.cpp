#include "slave.h"

// SLAVE GAME CODE
void setup() {
    pinMode(RGB_LED_RED, OUTPUT);
    pinMode(RGB_LED_GREEN, OUTPUT);
    pinMode(RGB_LED_BLUE, OUTPUT);

    pinMode(SS, INPUT);
    SPI.begin();
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
            setRGBColor(RGB_LED_RED, RGB_LED_GREEN, RGB_LED_BLUE, 1); // set to RED
            break;
        case 2:
            setRGBColor(RGB_LED_RED, RGB_LED_GREEN, RGB_LED_BLUE, 2); // set to GREEN
            break;
        case 3:
            setRGBColor(RGB_LED_RED, RGB_LED_GREEN, RGB_LED_BLUE, 3); // set to BLUE
            break;
        case 4:
            blinkLED(RGB_LED_RED); // blink the RED LED as an error signal
            break;
        default:
            turnOffRGB(RGB_LED_RED, RGB_LED_GREEN, RGB_LED_BLUE);
    }
}