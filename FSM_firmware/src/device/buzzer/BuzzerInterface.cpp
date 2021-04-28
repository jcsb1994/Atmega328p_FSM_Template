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
//    This file contains a high level interface for buzzer 
//
//***********************************************************************************

#include "device/buzzer/BuzzerInterface.h"

void BuzzerInterface::_reset() { 
        _state = S_BUZZER_IDLE;
        _Melody = NULL;
        _currNote = 0;
        noTone(_pin);
}

void BuzzerInterface::step() {
    switch (_state) {
    case S_BUZZER_IDLE:
        if (_Melody != NULL) {
            _state = S_BUZZER_ACTIVE;
        }
        break;
    case S_BUZZER_ACTIVE:

        if(_currNote >= _Melody->nbNotes) {
            _reset();
            
        } else { 
            uint16_t sound = _Melody->frequency[_currNote];                                                                                                                                                     
            tone(_pin, sound);
            _state = S_BUZZER_PLAYING;
        }
        break;
    case S_BUZZER_PLAYING:
    if ((++_stepCount * _stepPeriod) >= _Melody->duration[_currNote]) {
            noTone(_pin);
            _stepCount = 0;
            _state = S_BUZZER_ACTIVE;
            _currNote++;
    }
        break;
    default:
        break;
    }
}
