#ifndef UI_H
#define UI_H

#include "../FSM/tact.h"



class UI
{
private:

    tact myTacts[TACT_NB];
    // int m_tacts_states[TACT_NB];
    event m_incoming_event = nothing;

public:
    UI(/* args */);
    ~UI();


    void poll_tacts();

    event extract_event()
    {
        if (m_incoming_event)
        {

            Serial.println("FSM event");
            Serial.println(m_incoming_event);

            event event = m_incoming_event;
            m_incoming_event = nothing;
            return event;
        }
        else
            return nothing;
    }
};




#endif