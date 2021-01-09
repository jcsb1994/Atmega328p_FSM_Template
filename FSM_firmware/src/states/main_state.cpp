
#include "main.h"
#include "FSM/states.h"
#include "FSM/events.h"

int var_one = 1;
int var_two = 2;
int var_three = 3;

/* int *gen_val_map(int *map, unsigned int len, int target_widget_value, int inactive_widget_value)
{
    for (unsigned int i = 0; i < len; i++)
    {
        if (machine.get_target_widget() == i)
            map[i] = target_widget_value;
        else
            map[i] = inactive_widget_value;
    }
    return map;
}
 */
void main_state_handler()
{
    if (refreshFlag)
    {
        tft.setTextSize(2);
        tft.fillScreen(ST77XX_BLACK);
        tft.setCursor(0, 0);
        tft.setTextColor(ST77XX_WHITE, ST77XX_BLACK);
        tft.print("Values: ");

        refreshFlag = false;
        valuesRefreshFlag = true;
    }

    /*     for (unsigned int i = 0; i < (3); i++)
    {
        if (machine.get_target_widget() == i)
            val_map[i] = ST77XX_MAGENTA;
        else
            val_map[i] = ST77XX_WHITE;
        tft.setCursor(100, 80);
        tft.print(i);
    } */

    if (valuesRefreshFlag)
    {
        int widget_value_map[machine.get_widget_count()];
        int *val_map = widget_value_map;
        val_map = machine.pop_widget_val_map(val_map, machine.get_widget_count(), ST77XX_MAGENTA, ST77XX_WHITE);

        tft.setCursor(0, 80);
        tft.setTextColor(val_map[0], ST77XX_BLACK);
        tft.println(var_one);
        tft.setTextColor(val_map[1], ST77XX_BLACK);
        tft.println(var_two);
        tft.setTextColor(val_map[2], ST77XX_BLACK);
        tft.println(var_three);
        valuesRefreshFlag = false;
    }

    switch (machine.poll())
    {
        /*     case event::left:
        refreshFlag = true; */
    case event::up:
        valuesRefreshFlag = true;
        machine.move_cursor_y(-1);
/*         tft.setCursor(100, 100);
        tft.println(machine.get_target_widget());
        tft.println("up"); */
        //delay(5);
        //delay(500);

        break;

        /*     case event::right:
        refreshFlag = true; */
    case event::down:
        valuesRefreshFlag = true;
        machine.move_cursor_y(1);
        // tft.println(machine.get_target_widget());

        /*         delay(500); */
        break;

    case event::enter:
        valuesRefreshFlag = true;
        /* 
        tft.println("hi");
        tft.println(val_map[0]);
        tft.println(val_map[1]);
        tft.println(val_map[2]);
        delay(1000); */
        break;

    case event::nothing:
    default:
        break;
    }
}