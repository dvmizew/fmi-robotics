#ifndef SLAVE_H
#define SLAVE_H

#include <SPI.h>
#include "LEDControl.h"

#define RGB_LED_RED 9
#define RGB_LED_GREEN 10
#define RGB_LED_BLUE 11

void handleMasterCommand(int command);

#endif