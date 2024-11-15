#ifndef LEDCONTROL_H
#define LEDCONTROL_H

#include <Arduino.h>

void initializeLEDs();
void setRGBColor(int player, int color);
void turnOffRGB(int player);

#endif