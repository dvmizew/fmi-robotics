#include "RGBUtils.h"

void setRGBColor(int redPin, int greenPin, int bluePin, int color) {
    digitalWrite(redPin, color == 1);
    digitalWrite(greenPin, color == 2);
    digitalWrite(bluePin, color == 3);
}

void turnOffRGB(int redPin, int greenPin, int bluePin) {
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, LOW);
    digitalWrite(bluePin, LOW);
}