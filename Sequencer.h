#pragma once
#include <iostream>
#include "LeakedObjectDetector.h"

struct Sequencer
{
    int clockInputVolts;
    int seqLength;
    bool inputGateIsHigh;
    int rangeSemitones;
    float rangeLengthInputVolts;
    bool randomInputIsHigh;
    int maxSemitoneRange;
    int noteLengthMs;

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
