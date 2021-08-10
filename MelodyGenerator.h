#pragma once
//#include <iostream>
#include "LeakedObjectDetector.h"
#include "Sequencer.h"
#include "Arpeggiator.h"

struct MelodyGenerator
{
    Sequencer sequencer;
    Arpeggiator arpeggiator;
    int  arpModeControlValue = arpeggiator.arpModeControlValue;
    
    MelodyGenerator();
    ~MelodyGenerator();

    void displayArpStatus();
    void getSeqNoteRange();

    JUCE_LEAK_DETECTOR(MelodyGenerator)
};
