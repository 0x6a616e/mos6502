#ifndef MEMORY_H_
#define MEMORY_H_

#include <array>

class Memory {
   public:
    Memory();
    unsigned char read(unsigned short int address);
    void write(unsigned short int address, unsigned char data);

   private:
    std::array<unsigned char, 1 << 16> memory_;
};

#endif  // !MEMORY_H_
