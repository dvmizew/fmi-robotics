#ifndef GAMECONTROL_H
#define GAMECONTROL_H

#define BUZZER_PIN 4 // buzzer pin for playing sounds
#define SS_PIN 10 // slave select pin for SPI communication

#include <Arduino.h>
#include <Servo.h>
#include <SPI.h>

void initializeServo();
void startGame();
void updateGame();
void playCorrectSound();
void initializeSPI();
void sendCommandToSlave(int command);

#endif