#include "RGBUtils.h"

void setRGBColor(int redPin, int greenPin, int bluePin, int color) {
    digitalWrite(redPin, color == 1); // 1 - RED
    digitalWrite(greenPin, color == 2); // 2 - GREEN
    digitalWrite(bluePin, color == 3); // 3 - BLUE
}

void turnOffRGB(int redPin, int greenPin, int bluePin) {
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, LOW);
    digitalWrite(bluePin, LOW);
}