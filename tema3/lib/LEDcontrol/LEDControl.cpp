#include "LEDControl.h"

// Player 1 RGB LED pins
#define RGB_LED_PLAYER1_RED 9
#define RGB_LED_PLAYER1_GREEN 10
#define RGB_LED_PLAYER1_BLUE 11

// Player 2 RGB LED pins
#define RGB_LED_PLAYER2_RED 6
#define RGB_LED_PLAYER2_GREEN 5
#define RGB_LED_PLAYER2_BLUE 3

void initializeLEDs() {
    // Player 1 RGB LED pins
    pinMode(RGB_LED_PLAYER1_RED, OUTPUT);
    pinMode(RGB_LED_PLAYER1_GREEN, OUTPUT);
    pinMode(RGB_LED_PLAYER1_BLUE, OUTPUT);

    // Player 2 RGB LED pins
    pinMode(RGB_LED_PLAYER2_RED, OUTPUT);
    pinMode(RGB_LED_PLAYER2_GREEN, OUTPUT);
    pinMode(RGB_LED_PLAYER2_BLUE, OUTPUT);
}

void setRGBColor(int player, int color) {
    if (player == 1) {
        setRGBColor(RGB_LED_PLAYER1_RED, RGB_LED_PLAYER1_GREEN, RGB_LED_PLAYER1_BLUE, color);
    }
    else if (player == 2) {
        setRGBColor(RGB_LED_PLAYER2_RED, RGB_LED_PLAYER2_GREEN, RGB_LED_PLAYER2_BLUE, color);
    }
}

void turnOffRGB(int player) {
    if (player == 1) {
        turnOffRGB(RGB_LED_PLAYER1_RED, RGB_LED_PLAYER1_GREEN, RGB_LED_PLAYER1_BLUE);
    } 
    else {
        turnOffRGB(RGB_LED_PLAYER2_RED, RGB_LED_PLAYER2_GREEN, RGB_LED_PLAYER2_BLUE);
    }
}
