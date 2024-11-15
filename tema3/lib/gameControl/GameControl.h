#ifndef GAMECONTROL_H
#define GAMECONTROL_H
#define BUZZER_PIN 4

#include <Arduino.h>

void initializeServo();
void startGame();
void updateGame();
void playCorrectSound();
void initializeSPI();
void sendCommandToSlave(int command);

#endif