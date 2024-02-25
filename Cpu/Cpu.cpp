#include "Cpu.h"

#include <iostream>

void Cpu::printMemoryError() { std::cerr << "The CPU has no memory connected" << std::endl; }

unsigned char Cpu::getFlag(char flag) {
    switch (flag) {
        case 'N':
            return SR_ & (1 << 7);
        case 'V':
            return SR_ & (1 << 6);
        case 'B':
            return SR_ & (1 << 4);
        case 'D':
            return SR_ & (1 << 3);
        case 'I':
            return SR_ & (1 << 2);
        case 'Z':
            return SR_ & (1 << 1);
        case 'C':
            return SR_ & (1 << 0);
        default:
            return 0;
    }
}

void Cpu::setFlag(char flag, unsigned char bit) {
    bit = bit ? 1 : 0;
    switch (flag) {
        case 'N':
            SR_ &= ~(1 << 7);
            SR_ |= (bit << 7);
            break;
        case 'V':
            SR_ &= ~(1 << 6);
            SR_ |= (bit << 6);
            break;
        case 'B':
            SR_ &= ~(1 << 4);
            SR_ |= (bit << 4);
            break;
        case 'D':
            SR_ &= ~(1 << 3);
            SR_ |= (bit << 3);
            break;
        case 'I':
            SR_ &= ~(1 << 2);
            SR_ |= (bit << 2);
            break;
        case 'Z':
            SR_ &= ~(1 << 1);
            SR_ |= (bit << 1);
            break;
        case 'C':
            SR_ &= ~(1 << 0);
            SR_ |= (bit << 0);
            break;
    }
}

// Absolute addressing mode
unsigned short int Cpu::abs() {
    unsigned char low_byte = memory_->read(PC_++);
    unsigned char high_byte = memory_->read(PC_++);

    unsigned short int address = high_byte;
    address <<= 8;
    address |= low_byte;

    return address;
}

// Absolute, X-indexed addressing mode
unsigned short int Cpu::absX() {
    unsigned char low_byte = memory_->read(PC_++);
    unsigned char high_byte = memory_->read(PC_++);

    unsigned short int address = high_byte;
    address <<= 8;
    address |= low_byte;
    address += X_;

    return address;
}

// Absolute, Y-indexed addressing mode
unsigned short int Cpu::absY() {
    unsigned char low_byte = memory_->read(PC_++);
    unsigned char high_byte = memory_->read(PC_++);

    unsigned short int address = high_byte;
    address <<= 8;
    address |= low_byte;
    address += Y_;

    return address;
}

// Indirect addressing mode
unsigned short int Cpu::ind() {
    unsigned char low_byte = memory_->read(PC_++);
    unsigned char high_byte = memory_->read(PC_++);

    unsigned short int address = high_byte;
    address <<= 8;
    address |= low_byte;

    low_byte = memory_->read(address++);
    high_byte = memory_->read(address);

    address = high_byte;
    address <<= 8;
    address |= low_byte;

    return address;
}

// X-indexed, indirect addressing mode
unsigned short int Cpu::Xind() {
    unsigned char low_byte = memory_->read(PC_++);
    low_byte += X_;
    unsigned char high_byte = 0x00;

    unsigned short int address = high_byte;
    address <<= 8;
    address |= low_byte;

    low_byte = memory_->read(address++);
    high_byte = memory_->read(address);

    address = high_byte;
    address <<= 8;
    address |= low_byte;

    return address;
}

// Indirect, Y-indexed addressing mode
unsigned short int Cpu::indY() {
    unsigned char low_byte = memory_->read(PC_++);
    unsigned char high_byte = 0x00;

    unsigned short int address = high_byte;
    address <<= 8;
    address |= low_byte;

    low_byte = memory_->read(address++);
    high_byte = memory_->read(address);

    address = high_byte;
    address <<= 8;
    address |= low_byte;
    address += Y_;

    return address;
}

// Relative addressing mode
unsigned short int Cpu::rel() {
    unsigned char unsigned_offset = memory_->read(PC_++);
    char offset = static_cast<char>(unsigned_offset);

    unsigned short int address = PC_ + offset;

    return address;
}

// Zeropage addressing mode
unsigned short int Cpu::zpg() {
    unsigned char low_byte = memory_->read(PC_++);
    unsigned char high_byte = 0x00;

    unsigned short int address = high_byte;
    address <<= 8;
    address |= low_byte;

    return address;
}

// Zeropage, X-indexed addressing mode
unsigned short int Cpu::zpgX() {
    unsigned char low_byte = memory_->read(PC_++);
    low_byte += X_;
    unsigned char high_byte = 0x00;

    unsigned short int address = high_byte;
    address <<= 8;
    address |= low_byte;

    return address;
}

// class Cpu {
//    public:
//     Cpu();
//     void connectMemory(std::unique_ptr<Memory> memory);
//     std::unique_ptr<Memory> disconnectMemory();
//     void printPage(unsigned char page);
//     void printStatus();
//     void reset();
//     void step();
//     void run();
//
//    private:
//     unsigned short int zpgY();
//     void _00();
//     void _01();
//     void _05();
//     void _06();
//     void _08();
//     void _09();
//     void _0A();
//     void _0D();
//     void _0E();
//     void _10();
//     void _11();
//     void _15();
//     void _16();
//     void _18();
//     void _19();
//     void _1D();
//     void _1E();
//     void _20();
//     void _21();
//     void _24();
//     void _25();
//     void _26();
//     void _28();
//     void _29();
//     void _2A();
//     void _2C();
//     void _2D();
//     void _2E();
//     void _30();
//     void _31();
//     void _35();
//     void _36();
//     void _38();
//     void _39();
//     void _3D();
//     void _3E();
//     void _40();
//     void _41();
//     void _45();
//     void _46();
//     void _48();
//     void _49();
//     void _4A();
//     void _4C();
//     void _4D();
//     void _4E();
//     void _50();
//     void _51();
//     void _55();
//     void _56();
//     void _58();
//     void _59();
//     void _5D();
//     void _5E();
//     void _60();
//     void _61();
//     void _65();
//     void _66();
//     void _68();
//     void _69();
//     void _6A();
//     void _6C();
//     void _6D();
//     void _6E();
//     void _70();
//     void _71();
//     void _75();
//     void _76();
//     void _78();
//     void _79();
//     void _7D();
//     void _7E();
//     void _81();
//     void _84();
//     void _85();
//     void _86();
//     void _88();
//     void _8A();
//     void _8C();
//     void _8D();
//     void _8E();
//     void _90();
//     void _91();
//     void _94();
//     void _95();
//     void _96();
//     void _98();
//     void _99();
//     void _9A();
//     void _9D();
//     void _A0();
//     void _A1();
//     void _A2();
//     void _A4();
//     void _A5();
//     void _A6();
//     void _A8();
//     void _A9();
//     void _AA();
//     void _AC();
//     void _AD();
//     void _AE();
//     void _B0();
//     void _B1();
//     void _B4();
//     void _B5();
//     void _B6();
//     void _B8();
//     void _B9();
//     void _BA();
//     void _BC();
//     void _BD();
//     void _BE();
//     void _C0();
//     void _C1();
//     void _C4();
//     void _C5();
//     void _C6();
//     void _C8();
//     void _C9();
//     void _CA();
//     void _CC();
//     void _CD();
//     void _CE();
//     void _D0();
//     void _D1();
//     void _D5();
//     void _D6();
//     void _D8();
//     void _D9();
//     void _DD();
//     void _DE();
//     void _E0();
//     void _E1();
//     void _E4();
//     void _E5();
//     void _E6();
//     void _E8();
//     void _E9();
//     void _EA();
//     void _EC();
//     void _ED();
//     void _EE();
//     void _F0();
//     void _F1();
//     void _F5();
//     void _F6();
//     void _F8();
//     void _F9();
//     void _FD();
//     void _FE();
// };

// Cpu::Cpu() {
//     PC_ = 0x0000;
//     SP_ = 0x00;
//     AC_ = 0x00;
//     X_ = 0x00;
//     Y_ = 0x00;
//     SR_ = 0b00000000;
// }

// void Cpu::connectMemory(std::unique_ptr<Memory> memory) { memory_ = std::move(memory); }

// std::unique_ptr<Memory> Cpu::disconnectMemory() { return std::move(memory_); }

// void Cpu::printPage(unsigned char page) {
//     if (!memory_) {
//         printMemoryError();
//         return;
//     }
//     unsigned short int current_address = (page << 8);
//     unsigned char current_data;
//     for (unsigned char i = 0; i < 16; ++i) {
//         std::cout << std::format("0x{:0>4X}:", current_address);
//         for (unsigned char j = 0; j < 16; ++j) {
//             current_data = memory_->read(current_address);
//             std::cout << std::format("  0x{:0>2X}", current_data);
//             ++current_address;
//         }
//         std::cout << '\n';
//     }
// }

// void Cpu::printStatus() {
//     std::cout << std::format("A: 0x{:0>2X}, X: 0x{:0>2X}, Y: 0x{:0>2X}\n", AC_, X_, Y_);
//     std::cout << std::format("PC: 0x{:0>4X}, SP: 0x{:0>2X}\n", PC_, SP_);
//     std::cout << std::format("S(NV-BDIZC): {:0>8b}\n", SR_);
// }

// void Cpu::reset() {
//     if (!memory_) {
//         printMemoryError();
//         return;
//     }
//     unsigned char low_byte = memory_->read(0xFFFC);
//     unsigned char high_byte = memory_->read(0xFFFF);
//     PC_ = (high_byte << 8) | low_byte;
//     SP_ = 0xFF;
//     AC_ = 0x00;
//     X_ = 0x00;
//     Y_ = 0x00;
//     SR_ = 0b00100000;
// }

// void Cpu::step() {
//     if (!memory_) {
//         printMemoryError();
//         return;
//     }
// }
