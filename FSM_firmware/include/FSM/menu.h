//***********************************************************************************
// Copyright 2021 JCSB1994
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

//***********************************************************************************
//
// Description:
//    This file provides a menu interface for screens. 
//
//***********************************************************************************
//
// Widget map   : This menu i.f. lays the screen as a map made out of widgets in x and y coord
// Cursor       : The cursor is the x and y coord currently targeted
// Taget widget : Widget currently targeted by the cursor
// Edit widget  : When target widget is selected, becomes edit widget. user may edit/interact with it
//
//***********************************************************************************

#ifndef MENU_H
#define MENU_H

#include <Arduino.h>

#define X_COORD_INDEX (0)
#define Y_COORD_INDEX (1)
#define NOT_EDITING_WIDGET (-1)

#define WIDGET_CURSOR_MAP(x, max_x, y) (((max_x - 1) * x) + y) // Maps the current cursor pos to the map array

class menu
{
private:
    uint8_t cursor_pos[2] = {0, 0}; 

    uint8_t widget_map_size[2] = {0, 0};

    uint8_t target_widget;
    bool edit_widget;

    // called when cursor pos is changed or widget count is changed
    void enclose_cursor();
    void update_target_widget_from_cursor();

public:
    menu() {}
    ~menu() {}

    uint8_t get_x_widget_count() { return widget_map_size[X_COORD_INDEX]; }
    uint8_t get_y_widget_count() { return widget_map_size[Y_COORD_INDEX]; }
    uint8_t *get_cursor_pos() { return cursor_pos; }
    uint8_t get_active_widget() { return target_widget; }

    void enter_edit_widget() { edit_widget = true; }
    void quit_edit_widget() { edit_widget = false; } 
    bool is_edit_widget() { return edit_widget; }

    void move_cursor(bool dim, int8_t amount);

    void update_widget_map_size(uint8_t x_count, uint8_t y_count); // when changing state, resets active widget

    // color display menues
    /*     unsigned int get_widget_color(int8_t widget_map_index)
    {
        if (widget_map_index >= 0 && (widget_map_index < (widget_count[X_COORD_INDEX] * widget_count[Y_COORD_INDEX])))
            return widget_map[widget_map_index];
        else
            return 0;
    } */

    //unsigned int* set_widget_color_map(unsigned int inactive_col, unsigned int active_col);
};

#endif // MENU_H