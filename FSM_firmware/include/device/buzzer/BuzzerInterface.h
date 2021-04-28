#ifndef BUZZER_INTERFACE_H
#define BUZZER_INTERFACE_H

#include <Arduino.h>

#define BUZZER_PIN 7

#define D4_NOTE_FREQ (293)
#define E4_NOTE_FREQ (329)
#define F4_NOTE_FREQ (349)
#define G4_NOTE_FREQ (392)
#define A4_NOTE_FREQ (440)
#define B4_NOTE_FREQ (494)
#define C5_NOTE_FREQ (523)
#define E5_NOTE_FREQ (659)

#define MELODY_NOTE_MAX_NB (3)

/**********
 * The instance steps every ISR. step delay is specified in the ctor.
 * a melody is initialized with setMelody(). the tone will ring, when stepping
 * is complete, melody is set back to null
 *
 */

typedef struct {
    uint8_t nbNotes;
    uint16_t duration[MELODY_NOTE_MAX_NB];
    uint16_t frequency[MELODY_NOTE_MAX_NB];
} Melody_t;

typedef enum { S_BUZZER_IDLE, S_BUZZER_ACTIVE, S_BUZZER_PLAYING } BuzzerState_t;

class BuzzerInterface {
  private:
    const uint8_t _pin;
    const uint16_t _stepPeriod;
    Melody_t *_Melody;
    uint16_t _stepCount;
    uint8_t _currNote;
    BuzzerState_t _state;

    void _reset();

  public:
    BuzzerInterface(uint8_t pin, uint16_t _stepPeriod)
        : _pin(pin), _stepPeriod(_stepPeriod) {}
    ~BuzzerInterface() {}

    void setMelody(Melody_t *mel) {
        _reset();
        _Melody = mel;
    }
    void step();
};

#endif