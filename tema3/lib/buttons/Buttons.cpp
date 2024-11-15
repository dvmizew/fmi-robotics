#include "Buttons.h"

#define BUTTON1_PIN 2
#define BUTTON2_PIN 3
#define BUTTON3_PIN 4
#define START_BUTTON_PIN 5

void initializeButtons() {
    pinMode(BUTTON1_PIN, INPUT);
    pinMode(BUTTON2_PIN, INPUT);
    pinMode(BUTTON3_PIN, INPUT);
    pinMode(START_BUTTON_PIN, INPUT);
}

bool isStartButtonPressed() {
    return digitalRead(START_BUTTON_PIN) == HIGH;
}

int getPlayerButtonPress(int player) {
    if (digitalRead(BUTTON1_PIN) == HIGH) return 1;
    if (digitalRead(BUTTON2_PIN) == HIGH) return 2;
    if (digitalRead(BUTTON3_PIN) == HIGH) return 3;
    return -1;
}