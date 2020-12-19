
#include "main.h"
#include "FSM/states.h"
#include "FSM/events.h"

void read_state_handler()
{
    /*
    Read sensors, solve refresh flags, ...
    */

    switch (machine.poll_ui())
    {
    case events::nothing:
    default:
        break;
    }
}