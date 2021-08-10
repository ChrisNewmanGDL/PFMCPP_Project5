#pragma once
//#include <iostream>
#include "LeakedObjectDetector.h"
#include "Oscillator.h"
#include "Sequencer.h"

struct SequencePlayer
{
    Oscillator oscillator;
    Sequencer sequencer;
    
    SequencePlayer();
    ~SequencePlayer();

    void displayOctaveAndRange();
    void displayRootNote();

    JUCE_LEAK_DETECTOR(SequencePlayer)
};
