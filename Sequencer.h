#pragma once
#include "LeakedObjectDetector.h"

struct Sequencer
{
    int clockInputVolts {4};
    int seqLength { 4 };
    bool inputGateIsHigh { true };
    int rangeSemitones { 0 };
    float rangeLengthInputVolts { 12.f };
    bool randomInputIsHigh { true };
    int maxSemitoneRange { 18 };
    int noteLengthMs { 500 };

    Sequencer();
    ~Sequencer();

    int modulateSeqLength(int seqControlValue, int modLenInputVal);
    int quantizeSequence(int scale, bool quantizeSwitchValue);
    void printMe();
    void extendRange(int rangeSemitones);
    void displayNoteRange();
    int getSequenceLengthInMs();
    void displaySequenceLengthInMs();

    JUCE_LEAK_DETECTOR(Sequencer)
};
