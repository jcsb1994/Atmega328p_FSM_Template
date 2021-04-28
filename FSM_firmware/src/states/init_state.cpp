
#include "main.h"
#include "FSM/states.h"
#include "FSM/events.h"

// ----------------------------------------------------------------------
//      INIT STATE
// ----------------------------------------------------------------------

void init_state_handler()
{
    // tft setup
    tft.init(240, 240, SPI_MODE2);
    tft.setRotation(2);
    tft.setTextWrap(true);
    tft.fillScreen(ST77XX_YELLOW);
    tft.setCursor(30, 30);
    tft.setTextSize(3);
    tft.setTextColor(ST77XX_WHITE);
    tft.print("Hello");

    // buzzer setup
    Buzzer.setMelody(&initMelody);

    // next state
    machine.set_state(main_state_handler);
    machine.update_widget_map_size(2,3);

    refreshFlag = true;
}
