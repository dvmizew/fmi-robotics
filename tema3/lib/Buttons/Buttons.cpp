#include "Buttons.h"

#define BUTTON_PIN A0 // analog pin for reading the buttons

// because the buttons are multiplexed, we define thresholds for each button
#define BUTTON1_THRESHOLD 200
#define BUTTON2_THRESHOLD 400
#define BUTTON3_THRESHOLD 600

void initializeButtons() {
    pinMode(BUTTON_PIN, INPUT_PULLUP);
}

int readMultiplexedButton() {
    int buttonValue = analogRead(BUTTON_PIN);

    if (buttonValue < BUTTON1_THRESHOLD) {
        return 1; // first button
    } else if (buttonValue < BUTTON2_THRESHOLD) {
        return 2; // second button
    } else if (buttonValue < BUTTON3_THRESHOLD) {
        return 3; // third button
    }

    return -1; // no button was pressed
}