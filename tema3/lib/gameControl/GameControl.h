#ifndef GAMECONTROL_H
#define GAMECONTROL_H

#include <Arduino.h>

void initializeSPI();
void initializeServo();
void startGame();
void updateGame();
void endGame();

#endif