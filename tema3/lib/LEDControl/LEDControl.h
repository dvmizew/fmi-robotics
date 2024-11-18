#ifndef LEDCONTROL_H
#define LEDCONTROL_H

#include <Arduino.h>
#include "RGBUtils.h"

void initializeLEDs();
void setPlayerRGBColor(int player, int color);
void turnOffRGB(int player);
void blinkLED(int pin);

#endif