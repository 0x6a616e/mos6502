#include "Memory.h"

Memory::Memory() { memory_.fill(0x00); }

unsigned char Memory::read(unsigned short int address) { return memory_[address]; }

void Memory::write(unsigned short int address, unsigned char data) { memory_[address] = data; }
