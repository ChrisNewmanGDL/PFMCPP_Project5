/*
 Project 5: Part 4 / 4
 video: Chapter 3 Part 7

 Create a branch named Part4
 
 Don't #include what you don't use
 
 1) Your task is to refactor your Chapter 3 Part 4 task into separate source and header files.
         Add files via the pane on the left.
 
 2) Put all of your declarations for each class in .h files
         One header file per class ( i.e. Raider.h for a class named "Raider" )
 
 3) Put all of your implementations in .cpp files.
         one cpp file per class ( i.e. Raider.cpp for a class named "Raider" )
 
 4) Put all of your Wrapper classes in a single Wrappers.h file
         if you implemented your wrapper class functions in-class, you'll need to move them to Wrappers.cpp
 
 5) NO IN-CLASS IMPLEMENTATION ALLOWED.
         the only exception is the existing Atomic.h and LeakedObjectDetector.h
 
 6) for every .cpp file you have to make, insert it into the .replit file after 'main.cpp'.  Don't forget the spaces between file names.
 If you need help with this step, send me a DM.
 
 7) click the [run] button.  Clear up any errors or warnings as best you can.
 
 Remember, your Chapter 3 Part 4 task worked when it was all in one file. so you shouldn't need to edit any of it.  
         just split it up into source files and provide the appropriate #include directives.
 */



#include <iostream>
#include "LeakedObjectDetector.h"
#include "Oscillator.h"
#include "Sequencer.h"
#include "Arpeggiator.h"
#include "MelodyGenerator.h"
#include "SequencePlayer.h"
#include "Wrappers.h"


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
    std::cout << "simpleArpeggiator mode = " << myArpeggiator.pointerToArpeggiator->getArpMode() << std::endl; //THIS SHOULD BE SIMPLE ARPEGGIATOR
    myArpeggiator.pointerToArpeggiator->displayArpMode();

    MelodyGeneratorWrapper arpeggiator( new MelodyGenerator() );
    arpeggiator.pointerToMelodyGenerator->displayArpStatus();
    arpeggiator.pointerToMelodyGenerator->getSeqNoteRange();

    SequencePlayerWrapper sequencePlayer2( new SequencePlayer() );
    sequencePlayer2.pointerToSequencePlayer->displayOctaveAndRange();
    sequencePlayer2.pointerToSequencePlayer->displayRootNote();

    std::cout << "good to go!" << std::endl;
}
