#include <memory>

#include "Cpu.h"
#include "Memory.h"

int main() {
    std::unique_ptr<Memory> memory = std::make_unique<Memory>();

    Cpu cpu;
    cpu.connectMemory(std::move(memory));
    cpu.reset();

    return 0;
}
