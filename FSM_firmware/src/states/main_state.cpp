
#include "main.h"
#include "FSM/states.h"
#include "FSM/events.h"

enum class main_state_widgets
{
    edit1,
    edit2,
    edit3,
    edit4,
    edit5,
    edit6,
};



enum class main_state_editable_widgets
{
    edit1,
    edit2,
    edit3,
    edit4,
    edit5,
    edit6,
};

int var_one = 1;
int var_two = 2;
int var_three = 3;
int vartwo_one = 4;
int vartwo_two = 5;
int vartwo_three = 6;

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

    if (valuesRefreshFlag)
    {
        int widget_value_map[machine.get_widget_count()];
        int *val_map = widget_value_map;
        val_map = machine.pop_widget_val_map(val_map, machine.get_widget_count(),  ST77XX_WHITE, ST77XX_MAGENTA, ST77XX_GREEN);

        tft.setCursor(0, 80);   
        tft.setTextColor(val_map[0], ST77XX_BLACK);
        tft.println(var_one);
        tft.setTextColor(val_map[1], ST77XX_BLACK);
        tft.println(var_two);
        tft.setTextColor(val_map[2], ST77XX_BLACK);
        tft.println(var_three);

        tft.setCursor(60, 80);
        tft.setTextColor(val_map[3], ST77XX_BLACK);
        tft.print(vartwo_one);
        tft.setCursor(60, 100);
        tft.setTextColor(val_map[4], ST77XX_BLACK);
        tft.print(vartwo_two);
        tft.setCursor(60, 120);
        tft.setTextColor(val_map[5], ST77XX_BLACK);
        tft.print(vartwo_three);

        valuesRefreshFlag = false;
    }

    switch (machine.poll())
    {
        /*     case event::left:
        refreshFlag = true; */
    case event::up:
        valuesRefreshFlag = true;

        if (machine.is_editing_widget())
            switch (machine.get_target_widget())
            {
            case (int)main_state_editable_widgets::edit1:
                var_one++;
                break;

            default:
                break;
            }
        else
            machine.move_cursor_y(-1);
        break;

    case event::right:
        valuesRefreshFlag = true;
        machine.move_cursor_x(1);
        break;

    case event::left:
        valuesRefreshFlag = true;
        machine.move_cursor_x(-1);
        break;
        /*     case event::right:
        refreshFlag = true; */
    case event::down:
        valuesRefreshFlag = true;
        
        if (machine.is_editing_widget())
        {
        }

        else
            machine.move_cursor_y(1);
        break;

    case event::enter:
        valuesRefreshFlag = true;

        switch (machine.get_target_widget())
        {
        case (int)main_state_widgets::edit1:
        case (int)main_state_widgets::edit2:
        case (int)main_state_widgets::edit3:
        case (int)main_state_widgets::edit4:
        case (int)main_state_widgets::edit5:
        case (int)main_state_widgets::edit6:

            if (machine.is_editing_widget())
                machine.quit_edit_widget();
            else
                machine.enter_edit_widget();
            break;

        default:
            break;
        }

        break;

    case event::nothing:
    default:
        break;
    }
}