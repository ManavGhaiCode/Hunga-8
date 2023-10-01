#ifndef _MEMORY_H_
#define _MEMORY_H_

#include <vector>

std::vector<short> Memory(65536);
std::vector<short> CharMemory(65536);
std::vector<short> ProgramMemory(196608);

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

#endif