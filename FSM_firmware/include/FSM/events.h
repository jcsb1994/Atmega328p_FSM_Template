#ifndef EVENTS_H
#define EVENTS_H

enum events
{
    nothing, // Value 0 when no events are incoming
    increment,
    decrement,
    saveToEEPROM,
    tare,
    switchReadingMode,
    switchMenuPage
};

#endif // EVENTS_H