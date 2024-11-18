#ifndef GAMECONTROL_H
#define GAMECONTROL_H

#define BUZZER_PIN 4 // buzzer pin for playing sounds
#define SS_PIN 10 // slave select pin for SPI communication
#define SERVO_PIN 6 // servo pin for moving the button

#include <Arduino.h>
#include <Servo.h>
#include <SPI.h>

void initializeSerial();
void initializeServo();
void startGame();
void updateGame();
void playCorrectSound();
void initializeSPI();
void sendCommandToSlave(int command);
void printDebug(String message);

#endif