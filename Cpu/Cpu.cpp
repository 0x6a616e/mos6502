#include "Cpu.h"

#include <format>
#include <iostream>
#include <memory>

#include "Memory.h"

Cpu::Cpu() {
    program_counter_ = 0x0000;
    stack_pointer_ = 0x00;
    accumulator_ = 0x00;
    x_ = 0x00;
    y_ = 0x00;
    processor_status_ = 0b00000000;
}

void Cpu::connectMemory(std::unique_ptr<Memory> memory) { memory_ = std::move(memory); }

std::unique_ptr<Memory> Cpu::disconnectMemory() { return std::move(memory_); }

void Cpu::printPage(unsigned char page) {
    if (!memory_) {
        printMemoryError();
        return;
    }
    unsigned short int current_address = (page << 8);
    unsigned short int current_data;
    for (unsigned char i = 0; i < 16; ++i) {
        std::cout << std::format("0x{:0>4X}:", current_address);
        for (unsigned char j = 0; j < 16; ++j) {
            current_data = static_cast<unsigned short int>(memory_->read(current_address));
            std::cout << std::format("  0x{:0>2X}", current_data);
            ++current_address;
        }
        std::cout << '\n';
    }
}

void Cpu::printStatus() {
    std::cout << std::format("A: 0x{:0>2X}, X: 0x{:0>2X}, Y: 0x{:0>2X}\n", accumulator_, x_, y_);
    std::cout << std::format("PC: 0x{:0>4X}, SP: 0x{:0>2X}\n", program_counter_, stack_pointer_);
    std::cout << std::format("S(NV-BDIZC): {:0>8b}\n", processor_status_);
}

void Cpu::printMemoryError() { std::cerr << "The CPU has no memory connected" << std::endl; }

void Cpu::reset() {
    if (!memory_) {
        printMemoryError();
        return;
    }
    unsigned char low_byte = memory_->read(0xFFFC);
    unsigned char high_byte = memory_->read(0xFFFF);
    program_counter_ = (high_byte << 8) | low_byte;
    stack_pointer_ = 0xFF;
    accumulator_ = 0x00;
    x_ = 0x00;
    y_ = 0x00;
    processor_status_ = 0b00100000;
}

void Cpu::tick() {
    if (!memory_) {
        printMemoryError();
        return;
    }
}

// class Cpu {
//    public:
//     void tick();
//     void run();
//
//    private:
//     std::unique_ptr<Memory> memory_;
//     unsigned short int program_counter_;
//     unsigned char stack_counter_;
//     unsigned char accumulator_;
//     unsigned char x_;
//     unsigned char y_;
//     unsigned char processor_status_;  // NV-BDIZC
// };
