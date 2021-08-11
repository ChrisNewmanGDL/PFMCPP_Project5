#pragma once
#include "LeakedObjectDetector.h"

struct Arpeggiator
{
    float arpInputVolts  { 0.f };
    std::string chordType  { " Major9 " };
    int arpModeControlValue  { 2 };
    std::string arpMode  { " " };
    bool isHigh  { true };
    float clockInputVolts  { 0.f };
    float voltageThreshold  { 10.f };

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
