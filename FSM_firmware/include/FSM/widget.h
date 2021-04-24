#ifndef WIDGET_H
#define WIDGET_H

class widget
{
private:
    int *value;
    bool isEditable;
    unsigned int incrementSize;
    void (*activationFct)();

public:
  /**********************************************************************/
  /*!
    @brief  Ctor for non modifiable widgets, that trigger an action when pressed
    @param  activation_function function to run when widget is pressed
  */
  /**********************************************************************/
    widget(void (* activation_function)()) {isEditable = false; }
  /**********************************************************************/
  /*!
    @brief  Ctor for modifiable widgets, that contain a value that can be inc/decremented
    @param  displayedValue variable to link to the widget
    @param  incrementAmount Numeric amount by which the displayed value is changed when edited
  */
  /**********************************************************************/
    widget(int *displayedValue, unsigned int incrementAmount) : value(displayedValue), incrementSize(incrementAmount)  {isEditable = true; }
    ~widget() {}
    bool is_editable() { return isEditable; }
    void activate() { activationFct(); }
    void increment() { value += incrementSize; }
    void decrement() { value -= incrementSize; }
};

#endif