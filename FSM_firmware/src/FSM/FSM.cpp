#include "FSM/FSM.h"


void init_state_handler();

FSM::FSM(void initial_state(void))
{
    myUI = UI();
    state_handler = initial_state;
}

FSM::~FSM()
{
}

event FSM::extract_incoming_event()
{
    event ev = incoming_event;
    incoming_event = event::nothing;
    return ev;
}

event FSM::poll()
{
    if (incoming_event != event::nothing)
    {
        return extract_incoming_event();
    }

    // poll desired UI user inputs (tacts, encoders, etc.)
    myUI.poll_tacts();

    // get any event that occured in the polled input widgets
    incoming_event = myUI.extract_event();


/*     if (incoming_UI_event)
    {
        Serial.print("FSM event");
        Serial.println(incoming_UI_event);
    } */

    return incoming_event;
}


void FSM::handle_state()
{
    state_handler();
}