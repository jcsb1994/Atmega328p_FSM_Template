#ifndef UI_H
#define UI_H

#include "../FSM/tact.h"
#include "../FSM/menu.h"


class UI
{
private:

    tact myTacts[TACT_NB];

    event m_incoming_event = nothing;

public:
    UI();
    ~UI();

    menu Menu;

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