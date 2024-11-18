#ifndef DISPLAY_H
#define DISPLAY_H

#include <LiquidCrystal.h>

// LCD pins
#define RS 12
#define E 11
#define D4 5
#define D5 4
#define D6 3
#define D7 2

void initializeLCD();
void displayWelcomeMessage();
void updateScore(int player1Score, int player2Score);
void displayWinner(int player);
void displayPauseMessage();

#endif