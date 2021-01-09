

#include "FSM/menu.h"

void menu::update_target_widget_from_cursor()
{
    target_widget = ((widget_map_size[Y_COORD_INDEX]) * cursor_pos[X_COORD_INDEX]) + cursor_pos[Y_COORD_INDEX];
}

void menu::enclose_cursor()
{
    if (cursor_pos[X_COORD_INDEX] > (widget_map_size[X_COORD_INDEX] - 1))
    {
        cursor_pos[X_COORD_INDEX] = 0;
    }
    if (cursor_pos[Y_COORD_INDEX] > (widget_map_size[Y_COORD_INDEX] - 1))
    {
        cursor_pos[Y_COORD_INDEX] = 0;
    }
}

void menu::move_cursor(bool dim, int8_t amount)
{
    cursor_pos[dim] += amount;
    enclose_cursor();
    update_target_widget_from_cursor();
}


void menu::update_widget_map_size(uint8_t x_dimension, uint8_t y_dimension)
{
    widget_map_size[X_COORD_INDEX] = x_dimension;
    widget_map_size[Y_COORD_INDEX] = y_dimension;

    target_widget = 0;
    quit_edit_widget(); // leave editing mode, safeguard code
}

//---------------------------------------------

/* unsigned int* menu::set_widget_color_map(unsigned int inactive_col, unsigned int active_col)
{
    // create array
    unsigned int color_map[widget_count[X_COORD_INDEX] * widget_count[Y_COORD_INDEX]];

    // populate with inactive colors
    for (uint8_t i = 0; i < sizeof(color_map) / sizeof(color_map[0]); i++)
        color_map[i] = inactive_col;

    // set active col to active widget
    color_map[active_widget] = active_col;

    // copy to widget_map
    memmove(widget_map, color_map, sizeof(color_map));
    widget_map = color_map;

    return color_map;
} */