#ifndef MEMORY_IF_H
#define MEMORY_IF_H

#include <Arduino.h>
#include <EEPROM.h>

#define NB_SAVE_VALUES (5)
#define VALUES_TYPE_SIZE (sizeof(float))

class memory_interface
{
private:
    uint8_t _currentSaveIndex;            // Which of the address is currently targeted
    uint8_t _saveAddress[NB_SAVE_VALUES]; // EEPROM addresses to save into
    float _savedValue[NB_SAVE_VALUES];    // Torque values stored in the eeprom addresses

    bool deleteFlag = false;

    void generateSaveAddresses();

public:
    memory_interface()
    {
        generateSaveAddresses();
        populateSavedValues();
    }
    ~memory_interface() {}

    uint8_t getTargetAddress()  { return _saveAddress[_currentSaveIndex]; }
    float getTargetValue() { return _savedValue[_currentSaveIndex]; }
    float getValue(uint8_t val_idx) { return _savedValue[val_idx]; }

    void populateSavedValues(); // Puts all eeprom values into the _savedValue array

    // Which slot is targeted if save or delete is pressed 
    uint8_t getCurrentIndex() { return _currentSaveIndex; }
    void decrementCurrentIndex();
    void incrementCurrentIndex();

    bool isDeleteFlagged() { return deleteFlag; }
    void setDeleteFlag(bool is_pressed) { deleteFlag = is_pressed; }
    void saveToCurrentIndex(float val);
};

#endif // MEMORY_IF_H