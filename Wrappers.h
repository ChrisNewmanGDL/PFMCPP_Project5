#pragma once

//forward declarations

struct Oscillator;
struct Sequencer;
struct Arpeggiator;
struct MelodyGenerator;
struct SequencePlayer;

struct OscillatorWrapper
{
    OscillatorWrapper( Oscillator* ptr );
    ~OscillatorWrapper();
    
    Oscillator* pointerToOscillator = nullptr;
};

struct SequencerWrapper
{
    SequencerWrapper( Sequencer* ptr );
    ~SequencerWrapper();
    
    Sequencer* pointerToSequencer = nullptr;
};

struct ArpeggiatorWrapper
{
    ArpeggiatorWrapper( Arpeggiator* ptr ); 
    ~ArpeggiatorWrapper();

    Arpeggiator* pointerToArpeggiator = nullptr; 
};

struct MelodyGeneratorWrapper
{
    MelodyGeneratorWrapper( MelodyGenerator* ptr ); 
    ~MelodyGeneratorWrapper();
    
    MelodyGenerator* pointerToMelodyGenerator = nullptr; 
};

struct SequencePlayerWrapper
{
    SequencePlayerWrapper( SequencePlayer* ptr );  
    ~SequencePlayerWrapper();
    
    SequencePlayer* pointerToSequencePlayer = nullptr; 
};
