//***********************************************************************************
// Copyright 2021 jcsb1994
// Written by jcsb1994
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
//***********************************************************************************
//
// Description:
//    This file provides a finite state machine class for managing embedded device
//    firmware.
//
//***********************************************************************************
//
// FSM:
//    A state handler is called each time the FSM steps with handle_state().
//
//***********************************************************************************

#ifndef FSM_H
#define FSM_H

#include "FSM/UI.h"

class FSM
{
private:
    UI myUI;
    event incoming_event;
    void (*state_handler)();
    event extract_incoming_event();

public:
    FSM(void initial_state(void));
    ~FSM();

    event poll();

    void handle_state();
    void set_state(void state(void)) { state_handler = state; }

    uint8_t get_widget_count() { return myUI.Menu.get_widget_nb(); }
    uint8_t get_x_widget_count() { return myUI.Menu.get_widget_x_nb(); }
    uint8_t get_y_widget_count() { return myUI.Menu.get_widget_y_nb(); }
    uint8_t *get_cursor_pos() { return myUI.Menu.get_cursor_pos(); }
    uint8_t *get_widget_map_dimensions() { return myUI.Menu.get_widget_map_dimensions(); }
    uint8_t get_target_widget() { return myUI.Menu.get_target_widget(); }

    void enter_edit_widget() { myUI.Menu.enter_edit_widget(); }
    void quit_edit_widget() { myUI.Menu.quit_edit_widget(); }
    bool is_edit_widget() { return myUI.Menu.is_edit_widget(); }

    int *pop_widget_val_map(int *map, unsigned int len, int inactive_widget_value, int target_widget_value, int edit_widget_value)
    {
        return myUI.Menu.pop_widget_val_map(map, len, inactive_widget_value, target_widget_value, edit_widget_value);
    }

    void move_cursor_x(int8_t amount)
    {
        myUI.Menu.move_cursor(X_COORD_INDEX, amount);
    }

    void move_cursor_y(int amount)
    {
        myUI.Menu.move_cursor(Y_COORD_INDEX, amount);
        delay(5);   // weird not working with neg vals if no delay
    }

    void update_widget_map_size(uint8_t x_count, uint8_t y_count)
    {
        myUI.Menu.update_widget_map_size(x_count, y_count);
    }
};

#endif