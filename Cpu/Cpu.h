#ifndef CPU_H_
#define CPU_H_

#include <map>
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
    void step();
    void run();

   private:
    std::unique_ptr<Memory> memory_;
    unsigned short int PC_;
    unsigned char SP_;
    unsigned char AC_;
    unsigned char X_;
    unsigned char Y_;
    unsigned char SR_;  // NV-BDIZC
    std::map<unsigned char, void (*)()> operationMapper_;
    void printMemoryError();
    unsigned char getFlag(char flag);
    void setFlag(char flag, unsigned char bit);
    void stackPush(unsigned char data);
    unsigned char stackPop();
    unsigned short int abs();
    unsigned short int absX();
    unsigned short int absY();
    unsigned short int ind();
    unsigned short int Xind();
    unsigned short int indY();
    unsigned short int rel();
    unsigned short int zpg();
    unsigned short int zpgX();
    unsigned short int zpgY();
    void opc00();
    void opc01();
    void opc05();
    void opc06();
    void opc08();
    void opc09();
    void opc0A();
    void opc0D();
    void opc0E();
    void opc10();
    void opc11();
    void opc15();
    void opc16();
    void opc18();
    void opc19();
    void opc1D();
    void opc1E();
    void opc20();
    void opc21();
    void opc24();
    void opc25();
    void opc26();
    void opc28();
    void opc29();
    void opc2A();
    void opc2C();
    void opc2D();
    void opc2E();
    void opc30();
    void opc31();
    void opc35();
    void opc36();
    void opc38();
    void opc39();
    void opc3D();
    void opc3E();
    void opc40();
    void opc41();
    void opc45();
    void opc46();
    void opc48();
    void opc49();
    void opc4A();
    void opc4C();
    void opc4D();
    void opc4E();
    void opc50();
    void opc51();
    void opc55();
    void opc56();
    void opc58();
    void opc59();
    void opc5D();
    void opc5E();
    void opc60();
    void opc61();
    void opc65();
    void opc66();
    void opc68();
    void opc69();
    void opc6A();
    void opc6C();
    void opc6D();
    void opc6E();
    void opc70();
    void opc71();
    void opc75();
    void opc76();
    void opc78();
    void opc79();
    void opc7D();
    void opc7E();
    void opc81();
    void opc84();
    void opc85();
    void opc86();
    void opc88();
    void opc8A();
    void opc8C();
    void opc8D();
    void opc8E();
    void opc90();
    void opc91();
    void opc94();
    void opc95();
    void opc96();
    void opc98();
    void opc99();
    void opc9A();
    void opc9D();
    void opcA0();
    void opcA1();
    void opcA2();
    void opcA4();
    void opcA5();
    void opcA6();
    void opcA8();
    void opcA9();
    void opcAA();
    void opcAC();
    void opcAD();
    void opcAE();
    void opcB0();
    void opcB1();
    void opcB4();
    void opcB5();
    void opcB6();
    void opcB8();
    void opcB9();
    void opcBA();
    void opcBC();
    void opcBD();
    void opcBE();
    void opcC0();
    void opcC1();
    void opcC4();
    void opcC5();
    void opcC6();
    void opcC8();
    void opcC9();
    void opcCA();
    void opcCC();
    void opcCD();
    void opcCE();
    void opcD0();
    void opcD1();
    void opcD5();
    void opcD6();
    void opcD8();
    void opcD9();
    void opcDD();
    void opcDE();
    void opcE0();
    void opcE1();
    void opcE4();
    void opcE5();
    void opcE6();
    void opcE8();
    void opcE9();
    void opcEA();
    void opcEC();
    void opcED();
    void opcEE();
    void opcF0();
    void opcF1();
    void opcF5();
    void opcF6();
    void opcF8();
    void opcF9();
    void opcFD();
    void opcFE();
};

#endif  // !CPU_H_
