/*
 Project 5: Part 3 / 4
 video: Chapter 3 Part 4:

Create a branch named Part3

 the 'new' keyword

 1) add #include "LeakedObjectDetector.h" to main

 2) Add 'JUCE_LEAK_DETECTOR(OwnerClass)' at the end of your UDTs.

 3) write the name of your class where it says "OwnerClass"

 4) write wrapper classes for each type similar to how it was shown in the video

 5) update main()
      replace your objects with your wrapper classes, which have your UDTs as pointer member variables.

    This means if you had something like the following in your main() previously:
*/
#if false
 Axe axe;
 std::cout << "axe sharpness: " << axe.sharpness << "\n";
 #endif
 /*
    you would update that to use your wrappers:

 */

#if false
AxeWrapper axWrapper( new Axe() );
std::cout << "axe sharpness: " << axWrapper.axPtr->sharpness << "\n";
#endif
/*
notice that the object name has changed from 'axe' to 'axWrapper'
You don't have to do this, you can keep your current object name and just change its type to your Wrapper class

 8) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.

 see here for an example: https://repl.it/@matkatmusic/ch3p04example

 you can safely ignore any warnings about exit-time-destructors.
 if you would like to suppress them, add -Wno-exit-time-destructors to the .replit file
   with the other warning suppression flags
 */




/*
 copied UDT 1:
 */

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

struct OscillatorWrapper
{
    OscillatorWrapper( Oscillator* ptr ) : pointerToOscillator( ptr ) { }
    ~OscillatorWrapper()
    {
        delete pointerToOscillator;
    }

    Oscillator* pointerToOscillator = nullptr;
};

/*
 copied UDT 2:
 */
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

struct SequencerWrapper
{
    SequencerWrapper( Sequencer* ptr ) : pointerToSequencer( ptr ) { } 
    ~SequencerWrapper()
    {
        delete pointerToSequencer;
    }

    Sequencer* pointerToSequencer = nullptr; //initialising member variable pointerToSequencer as nullptr
};

// /*
//  copied UDT 3:
//  */
struct Arpeggiator
{
    float arpInputVolts;
    std::string chordType;
    int arpModeControlValue;
    std::string arpMode;
    bool isHigh;
    float clockInputVolts;
    float voltageThreshold;

    Arpeggiator();
    ~Arpeggiator();

    int modulateChordType(int chordControlValue, int chordModulationInputVal);
    int modulateOctave(int octControlValue, int octModulationInputVal);
    void printMe();
    void showMaxVOctWarning();
    std::string getArpMode();
    void displayArpMode();

    JUCE_LEAK_DETECTOR(Arpeggiator)
};

Arpeggiator::Arpeggiator()
{
    arpInputVolts = 0.f; chordType = " Major9 "; arpModeControlValue = 2; arpMode = " "; isHigh = true; clockInputVolts = 0.f; voltageThreshold = 10.f;
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

struct ArpeggiatorWrapper
{
    ArpeggiatorWrapper( Arpeggiator* ptr ) : pointerToArpeggiator( ptr ) { } 
    ~ArpeggiatorWrapper()
    {
        delete pointerToArpeggiator;
    }

    Arpeggiator* pointerToArpeggiator = nullptr; //initialising member variable pointerToArpeggiator as nullptr
};
/*
 new UDT 4:
 with 2 member functions
 */
struct MelodyGenerator
{
    // types above used as member variables
    Sequencer sequencer;
    Arpeggiator arpeggiator;
    int  arpModeControlValue = arpeggiator.arpModeControlValue;
    
    MelodyGenerator();
    ~MelodyGenerator();

    void displayArpStatus();
    void getSeqNoteRange();

    JUCE_LEAK_DETECTOR(MelodyGenerator)
};

MelodyGenerator::MelodyGenerator()
{
    std::cout << "Hello from MelodyGenerator struct, I am being constructed" << std::endl;
    std::cout << "MG arpmodevalue = " << arpModeControlValue << std::endl;    arpeggiator.arpModeControlValue = 0;
}

MelodyGenerator::~MelodyGenerator()
{
    arpeggiator.arpModeControlValue = 0;
    std::cout << "Arp mode reset to default value of " << arpeggiator.arpModeControlValue << std::endl;
    std::cout << "Goodbye from MelodyGenerator struct, I am being destructed" << std::endl;
}
// add 2 member functions that use member variables
void MelodyGenerator::displayArpStatus()
{
       std::cout << "Melody generator arp mode = " << arpeggiator.getArpMode() << std::endl;
}

void MelodyGenerator::getSeqNoteRange()
{
    sequencer.displayNoteRange();
}

struct MelodyGeneratorWrapper
{
    MelodyGeneratorWrapper( MelodyGenerator* ptr ) : pointerToMelodyGenerator( ptr ) { } 
    ~MelodyGeneratorWrapper()
    {
        delete pointerToMelodyGenerator;
    }

    MelodyGenerator* pointerToMelodyGenerator = nullptr; 
};
/*
 new UDT 5:
 with 2 member functions
 */
struct SequencePlayer
{
    Oscillator oscillator;
    Sequencer sequencer;

    SequencePlayer();
    ~SequencePlayer();

    void displayOctaveAndRange();
    void displayRootNote();

    JUCE_LEAK_DETECTOR(SequencePlayer)
};

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

struct SequencePlayerWrapper
{
    SequencePlayerWrapper( SequencePlayer* ptr ) : pointerToSequencePlayer( ptr ) { } 
    ~SequencePlayerWrapper()
    {
        delete pointerToSequencePlayer;
    }

    SequencePlayer* pointerToSequencePlayer = nullptr; 
};


/*MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].

If you didn't already:
   Make a pull request after you make your first commit
   pin the pull request link and this repl.it link to our DM thread in a single message.

send me a DM to review your pull request when the project is ready for review.

Wait for my code review.
*/


int main()
{
    OscillatorWrapper firstOscillator( new Oscillator() );// unpack  this syntax
    firstOscillator.pointerToOscillator->printMe();
    OscillatorWrapper basalOscillator( new Oscillator() );

    std::cout << "Basal oscillator's current Octave = " << basalOscillator.pointerToOscillator->getOctave() << " - Frequency = " << basalOscillator.pointerToOscillator->noteInHz << std::endl;
    basalOscillator.pointerToOscillator->displayOctave();
    basalOscillator.pointerToOscillator->ascendingNote(20000.f);

    SequencerWrapper mySequencer( new Sequencer() );
    mySequencer.pointerToSequencer->printMe(); 
    SequencerWrapper seq3Sequencer( new Sequencer() );
    seq3Sequencer.pointerToSequencer->extendRange(16);

    std::cout << "seq3's " << seq3Sequencer.pointerToSequencer->seqLength << " note sequence will take " << seq3Sequencer.pointerToSequencer->seqLength * seq3Sequencer.pointerToSequencer->noteLengthMs << " ms to play through to end" << std::endl;
    seq3Sequencer.pointerToSequencer->displaySequenceLengthInMs();

    ArpeggiatorWrapper myArpeggiator( new Arpeggiator() );
    myArpeggiator.pointerToArpeggiator->printMe();
    int chordVal = myArpeggiator.pointerToArpeggiator->modulateChordType(0, 1);
    switch (chordVal)
    {
    case 1:
        std::cout << "Chord is major7" << std::endl;
        break;
    case 2:
        std::cout << "Chord is minor7" << std::endl;
        break;
    case 3:
        std::cout << "Chord is Major9" << std::endl;
        break;
    case 4:
        std::cout << "etc" << std::endl;
        break;
    }
    
    ArpeggiatorWrapper simpleArpeggiator( new Arpeggiator() );
    std::cout << "simpleArpeggiator mode = " << myArpeggiator.pointerToArpeggiator->getArpMode() << std::endl;
    myArpeggiator.pointerToArpeggiator->displayArpMode();

    MelodyGeneratorWrapper arpeggiator( new MelodyGenerator() );
    arpeggiator.pointerToMelodyGenerator->displayArpStatus();
    arpeggiator.pointerToMelodyGenerator->getSeqNoteRange();

    SequencePlayerWrapper sequencePlayer2( new SequencePlayer() );
    sequencePlayer2.pointerToSequencePlayer->displayOctaveAndRange();
    sequencePlayer2.pointerToSequencePlayer->displayRootNote();

    std::cout << "good to go!" << std::endl;
}
