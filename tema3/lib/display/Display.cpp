#include "Display.h"
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

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

void displayPauseMessage() {
    lcd.clear();
    lcd.print("Next Round...");
    delay(2000); // pause of 2 seconds
}