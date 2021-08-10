#include "Sequencer.h"

Sequencer::Sequencer()
{
    clockInputVolts = 4; seqLength = 4; inputGateIsHigh = true; rangeSemitones = 0; rangeLengthInputVolts = 12.f; randomInputIsHigh = true; maxSemitoneRange = 18; noteLengthMs = 500;
}

Sequencer::~Sequencer()
{
    std::cout << "Goodbye from Sequencer Destructor" << std::endl;
}

int Sequencer::getSequenceLengthInMs()
{
    return seqLength * noteLengthMs;
}


void Sequencer::displaySequenceLengthInMs()
{
    std::cout << "Sequencer's " << this->seqLength << " note sequence will take " << this->getSequenceLengthInMs() << " ms to play through to end" << std::endl;
}

int Sequencer::modulateSeqLength(int seqCtrlValue, int modLenInputVal)
{
    return seqCtrlValue + modLenInputVal;
}

void Sequencer::displayNoteRange()
{
    float range = rangeSemitones + rangeLengthInputVolts;
    std::cout << "Note range is " << range << " semitones" << std::endl;
}

int Sequencer::quantizeSequence(int scale, bool quantizeSwitchValue)
{
    return (quantizeSwitchValue ? scale : 0);
}

void Sequencer::printMe()
{
    seqLength = 4;
    std::cout << "Sequence length = " << seqLength << std::endl;
}

void Sequencer::extendRange(int sequenceRangeSemitones)
{
    std::cout << "Starting semitone range = " << sequenceRangeSemitones << std::endl;

    for (int i = 0; i <= maxSemitoneRange; ++i)
    {
        ++sequenceRangeSemitones;
        std::cout << "Semitone range is now " << sequenceRangeSemitones << std::endl;
    }

    std::cout << "Semitone range is now " << sequenceRangeSemitones << " - bit much" << std::endl;
}
