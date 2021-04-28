#include "main.h"
#include "FSM/states.h"
#include "FSM/events.h"

// ----------------------------------------------------------------------
//      PIN MAPPING
// MCU pin usage definitions
// ----------------------------------------------------------------------

#define BUZZER_PIN 7

#define TFT_CS 10 // define chip select pin
#define TFT_DC 9  // define data/command pin
#define TFT_RST 8 // define reset pin, or set to -1 and connect to Arduino RESET pin

struct tact_link tact_links[TACT_NB]{{0, nothing, up, nothing},
                                     {1, nothing, left, nothing},
                                     {2, nothing, enter, nothing},
                                     {3, nothing, down, nothing},
                                     {4, nothing, right, nothing}};


// ----------------------------------------------------------------------
//      GLOBAL
// Global variables, declared extern here to be accessed by states source files
// ----------------------------------------------------------------------

bool refreshFlag = false;
bool valuesRefreshFlag = false;

volatile uint8_t timerOneFlagIterator = 0;

Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_RST);
BuzzerInterface Buzzer = BuzzerInterface(BUZZER_PIN, 14);

Melody_t initMelody{.nbNotes = 3,
                    .duration = {200, 200, 400},
                    .frequency = {G4_NOTE_FREQ, B4_NOTE_FREQ, C5_NOTE_FREQ}};

// ----------------------------------------------------------------------
//      MAIN
// Setup, main loop, ISRs
// ----------------------------------------------------------------------

void setup()
{
#if __USING_DEBUG_MODE__
    Serial.begin(9600);
    pinMode(DEBUG_LED_PIN, OUTPUT);
#endif
}

FSM machine(init_state_handler);

void loop()
{
    machine.handle_state();
}

ISR(TIMER0_COMPA_vect)
{
    timerOneFlagIterator++;
}

ISR(TIMER1_COMPA_vect) { Buzzer.step(); }