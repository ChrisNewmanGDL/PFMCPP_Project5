#include "Oscillator.h"

Oscillator::Oscillator()
{
    vOctInput = 1.f; defaultVoltage = 0.f; waveformControlPosition = 4; pulseWidthPercent = 50.f; modSocketVolts = 1.f; noteInHz = 440.f; audibleThresholdHz = 20000.f;
}

Oscillator::~Oscillator()
{
    std::cout << "Goodbye from Oscillator Destructor" << std::endl;
}
//.........................................................................................................................................................................................

float Oscillator::getOctave()
{
   return vOctInput + modSocketVolts;
}

void Oscillator::displayOctave()
{
    std::cout << "Oscillator's current Octave = " << this->getOctave() << " - Frequency = " << this->noteInHz << std::endl;
}

float Oscillator::modulateNote(float inputVolts, float modVolts)
{
    return inputVolts + modVolts;
}



void Oscillator::selectOscWaveform(int waveformCtrlPosition, int waveformModInputVal)
{
    int waveform = waveformCtrlPosition + waveformModInputVal;

    switch (waveform)
    {
    case 1:
        std::cout << "Sine";
        break;
    case 2:
        std::cout << "Triangle";
        break;
    case 3:
        std::cout << "Saw";
        break;
    case 4:
        std::cout << "Square";
        break;
    }
}

void Oscillator::ascendingNote(float thresholdHz)
{
    while (noteInHz < thresholdHz)
    {
        std::cout << noteInHz << "Hz" << " Note is theoretically within human range " << std::endl;
        noteInHz *= 2;
    }
    std::cout << "Out of range, but your dog should hear it" << std::endl;
}

void Oscillator::printMe()
{
    vOctInput = 2.58f;
    modSocketVolts = 2.167f;
    float combinedVolts = vOctInput + modSocketVolts;
    std::cout << "combinedVolts = " << combinedVolts << std::endl;
    std::cout << ((combinedVolts > 4) ? "Voltage is above max value of 4v" : " - ");
    std::cout << std::endl;
}
