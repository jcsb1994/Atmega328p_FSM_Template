#include "device/Atmega328p/Atmega328p_Timers.h"

/*##################################################
            WDT
##################################################*/

#if WDT_CONFIG

// counter should be flag and if not set,  the system restarts
volatile uint8_t wdt_counter; // Volatile is preferable when modified in WDT

void WDT_setup()
{
    WDTCSR = (24); // Change enable and WDE - also resets

    //prescalers only - get rid of the WDE and WDCE bit.

#if WDT_PERIOD == 8000
    WDTCSR = (0b100001); // 8 sec
#endif

#if WDT_PERIOD == 4000
    WDTCSR = (0b100000); // 4 sec
#endif

#if WDT_PERIOD == 1000
    WDTCSR = (6); // 1 sec
#endif

#if WDT_PERIOD == 125
    WDTCSR = (3); // 0,125 sec
#endif

#if WDT_PERIOD == 64
    WDTCSR = (2); //64 ms
#endif

#if WDT_PERIOD == 32
    WDTCSR = (1); //32 ms
#endif

#if WDT_PERIOD == 16
    WDTCSR = (0);
#endif

    WDTCSR |= (1 << 6); //enable interrupt mode - WDT as an interrupt is useful to wake up from sleep
}

#endif

/*##################################################
            TIMER 1
##################################################*/

#if TIMER_ONE_CONFIG

void timer1_setup()
{
    cli();
    //set timer1 interrupt at 1Hz
    TCCR1A = 0; // set entire TCCR1A register to 0
    TCCR1B = 0; // same for TCCR1B
    TCNT1 = 0;  //initialize counter value to 0
    // set compare match register for 1hz increments
    OCR1A = 15624; // = (16*10^6) / (1*1024) - 1 (must be <65536)
    // turn on CTC mode
    TCCR1B |= (1 << WGM12);
    // Set CS10 and CS12 bits for 1024 prescaler
    TCCR1B |= (1 << CS12) | (1 << CS10);
    // enable timer compare interrupt
    TIMSK1 |= (1 << OCIE1A);
    sei();
}

#endif

#if TIMER_ZERO_CONFIG

// timer 0 controls PWM outputs on 5 and 6
void timer0_setup()
{
    cli();
    TCCR0A = 0; // set entire TCCR2A register to 0
    TCCR0B = 0; // same for TCCR2B
    TCNT0 = 0;  //initialize counter value to 0
    // set compare match register for 2khz increments
    OCR0A = 124; // = 16MHz / (3*1024) - 1 (must be <256)
    // turn on CTC mode
    TCCR0A |= (1 << WGM01);
    // Set CS02 and CS00 bits for 1024 prescaler
    TCCR0B |= (1 << CS02) | (1 << CS00);
    // enable timer compare interrupt
    TIMSK0 |= (1 << OCIE0A);
    sei();
}

#endif