#include <iostream>
#include "Arpeggiator.h"
Arpeggiator::Arpeggiator()
{
    
}

Arpeggiator::~Arpeggiator()
{
    std::cout << "Goodbye from Arpeggiator Destructor" << std::endl;
}

std::string Arpeggiator::getArpMode()
{
    arpMode =  (arpModeControlValue == 1) ? "Up " : "Down";
    return arpMode;
}

void Arpeggiator::displayArpMode()
{
    std::cout << "Arpeggiator mode = " << this->getArpMode() << " - Arp mode control value = " << this->arpModeControlValue << std::endl;
}

int Arpeggiator::modulateChordType(int chordCtrlValue, int chordModInputVal)
{
    int chordIdentifier = chordCtrlValue + chordModInputVal;
    return chordIdentifier;
}

int Arpeggiator::modulateOctave(int octCtrlValue, int octModInputVal)
{
    return octCtrlValue + octModInputVal;
}

void Arpeggiator::printMe()
{
    std::cout << "chord = " << chordType << std::endl;
}

void Arpeggiator::showMaxVOctWarning()
{
    while (arpInputVolts < voltageThreshold)
    {
        std::cout << "Arpeggiator input voltage is  within  range " << std::endl;
        arpInputVolts += 2;
    }
    std::cout << "Arpeggiator input voltage out of range" << std::endl;
}
