#include "LEDControl.h"

#define RGB_LED_PIN_PLAYER1 9
#define RGB_LED_PIN_PLAYER2 10

void initializeLEDs() {
    pinMode(RGB_LED_PIN_PLAYER1, OUTPUT);
    pinMode(RGB_LED_PIN_PLAYER2, OUTPUT);
}

void setRGBColor(int player, int color) {
    if (player == 1) {
        analogWrite(RGB_LED_PIN_PLAYER1, color);
    } else {
        analogWrite(RGB_LED_PIN_PLAYER2, color);
    }
}

void turnOffRGB(int player) {
    if (player == 1) {
        digitalWrite(RGB_LED_PIN_PLAYER1, LOW);
    } else {
        digitalWrite(RGB_LED_PIN_PLAYER2, LOW);
    }
}