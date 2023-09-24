#ifndef _MEMORY_H_
#define _MEMORY_H_

#include <vector>

std::vector<short> Memory(65536);
std::vector<short> CharMemory(65536);
std::vector<short> ProgramMemory(65536);

// Resiter

short RegA;
short RegB;
short RegC;

short RegI;
short RegID;
short RegIE;

short RegF;
short RegG;

short RegSP;

// Busses

short dataBus;
short addressBus;

void GetAddress(short Address) {
    dataBus = Memory.at(Address);
}

void SetAddress(short Address) {
    Memory.at(Address) = dataBus;
}

#endif