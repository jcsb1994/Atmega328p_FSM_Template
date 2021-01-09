
#include "main.h"
#include "FSM/states.h"
#include "FSM/events.h"

int var_one = 1;
int var_two = 2;
int var_three = 3;

void main_state_handler()
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

    int val_map[machine.get_widget_count()] = {0};
    for (unsigned int i = 0; i < (sizeof(val_map) / sizeof(val_map[0])); i++)
    {
        if (machine.get_target_widget() == i)
            val_map[i] = ST77XX_MAGENTA;
        else
            val_map[i] = ST77XX_WHITE;
    }

    if (valuesRefreshFlag)
    {

        tft.setCursor(0, 80);
        tft.setTextColor(val_map[0]);
        tft.println(var_one);
        tft.setTextColor(val_map[1]);
        tft.println(var_two);
        tft.setTextColor(val_map[2]);
        tft.println(var_three);
        valuesRefreshFlag = false;
    }

    switch (machine.poll())
    {
/*     case event::left:
        refreshFlag = true; */
    case event::up:
        valuesRefreshFlag = true;
        machine.move_cursor_x(-1);
        break;

/*     case event::right:
        refreshFlag = true; */
    case event::down:
        valuesRefreshFlag = true;
        machine.move_cursor_x(1);
        break;

    case event::enter:
        valuesRefreshFlag = true;

        tft.println("hi");
        tft.println(val_map[0]);
        tft.println(val_map[1]);
        tft.println(val_map[2]);
        delay(1000);
        break;

    case event::nothing:
    default:
        break;
    }
}