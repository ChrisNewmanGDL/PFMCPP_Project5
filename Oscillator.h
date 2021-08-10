#pragma once
#include <iostream>
#include "LeakedObjectDetector.h"


struct Oscillator
{
    float vOctInput;
    float defaultVoltage;
    int waveformControlPosition;
    float pulseWidthPercent;
    float modSocketVolts;
    float noteInHz;
    float audibleThresholdHz;

    Oscillator();
    ~Oscillator();

    float modulateNote(float inputSocketVolts, float modSocketVolts);
    void selectOscWaveform(int waveformControlPosition, int waveformModInputValue);
    void printMe();
    void ascendingNote(float audibleThresholdHz);
    float getOctave();
    void displayOctave();

    JUCE_LEAK_DETECTOR(Oscillator)
};
