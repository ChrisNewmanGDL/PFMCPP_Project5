#pragma once
#include <iostream>
#include "LeakedObjectDetector.h"

struct Arpeggiator
{
    float arpInputVolts;
    std::string chordType;
    int arpModeControlValue;
    std::string arpMode;
    bool isHigh;
    float clockInputVolts;
    float voltageThreshold;

    Arpeggiator();
    ~Arpeggiator();

    int modulateChordType(int chordControlValue, int chordModulationInputVal);
    int modulateOctave(int octControlValue, int octModulationInputVal);
    void printMe();
    void showMaxVOctWarning();
    std::string getArpMode();
    void displayArpMode();

    JUCE_LEAK_DETECTOR(Arpeggiator)
};
