#ifndef CPU_H_
#define CPU_H_

#include <memory>

#include "Memory.h"

class Cpu {
   public:
    Cpu();
    void connectMemory(std::unique_ptr<Memory> memory);
    std::unique_ptr<Memory> disconnectMemory();
    void printPage(unsigned char page);
    void printStatus();
    void reset();
    void tick();
    void run();

   private:
    std::unique_ptr<Memory> memory_;
    unsigned short int program_counter_;
    unsigned char stack_pointer_;
    unsigned char accumulator_;
    unsigned char x_;
    unsigned char y_;
    unsigned char processor_status_;  // NV-BDIZC
    void printMemoryError();
};

#endif  // !CPU_H_
