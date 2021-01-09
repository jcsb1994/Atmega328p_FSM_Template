#ifndef FSM_H
#define FSM_H

#include "FSM/UI.h"


class FSM
{
private:
    /* data */
    UI myUI;
    event incoming_event;
    void (*state_handler)();
    event extract_incoming_event();

public:
    FSM(void initial_state(void));
    ~FSM();

    event poll();

    void handle_state();
    void set_state(void state(void)) {state_handler = state; }
};


#endif