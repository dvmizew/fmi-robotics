#ifndef BUTTONS_H
#define BUTTONS_H

#include <Arduino.h>

void initializeButtons(); // uses the A0 pin to read the buttons
int readMultiplexedButton();

#endif
