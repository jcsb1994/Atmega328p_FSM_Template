
#include "main.h"
#include "FSM/states.h"
#include "FSM/events.h"

void list_state_handler()
{
    if (refreshFlag)
    {
        tft.setTextSize(2);
        tft.fillScreen(ST77XX_BLACK);
        tft.setCursor(0, 0);
        tft.setTextColor(ST77XX_WHITE);
        tft.print("Values: ");
        refreshFlag = false;
        valuesRefreshFlag = true;
    }

    if (valuesRefreshFlag)
    {
        tft.print("2");
        valuesRefreshFlag = false;
    }

    switch (machine.poll_ui())
    {
    case events::increment:
        valuesRefreshFlag = true;
        break;

    case events::nothing:
    default:
        break;
    }
}