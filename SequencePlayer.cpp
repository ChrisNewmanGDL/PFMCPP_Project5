#include "SequencePlayer.h"

SequencePlayer::SequencePlayer()
{
    std::cout << "Hello from SequencePlayer struct, I am being constructed " << std::endl;
}

SequencePlayer::~SequencePlayer()
{
    std::cout << "Goodbye from SequencePlayer struct, I am being destructed " << std::endl;
}
//add 2 member functions
void SequencePlayer::displayOctaveAndRange()
{
    oscillator.displayOctave();
    sequencer.displayNoteRange();
}

void SequencePlayer::displayRootNote()
{
    std::cout << "Root note of sequence is " << oscillator.noteInHz << "hz" << std::endl;
}
