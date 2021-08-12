
#include "MelodyGenerator.h"

MelodyGenerator::MelodyGenerator()
{
    std::cout << "Hello from MelodyGenerator struct, I am being constructed" << std::endl;
    std::cout << "MG arpmodevalue = " << arpModeControlValue << std::endl;    
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
