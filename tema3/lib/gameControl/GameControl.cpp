#include "GameControl.h"
#include "Buttons.h"
#include "LEDControl.h"
#include "Display.h"
#include <Servo.h>
#include <SPI.h>

#define SS_PIN 10 // slave select pin for SPI communication

Servo gameServo;
int player1Score = 0;
int player2Score = 0;
int currentPlayer = 1;
unsigned long lastUpdateTime = 0;
const int roundDuration = 3000;  // round duration in milliseconds

void initializeSPI() {
    SPI.begin();
    pinMode(SS_PIN, OUTPUT);
    digitalWrite(SS_PIN, HIGH); // disable initial slave device
}

void initializeServo() {
    gameServo.attach(6); // attach the servo to pin 6
    gameServo.write(0); // set the initial position of the servo
}

void sendCommandToSlave(int command) {
    digitalWrite(SS_PIN, LOW); // enable the slave device
    SPI.transfer(command); // send the command to the slave device
    digitalWrite(SS_PIN, HIGH); // disable the slave device
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
        displayPauseMessage();
        lastUpdateTime = millis(); // reset the timer
        int correctButton = random(1, 4);
        sendCommandToSlave(correctButton); // send the correct button to the slave device
        
        int buttonPressed = readMultiplexedButton(); // read the button pressed by the player
        if (buttonPressed > 0 && buttonPressed == correctButton) { // check if the correct button was pressed
            playCorrectSound(); // play a sound to indicate a correct button press
            if (currentPlayer == 1)
                player1Score++;
            else if (currentPlayer == 2)
                player2Score++;
            updateScore(player1Score, player2Score); // update the score on the display
        }

        gameServo.write(gameServo.read() + 10); // move the servo by 10 degrees because the player missed the button
        if (gameServo.read() >= 180) { // check if the servo has reached the end position
            displayWinner(player1Score > player2Score ? 1 : 2);
            gameServo.write(0); // back to the initial position
        }

        currentPlayer = (currentPlayer == 1) ? 2 : 1; // change the player
    }
}

void playCorrectSound() {
    // play a sound to indicate a correct button press
    tone(BUZZER_PIN, 1000, 200);  // at 1khz for 200ms
}

void playGameOverSound() {
    // play a sound to indicate the end of the game
    tone(BUZZER_PIN, 500, 500);   // at 0.5khz for 500ms
}