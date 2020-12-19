#ifndef FSM_H
#define FSM_H

#include "FSM/UI.h"


class FSM
{
private:
    /* data */
    UI myUI;
    events incoming_UI_event;
    void (*state_handler)();

public:
    FSM(void initial_state(void));
    ~FSM();

    events poll_ui();

    void handle_state();
    void set_state(void state(void)) {state_handler = state; }
};


#endif