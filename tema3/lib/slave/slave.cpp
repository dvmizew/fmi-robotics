#include <slave.h>

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
        handleCommand(command);
    }
}

void handleCommand(int command) {
    digitalWrite(RGB_LED_RED, command == 1);
    digitalWrite(RGB_LED_GREEN, command == 2);
    digitalWrite(RGB_LED_BLUE, command == 3);
}