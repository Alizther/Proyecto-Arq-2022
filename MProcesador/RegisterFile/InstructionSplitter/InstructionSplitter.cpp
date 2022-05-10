#include "InstructionSplitter.h"

InstructionSplitter::InstructionSplitter(sc_module_name moduleName) : sc_module(moduleName) {
    SC_METHOD(split);
    dont_initialize();
    sensitive << instructionIn;
}

InstructionSplitter::~InstructionSplitter() {}

void InstructionSplitter::split() {
    controlOut.write(instructionIn.read().range(6, 0));
    addressReadAOut.write(instructionIn.read().range(19, 15));
    addressReadBOut.write(instructionIn.read().range(24, 20));
    instructionOut.write(instructionIn.read());
    sc_uint<4> tempFunc = instructionIn.read().range(14, 12);
    tempFunc[3] = instructionIn.read()[30];
    functOut.write(tempFunc);
    addressWriteOut.write(instructionIn.read().range(11, 7));
}
