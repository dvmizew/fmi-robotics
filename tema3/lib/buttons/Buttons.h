#ifndef BUTTONS_H
#define BUTTONS_H

#include <Arduino.h>

void initializeButtons();
bool isStartButtonPressed();
int getPlayerButtonPress(int player);

#endif