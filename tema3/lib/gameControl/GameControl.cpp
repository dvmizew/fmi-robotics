#include "GameControl.h"
#include "Buttons.h"
#include "LEDControl.h"
#include "Display.h"
#include <SPI.h>
#include <Servo.h>

Servo gameServo;
int player1Score = 0;
int player2Score = 0;
int currentPlayer = 1;
unsigned long lastUpdateTime = 0;
const int roundDuration = 3000;  // durata rundelor in milisecunde

void initializeSPI() {
    SPI.begin();
}

void initializeServo() {
    gameServo.attach(6);
    gameServo.write(0);
}

void startGame() {
    displayWelcomeMessage();
    player1Score = 0;
    player2Score = 0;
    currentPlayer = 1;
    lastUpdateTime = millis();
}

void updateGame() {
    if (millis() - lastUpdateTime > roundDuration) {
        lastUpdateTime = millis();
        int correctButton = random(1, 4); // buton random

        setRGBColor(currentPlayer, correctButton);

        int buttonPress = getPlayerButtonPress(currentPlayer);
        if (buttonPress == correctButton) {
            if (currentPlayer == 1) 
                player1Score++;
            else 
                player2Score++;
                
            updateScore(player1Score, player2Score);
        }
        
        gameServo.write(gameServo.read() + 10);

        if (gameServo.read() >= 180) {
            endGame();
        }
        
        currentPlayer = (currentPlayer == 1) ? 2 : 1;  // schimbam intre jucatori
        turnOffRGB(currentPlayer);
    }
}

void endGame() {
    if (player1Score > player2Score) displayWinner(1);
    else displayWinner(2);
    gameServo.write(0);
}