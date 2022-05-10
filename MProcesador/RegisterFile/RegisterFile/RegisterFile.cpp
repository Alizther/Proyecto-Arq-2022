#include "RegisterFile.h"

RegisterFile::RegisterFile(sc_module_name moduleName) : sc_module(moduleName) {
    SC_METHOD(write);
    dont_initialize();
    sensitive << clkIn.neg();
    
    SC_METHOD(read);
    dont_initialize();
    sensitive << clkIn;
}

RegisterFile::~RegisterFile() {}

void RegisterFile::write() {
    if (writeEnableIn.read()) {
        registers[addressWIn.read()] = wIn.read();
    }
}

void RegisterFile::read() {
    aOut.write(registers[addressAIn.read()]);
    bOut.write(registers[addressBIn.read()]);
}
