/*
Project 5: Part 1 / 4
 video Chapter 2 - Part 12

 Create a branch named Part1

Purpose:  This project continues developing Project3.
       you will learn how to take code from existing projects and migrate only what you need to new projects
       you will learn how to write code that doesn't leak as well as how to refactor.

 Destructors

 0) move all of your implementations of all functions to OUTSIDE of the class.

 1) Copy 3 of your user-defined types (the ones with constructors and for()/while() loops from Project 3) here
 2) add destructors
        make the destructors do something like print out the name of the class.

 3) add 2 new UDTs that use only the types you copied above as member variables.

 4) add 2 member functions that use your member variables to each of these new UDTs

 5) Add constructors and destructors to these 2 new types that do stuff.
        maybe print out the name of the class being destructed, or call a member function of one of the members.  be creative

 6) copy over your main() from the end of Project3 and get it to compile with the types you copied over.
        remove any code in main() that uses types you didn't copy over.

 7) Instantiate your 2 UDT's from step 4) in the main() function at the bottom.
       call their member functions.

 8) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.

 */

/* 
 copied UDT 1:
 */

#include <iostream>

struct Oscillator
{
    float vOctInput;
    float defaultVoltage;
    int waveformControlPosition;
    float pulseWidthPercent;
    int octave;
    float modSocketVolts;
    float noteInHz;
    float audibleThresholdHz;
    
    Oscillator();
    ~Oscillator();

    float modulateNote(float inputSocketVolts, float modSocketVolts);
    void selectOscWaveform(int waveformControlPosition, int waveformModInputValue);
    void printMe();
    void ascendingNote(float audibleThresholdHz);
    void displayOctave();
};

Oscillator::Oscillator() 
{  
    vOctInput = 0.5f; defaultVoltage = 0.f; waveformControlPosition = 4; pulseWidthPercent = 50.f; octave = (0); modSocketVolts = 0.f; noteInHz = 440.f; audibleThresholdHz = 20000.f; 
} 

Oscillator::~Oscillator() 
    {
        std::cout << "Goodbye from Oscillator Destructor" << std::endl;
    }

float Oscillator::modulateNote(float inputVolts, float modVolts)
{
    return inputVolts + modVolts;
}

void Oscillator::selectOscWaveform(int waveformCtrlPosition, int waveformModInputVal)
{
    int waveform = waveformCtrlPosition + waveformModInputVal;

    switch(waveform)
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
    while(noteInHz < thresholdHz)
    {
        std::cout << noteInHz <<  "Hz" << " Note is theoretically within human range " << std::endl;
        noteInHz *= 2;
    }
    std::cout << "Out of range, but your dog should hear it" << std::endl;

}

void Oscillator::printMe()
{
    vOctInput = 2.58f;
    modSocketVolts = 2.167f;
    float combinedVolts =  vOctInput + modSocketVolts;
    std::cout << "combinedVolts = " << combinedVolts << std::endl;
    std::cout << ((combinedVolts > 4) ?  "Voltage is above max value of 4v" : " - ");
    std::cout << std::endl;
}

void Oscillator::displayOctave()
{
    std::cout  << "Current Octave = " << vOctInput + modSocketVolts << std::endl;
}
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
    
    Sequencer();
    ~Sequencer();

    int modulateSeqLength(int seqControlValue, int modLenInputVal);
    int quantizeSequence(int scale, bool quantizeSwitchValue);
    void printMe();
    void displayNoteRange();
    void extendRange(int rangeSemitones);
};

Sequencer::Sequencer()
{
    clockInputVolts = 4; seqLength = 4; inputGateIsHigh = true; rangeSemitones = 0; rangeLengthInputVolts =12.f; randomInputIsHigh = true; maxSemitoneRange = 18;
}

Sequencer::~Sequencer()
{
    std::cout << "Goodbye from Sequencer Destructor" << std::endl;
}

void Sequencer::displayNoteRange()
{
    float range = rangeSemitones + rangeLengthInputVolts;
    std::cout << "Note range is " << range << " semitones" << std::endl;
}

int Sequencer::modulateSeqLength(int seqCtrlValue, int modLenInputVal)
{
    return seqCtrlValue + modLenInputVal;
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

    for(int i = 0; i <= maxSemitoneRange; ++i)
    {
        ++sequenceRangeSemitones;
        std::cout << "Semitone range is now " << sequenceRangeSemitones << std::endl;
    }

    std::cout << "Semitone range is now " << sequenceRangeSemitones << " - bit much" <<std::endl;

}
/*
 copied UDT 3:
 */
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
    void modulateArpMode();
    void displayInputVolts();
};

Arpeggiator::Arpeggiator()
{
    arpInputVolts= 0.f; chordType = " Major9 "; arpModeControlValue =2; arpMode = " "; isHigh = true; clockInputVolts = 0.f; voltageThreshold = 10.f;
}

Arpeggiator::~Arpeggiator()
{
    std::cout << "Goodbye from Arpeggiator Destructor" << std::endl;
}

void Arpeggiator::modulateArpMode()
{
    std::cout << "Arpeggiator mode = " << ((arpModeControlValue = 1) ? "Up " : "Down") << std::endl;
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
    while(arpInputVolts < voltageThreshold)
    {
        std::cout <<  "Arpeggiator input voltage is within range " << std::endl;
        arpInputVolts += 2;
    }
    std::cout << "Arpeggiator input voltage out of range" << std::endl;
 }
/*
 new UDT 4:
 with 2 member functions
 */
struct MelodyGenerator
{
// types above used as member variables
    Sequencer sequencer;
    Arpeggiator arpeggiator;

    MelodyGenerator();
    ~MelodyGenerator();

    void displayArpStatus();
    void getSeqNoteRange();
};

MelodyGenerator::MelodyGenerator()
{
    std::cout << "Hello from MelodyGenerator struct, I am being constructed" << std::endl;
    arpeggiator.arpModeControlValue = 0;
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
    arpeggiator.modulateArpMode(); //call a member function of Arpeggiator
}

void MelodyGenerator::getSeqNoteRange()
{
    sequencer.displayNoteRange();
}
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
    std::cout  << "Root note of sequence is " << oscillator.noteInHz << "hz" << std::endl;
}


 /*MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].

 If you didn't already:
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */


//#include <iostream>


int main()
{
    Oscillator newOscillator;
    newOscillator.printMe();
    Oscillator basalOscillator;
    basalOscillator.displayOctave();
    basalOscillator.ascendingNote(20000.f);

    Sequencer mySequencer;
    mySequencer.printMe();
    Sequencer seq3Sequencer;
    seq3Sequencer.displayNoteRange();
    seq3Sequencer.extendRange(16);

    Arpeggiator myArpeggiator;
    myArpeggiator.printMe();
    int chordVal = myArpeggiator.modulateChordType(0, 1);
    Arpeggiator simpleArpeggiator;
    simpleArpeggiator.modulateArpMode();

    simpleArpeggiator.showMaxVOctWarning();

    switch(chordVal)
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

    MelodyGenerator melodyGenerator2;
    melodyGenerator2.displayArpStatus();
    melodyGenerator2.getSeqNoteRange();

    SequencePlayer sequencePlayer2;
    sequencePlayer2.displayOctaveAndRange();
    sequencePlayer2.displayRootNote();

    std::cout << "good to go!" << std::endl;
}
