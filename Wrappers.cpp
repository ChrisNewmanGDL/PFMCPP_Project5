#include "Wrappers.h"
#include "Oscillator.h"
#include "Sequencer.h"
#include "Arpeggiator.h"
#include "MelodyGenerator.h"
#include "SequencePlayer.h"



OscillatorWrapper::OscillatorWrapper( Oscillator* ptr) :
    pointerToOscillator( ptr )
{
}
OscillatorWrapper::~OscillatorWrapper()
{
    delete pointerToOscillator;
}
    
SequencerWrapper::SequencerWrapper( Sequencer* ptr) :
    pointerToSequencer( ptr )
{
}

SequencerWrapper::~SequencerWrapper()
{
    delete pointerToSequencer;
}

ArpeggiatorWrapper::ArpeggiatorWrapper( Arpeggiator* ptr) :
    pointerToArpeggiator( ptr )
{
}
ArpeggiatorWrapper::~ArpeggiatorWrapper()
{
    delete pointerToArpeggiator;
}

MelodyGeneratorWrapper::MelodyGeneratorWrapper( MelodyGenerator* ptr) :
    pointerToMelodyGenerator( ptr )
{
}
MelodyGeneratorWrapper::~MelodyGeneratorWrapper()
{
    delete pointerToMelodyGenerator;
}

SequencePlayerWrapper::SequencePlayerWrapper( SequencePlayer* ptr) :
    pointerToSequencePlayer( ptr )
{
}
SequencePlayerWrapper::~SequencePlayerWrapper()
{
    delete pointerToSequencePlayer;
}
