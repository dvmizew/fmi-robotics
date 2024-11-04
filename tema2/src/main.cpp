#include <Arduino.h>
#include <dictionary.h>

#define PIN_RED 10
#define PIN_GREEN 9
#define PIN_BLUE 8
#define PIN_START 2
#define PIN_DIFFICULTY 3

#define TIMER_BASE_COUNT 62500 // 16MHz / 256 / 1Hz = 62500
#define SERIAL_BAUD 9600

#define BUTTON_DEBOUNCE_DELAY 500
#define INITIAL_BLINK_DURATION 500
#define INITIAL_DURATION 3000

#define TOTAL_GAME_TIME 30
#define EASY_MODE_TIME 10
#define MEDIUM_MODE_TIME 5
#define HARD_MODE_TIME 2

volatile int remainingWordTime = EASY_MODE_TIME;
volatile unsigned int remainingGameTime = TOTAL_GAME_TIME;

unsigned long lastStartStopTime = 0;
unsigned long lastDifficultyChangeTime = 0;
unsigned long blinkTimer = 0;
unsigned long startTime = 0;

unsigned int blinkCount = 0;
unsigned int correctGuesses = 0;

bool startStopPressed = false;
bool difficultyPressed = false;
bool requestNewWord = false;
bool gameFinished = false;

String activeWord;
String playerInput = "";
String serialBuffer = "";

enum GamePhase {
    PHASE_IDLE,
    PHASE_STARTING,
    PHASE_RUNNING
};

enum LevelDifficulty {
    DIFFICULTY_EASY,
    DIFFICULTY_MEDIUM,
    DIFFICULTY_HARD
};

GamePhase currentPhase;
LevelDifficulty currentDifficulty;

void handleIdlePhase();
void handleStartingPhase();
void handleRunningPhase();
void generateNewWord();
void switchToIdle();
void switchToStart();
void switchToRunning();
void processStartButton();
void processDifficultyButton();
void resetLEDs();
void lightWhiteLED();
void lightGreenLED();
void lightRedLED();
void changeDifficulty();

ISR(TIMER1_COMPA_vect) {
    // Timer interrupt handler to keep track of the remaining time for the word and the game
    if (currentPhase != PHASE_RUNNING)
        return;

    remainingWordTime--;
    remainingGameTime--;

    if (remainingWordTime <= 0)
        requestNewWord = true;

    if (remainingGameTime == 0)
        gameFinished = true;
}

void setup() {
    // Set up the pins for the LEDs
    pinMode(PIN_RED, OUTPUT);
    pinMode(PIN_GREEN, OUTPUT);
    pinMode(PIN_BLUE, OUTPUT);

    // Set up the buttons
    pinMode(PIN_START, INPUT_PULLUP);
    pinMode(PIN_DIFFICULTY, INPUT_PULLUP);

    // Attach interrupts to buttons to detect presses
    attachInterrupt(digitalPinToInterrupt(PIN_START), processStartButton, FALLING);
    attachInterrupt(digitalPinToInterrupt(PIN_DIFFICULTY), processDifficultyButton, FALLING);

    // Initialize serial communication
    Serial.begin(SERIAL_BAUD);
    switchToIdle();

    randomSeed(millis());

    noInterrupts(); // Disable interrupts while setting up the timer

    TCCR1A = 0;
    TCCR1B = 0;

    TCNT1 = TIMER_BASE_COUNT; // Set the initial value for the timer (1Hz)
    TCCR1B |= (1 << CS12); // Set the prescaler to divide the frequency by 256
    TIMSK1 |= (1 << OCIE1A); // Enable interrupt on compare match

    interrupts();
}

// specific Arduino function to handle serial events
void serialEvent() {
    while (Serial.available())
        serialBuffer += (char)Serial.read();
}

void loop() {
    switch (currentPhase) {
        case PHASE_IDLE:
            handleIdlePhase();
            break;
        case PHASE_STARTING:
            handleStartingPhase();
            break;
        case PHASE_RUNNING:
            handleRunningPhase();
            break;
    }
}

void handleIdlePhase() {
    if (startStopPressed) {
        switchToStart();
        Serial.println("\nStarting!");
        startStopPressed = false; // reset the flag
    }

    if (difficultyPressed) {
        changeDifficulty();
        difficultyPressed = false; // reset the flag
    }
}

void handleStartingPhase() {
    blinkTimer = millis() - startTime; // calculate the time elapsed since the start of the phase

    if (blinkTimer > INITIAL_BLINK_DURATION * blinkCount) {
        if (blinkCount % 2 == 0) {
            lightWhiteLED();
        } else {
            resetLEDs();
            // Display the countdown on the serial monitor
            int countdown = 3 - blinkCount / 2;
            if (countdown > 0) {
                Serial.println(countdown);
            }
        }
        blinkCount++;
    }

    if (blinkTimer > INITIAL_DURATION) { // after the initial duration, switch to the running phase
        Serial.println("\nGo!");
        switchToRunning();
    }
}

void handleRunningPhase() {
    if (startStopPressed) {
        Serial.println("\nGame stopped!");
        switchToIdle();
        startStopPressed = false;
    }

    if (requestNewWord) {
        generateNewWord();
        requestNewWord = false;
    }

    if (gameFinished) {
        Serial.println("\nGame over!");
        Serial.print("Ai ghicit ");

        if (correctGuesses == 1)
            Serial.println("un singur cuvant!");
        else if (correctGuesses < 20) {
            Serial.print(correctGuesses);
            Serial.println(" cuvinte!");
        }
        else if (correctGuesses) {
            Serial.print(correctGuesses);
            Serial.println(" de cuvinte!");
        }

        switchToIdle();
        gameFinished = false;
    }

    if (serialBuffer.length() > 0) {
        char inputChar = serialBuffer.charAt(0); // get the first character from the serial buffer
        serialBuffer.remove(0, 1); // remove the first character from the serial buffer because it was processed already

        if (inputChar == '\b' && playerInput.length() > 0) {
            // when backspace is pressed, remove the last character from the player input string and light up the LEDs based on the input correctness
            playerInput.remove(playerInput.length() - 1);
            (activeWord.startsWith(playerInput)) ? lightGreenLED() : lightRedLED();
        } else if (isAlpha(inputChar) || inputChar == ' ') {
            // only process alphabetic characters and spaces (for multi-word phrases)
            inputChar = tolower(inputChar);
            playerInput += inputChar;

            // check if the player input matches the active word
            if (playerInput == activeWord) {
                correctGuesses++;
                Serial.println("\nCorect!");
                requestNewWord = true;
            }
            // when a character is pressed, light up the LEDs based on the input correctness
            (activeWord.startsWith(playerInput)) ? lightGreenLED() : lightRedLED();
        }
    }
}

void processStartButton() {
    unsigned long currentTime = millis();
    if (currentTime - lastStartStopTime > BUTTON_DEBOUNCE_DELAY) {
        startStopPressed = true;
        lastStartStopTime = currentTime;
    }
}

void processDifficultyButton() {
    if (currentPhase != PHASE_IDLE)
        return;

    unsigned long currentTime = millis();
    if (currentTime - lastDifficultyChangeTime > BUTTON_DEBOUNCE_DELAY) {
        difficultyPressed = true;
        lastDifficultyChangeTime = currentTime;
    }
}

void changeDifficulty() {
    if (currentPhase != PHASE_IDLE)
        return;

    switch (currentDifficulty) {
        case DIFFICULTY_EASY:
            currentDifficulty = DIFFICULTY_MEDIUM;
            Serial.println(difficultyMessages[1]);  // Medium
            break;
        case DIFFICULTY_MEDIUM:
            currentDifficulty = DIFFICULTY_HARD;
            Serial.println(difficultyMessages[2]);  // Hard mode on!
            break;
        case DIFFICULTY_HARD:
        default:
            currentDifficulty = DIFFICULTY_EASY;
            Serial.println(difficultyMessages[0]);  // Easy
            break;
    }
}

void generateNewWord() {
    switch (currentDifficulty) {
        case DIFFICULTY_EASY:
            remainingWordTime = EASY_MODE_TIME;
            break;
        case DIFFICULTY_MEDIUM:
            remainingWordTime = MEDIUM_MODE_TIME;
            break;
        case DIFFICULTY_HARD:
            remainingWordTime = HARD_MODE_TIME;
            break;
    }

    int index = random(dictionaryLen);
    activeWord = String(dictionary[index]);
    playerInput = ""; // reset the player input
    serialBuffer = ""; // reset the serial buffer
    lightGreenLED();

    Serial.println("\nCuvant:");
    Serial.println(activeWord);
}

void switchToIdle() {
    lightWhiteLED();
    currentPhase = PHASE_IDLE;
    currentDifficulty = DIFFICULTY_EASY;
}

void switchToStart() {
    resetLEDs();
    startTime = millis();
    blinkTimer = 0;
    blinkCount = 1;
    currentPhase = PHASE_STARTING;
}

void switchToRunning() {
    lightGreenLED();
    remainingGameTime = TOTAL_GAME_TIME;
    remainingWordTime = 0;
    correctGuesses = 0;
    currentPhase = PHASE_RUNNING;
}

// LED functions
void setLEDs(bool red, bool green, bool blue) {
    digitalWrite(PIN_RED, red ? HIGH : LOW);
    digitalWrite(PIN_GREEN, green ? HIGH : LOW);
    digitalWrite(PIN_BLUE, blue ? HIGH : LOW);
}

void lightWhiteLED() {
    setLEDs(true, true, true);
}

void lightGreenLED() {
    setLEDs(false, true, false);
}

void lightRedLED() {
    setLEDs(true, false, false);
}

void resetLEDs() {
    setLEDs(false, false, false);
}
