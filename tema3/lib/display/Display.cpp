#include "Display.h"
#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

void initializeLCD() {
    lcd.begin(16, 2);
}

void displayWelcomeMessage() {
    lcd.clear();
    lcd.print("Welcome!");
}

void updateScore(int player1Score, int player2Score) {
    lcd.setCursor(0, 0);
    lcd.print("P1: ");
    lcd.print(player1Score);
    lcd.setCursor(0, 1);
    lcd.print("P2: ");
    lcd.print(player2Score);
}

void displayWinner(int player) {
    lcd.clear();
    lcd.print("Winner: P");
    lcd.print(player);
}