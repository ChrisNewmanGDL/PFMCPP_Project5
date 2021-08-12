#pragma once
#include "LeakedObjectDetector.h"

struct Oscillator
{
    float vOctInput { 1.f };
    float defaultVoltage { 0.f };
    int waveformControlPosition { 4 };
    float pulseWidthPercent { 50.f };
    float modSocketVolts { 1.f };
    float noteInHz { 440.f };
    float audibleThresholdHz { 20000.f };

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
