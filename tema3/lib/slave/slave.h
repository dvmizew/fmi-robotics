#ifndef SLAVE_H
#define SLAVE_H

#include <SPI.h>
#include "LEDControl.h"

void handleMasterCommand(int command);

#endif