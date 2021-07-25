/*
Project 5: Part 2 / 4
 video: Chapter 3 Part 1

Create a branch named Part2

 The 'this' keyword

 The purpose of this project part is to show you how accessing member variables of objects INSIDE member functions is very similar to accessing member variables of objects OUTSIDE of member functions, via 'this->' and via the '.' operator.
 This project part will break the D.R.Y. rule, but that is fine for the purpose of this project part.


 1) if you don't have any std::cout statements in main() that access member variables of your U.D.Ts
         write some.
    You can copy some from your Project3's main() if needed.

 2) For each std::cout statement in main() that accessed member variables of your types or printed out the results of your member function calls,
        a) write a member function that prints the same thing out, but uses the proper techniques inside the member functions to access the same member variables/functions.
        b) be explicit with your use of 'this->' in those member functions so we see how you're accessing/calling those member variables and functions *inside*
        c) call that member function after your std::cout statement in main.
        d) you should see 2 (almost) identical messages in the program output for each member function you add:
            one for the std::cout line, and one for the member function's output


 3) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 */

 /*
  example:
  */
#include <iostream>

namespace Example
{
    //a User-Defined Type
    struct MyFoo
    {
        MyFoo() { std::cout << "creating MyFoo" << std::endl; }
        ~MyFoo() { std::cout << "destroying MyFoo" << std::endl; }

        // 2a) the member function whose function body is almost identical to the std::cout statement in main.
        void memberFunc()
        {
            // 2b) explicitly using 'this' inside this member function.
            std::cout << "MyFoo returnValue(): " << this->returnValue() << " and MyFoo memberVariable: " << this->memberVariable << std::endl;
        }

        int returnValue() { return 3; }
        float memberVariable = 3.14f;

        /*
        note: the example functions are implemented in-class, and the ctor/dtor show the curly braces on the same line as the function declaration.
        Do not do this.  Follow the instructions and coding style for the course.
        */
    };

    int main()
    {
        //an instance of the User-Defined Type named mf
        MyFoo mf;

        // 1) a std::cout statement that uses mf's member variables
        std::cout << "mf returnValue(): " << mf.returnValue() << " and mf memberVariable: " << mf.memberVariable << std::endl;

        // 2c) calling mf's member function.  the member function's body is almost identical to the cout statement above.
        mf.memberFunc();
        return 0;
    }
}



/*
 copied UDT 1:
 */

//#include <iostream>

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


};

Sequencer::Sequencer()
{
    clockInputVolts = 4; seqLength = 4; inputGateIsHigh = true; rangeSemitones = 0; rangeLengthInputVolts = 12.f; randomInputIsHigh = true; maxSemitoneRange = 18; noteLengthMs = 500;
}

Sequencer::~Sequencer()
{
    std::cout << "Goodbye from Sequencer Destructor" << std::endl;
}
//...........................................................................................................................................................................
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
//...........................................................................................................................................................................

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
    std::string getArpMode();
    void displayArpMode();
};

Arpeggiator::Arpeggiator()
{
    arpInputVolts = 0.f; chordType = " Major9 "; arpModeControlValue = 2; arpMode = " "; isHigh = true; clockInputVolts = 0.f; voltageThreshold = 10.f;
}

Arpeggiator::~Arpeggiator()
{
    std::cout << "Goodbye from Arpeggiator Destructor" << std::endl;
}
//...............................................................................................................................................................
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
       std::cout << "Melody generator arp mode = " << arpeggiator.getArpMode() << std::endl;
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
    std::cout << "Root note of sequence is " << oscillator.noteInHz << "hz" << std::endl;
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

    // this keyword....................................................................................................
    std::cout << "Basal oscillator's current Octave = " << basalOscillator.getOctave() << " - Frequency = " << basalOscillator.noteInHz << std::endl;
    basalOscillator.displayOctave();
    basalOscillator.ascendingNote(20000.f);

    Sequencer mySequencer;
    mySequencer.printMe();
    Sequencer seq3Sequencer;
    seq3Sequencer.extendRange(16);
    // this keyword....................................................................................................
    std::cout << "seq3's " << seq3Sequencer.seqLength << " note sequence will take " << seq3Sequencer.seqLength * seq3Sequencer.noteLengthMs << " ms to play through to end" << std::endl;
    seq3Sequencer.displaySequenceLengthInMs();

    Arpeggiator myArpeggiator;
    myArpeggiator.printMe();
    int chordVal = myArpeggiator.modulateChordType(0, 1);
    Arpeggiator simpleArpeggiator;
    //................................................................................................................
    std::cout << "simpleArpeggiator mode = " << simpleArpeggiator.getArpMode() << std::endl;
    simpleArpeggiator.displayArpMode();


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

    MelodyGenerator melodyGenerator2;
    simpleArpeggiator.arpModeControlValue = 1;
    melodyGenerator2.displayArpStatus();
    melodyGenerator2.getSeqNoteRange();

    SequencePlayer sequencePlayer2;
    sequencePlayer2.displayOctaveAndRange();
    sequencePlayer2.displayRootNote();

    std::cout << "good to go!" << std::endl;
}
