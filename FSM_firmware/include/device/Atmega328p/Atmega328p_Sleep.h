#ifndef ATMEGA328P_SLEEP_H
#define ATMEGA328P_SLEEP_H

#include <Arduino.h>

#define SLEEP_CONFIG 0

void sleep_setup();

/***************************************************************************
 * activate_sleep function
 * 
 * This function turns sleep on for Atmega328p
 * 
 ***************************************************************************/

void activate_sleep();

#endif // ATMEGA328P_SLEEP_H