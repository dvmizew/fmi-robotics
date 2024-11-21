#ifndef BUTTONS_H
#define BUTTONS_H

#include <Arduino.h>

#define BUTTON_PIN A0 // analog pin for reading the buttons

// because the buttons are multiplexed, we define thresholds for each button
#define BUTTON1_THRESHOLD 200
#define BUTTON2_THRESHOLD 400
#define BUTTON3_THRESHOLD 600

#define DEBOUNCE_DELAY 50 
#define NO_BUTTON_PRESSED -1 // default value for no button pressed
#define START_BUTTON_PRESSED 100

void initializeButtons(); // uses the A0 pin to read the buttons
int readMultiplexedButton();

#endif