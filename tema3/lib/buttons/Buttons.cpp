#include "Buttons.h"

#define BUTTON_PIN A0 // analog pin for reading the buttons

// because the buttons are multiplexed, we define thresholds for each button
#define BUTTON1_THRESHOLD 200
#define BUTTON2_THRESHOLD 400
#define BUTTON3_THRESHOLD 600

void initializeButtons() {
    pinMode(BUTTON_PIN, INPUT);
}

int readMultiplexedButton() {
    int analogValue = analogRead(BUTTON_PIN);

    if (analogValue < BUTTON1_THRESHOLD) {
        return 1; // first button
    } else if (analogValue < BUTTON2_THRESHOLD) {
        return 2; // second button
    } else if (analogValue < BUTTON3_THRESHOLD) {
        return 3; // third button
    }

    return -1; // no button was pressed
}