#ifndef DISPLAY_H
#define DISPLAY_H

#include <Arduino.h>

void initializeLCD();
void displayWelcomeMessage();
void updateScore(int player1Score, int player2Score);
void displayWinner(int player);

#endif