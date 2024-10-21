#include <Arduino.h>

#define led1 10 // 25%
#define led2 9	// 50%
#define led3 8	// 75%
#define led4 7	// 100%

#define ledR 6 // red
#define ledG 5 // green
#define ledB 4 // blue

#define buttonStart 3
#define buttonStop 2

bool charging = false;
bool stationFree = true;

unsigned long lastMillis;
int currentStep = 0; // 0 = libera, 1 = 25%, 2 = 50%, 3 = 75%, 4 = 100%

void resetStation();
void startCharging();
void stopCharging();
void updateChargingProgress();
void blinkLED(int ledPin);
void blinkAllLEDs();

void setup() {
	pinMode(led1, OUTPUT);
	pinMode(led2, OUTPUT);
	pinMode(led3, OUTPUT);
	pinMode(led4, OUTPUT);

	pinMode(ledR, OUTPUT);
	pinMode(ledG, OUTPUT);
	pinMode(ledB, OUTPUT);

	pinMode(buttonStart, INPUT_PULLUP);
	pinMode(buttonStop, INPUT_PULLUP);

	resetStation();
}

void loop() {
	// apasarea butonului start cand statia este libera
	if (digitalRead(buttonStart) == LOW && stationFree) {
		delay(50); // debounce
		startCharging();
	}

	// apasarea lunga a butonului stop cand statia este ocupata
	if (digitalRead(buttonStop) == LOW && !stationFree) {
		long pressDuration = 0;
		while (digitalRead(buttonStop) == LOW) {
			pressDuration++;
			delay(10);
			if (pressDuration > 100) { // 1 sec
				stopCharging();
				break;
			}
		}
	}

	if (charging) {
		updateChargingProgress();
	}
}

void resetStation() {
	stationFree = true;
	charging = false;
	currentStep = 0;

	digitalWrite(led1, LOW);
	digitalWrite(led2, LOW);
	digitalWrite(led3, LOW);
	digitalWrite(led4, LOW);

	digitalWrite(ledR, LOW);
	digitalWrite(ledG, HIGH);
	digitalWrite(ledB, LOW);
}

void startCharging() {
	stationFree = false;
	charging = true;

	digitalWrite(ledR, HIGH);
	digitalWrite(ledG, LOW);
	digitalWrite(ledB, LOW);

	lastMillis = millis();
	currentStep = 1; // we start at 25%
}

void stopCharging() {
	charging = false;
	blinkAllLEDs();
	resetStation();
}

void updateChargingProgress() {
	if (millis() - lastMillis >= 3000) {
		lastMillis = millis();

		if (currentStep == 1) {
			blinkLED(led1);
		}
		else if (currentStep == 2) {
			digitalWrite(led1, HIGH);
			blinkLED(led2);
		}
		else if (currentStep == 3) {
			digitalWrite(led2, HIGH);
			blinkLED(led3);
		}
		else if (currentStep == 4) {
			digitalWrite(led3, HIGH);
			blinkLED(led4);
		}
		else if (currentStep == 5) {
			// incarcare completa
			digitalWrite(led4, HIGH);
			blinkAllLEDs();
			resetStation();
		}
		currentStep++;
	}
}

void blinkAllLEDs() {
	for (int i = 0; i < 3; i++) {
		digitalWrite(led1, HIGH);
		digitalWrite(led2, HIGH);
		digitalWrite(led3, HIGH);
		digitalWrite(led4, HIGH);
		delay(500);
		digitalWrite(led1, LOW);
		digitalWrite(led2, LOW);
		digitalWrite(led3, LOW);
		digitalWrite(led4, LOW);
		delay(500);
	}
}

void blinkLED(int ledPin) {
	for (int i = 0; i < 3; i++){
		digitalWrite(ledPin, HIGH);
		delay(500);
		digitalWrite(ledPin, LOW);
		delay(500);
	}
	digitalWrite(ledPin, HIGH);
}