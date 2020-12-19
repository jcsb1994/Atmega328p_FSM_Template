#ifndef _74HC165_H
#define _74HC165_H


#include <stdint.h>
#include <SPI.h>


#define LOAD_PIN 5


/***************************************************************************
 * SPI_init function
 * 
 * SPI protocol is initialized.
 * SPI is needed to get data from the 74hc165 shift registers
 * 
 ***************************************************************************/

void SPI_init();

/***************************************************************************
 * inputShiftSnapShot function
 * 
 * 1) Turn the loadPin HIGH for a millisecond, saves the state of the input pins
 * at a given moment
 * 2) 1 empty byte is transfered for each shift register via the SPI protocol
 *    and received exchange byte is stored in the shift register's data member.
 * 
 ***************************************************************************/

void inputShiftSnapShot();

#endif