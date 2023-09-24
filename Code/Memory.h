#ifndef _MEMORY_H_
#define _MEMORY_H_

#include <vector>

std::vector<short> Memory;
short dataBus;

void GetAddress(short Address) {
    dataBus = Memory.at(Address);
}

void SetAddress(short Address) {
    Memory.at(Address) = dataBus;
}

#endif