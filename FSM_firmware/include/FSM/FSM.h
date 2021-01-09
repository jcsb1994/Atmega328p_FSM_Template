#ifndef FSM_H
#define FSM_H

#include "FSM/UI.h"

class FSM
{
private:
    /* data */
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

    void move_cursor_x(int8_t amount)
    {
        myUI.Menu.move_cursor(X_COORD_INDEX, amount);
    }

    void move_cursor_y(int8_t amount)
    {
        myUI.Menu.move_cursor(Y_COORD_INDEX, amount);
    }

    void update_widget_map_size(uint8_t x_count, uint8_t y_count)
    {
        myUI.Menu.update_widget_map_size(x_count, y_count);
    }
};

#endif