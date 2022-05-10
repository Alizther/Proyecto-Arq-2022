#include "ImmediateGenerator.h"

ImmediateGenerator::ImmediateGenerator(sc_module_name moduleName) : sc_module(moduleName) {
    SC_METHOD(generate);
    dont_initialize();
    sensitive << instructionIn;
}

ImmediateGenerator::~ImmediateGenerator() {}

void ImmediateGenerator::generate() {
    sc_uint<32> instruction = instructionIn.read();
    int control = controlIn.read().to_int();
    sc_int<32> immediateValue = 0;
    switch (control) {
        case 3:
        case 15:
        case 19:
        case 103:
        case 115: {
            // I Format
            for (int i = 0; i < 32; ++i) {
                if (i < 12) {
                    immediateValue[i] = instruction[i + 20];
                } else {
                    if (!immediateValue[i - 1]) {
                        break;
                    };
                    immediateValue[i] = immediateValue[i - 1];
                }
            }
            break;
        }
        case 23:
        case 55: {
            // U Format
            for (int i = 31; i >= 12; --i) {
                immediateValue[i] = instruction[i];
            }
            break;
        }
        case 35: {
            // S Format
            for (int i = 0; i < 32; ++i) {
                if (i >= 0 && i <= 4) {
                    immediateValue[i] = instruction[i + 7];
                } else if (i >= 5 && i <= 11) {
                    immediateValue[i] = instruction[i + 20];
                } else {
                    if (!immediateValue[i - 1]) {
                        break;
                    };
                    immediateValue[i] = immediateValue[i - 1];
                }
            }
            break;
        }
        case 51: {
            // R Format (no immediate value)
            break;
        }
        case 99: {
            // SB Format
            for (int i = 0; i < 32; ++i) {
                if (i == 0) {
                    continue;
                } else if (i >= 1 && i <= 4) {
                    immediateValue[i] = instruction[i + 7];
                } else if (i >= 5 && i <= 10) {
                    immediateValue[i] = instruction[i + 20];
                } else if (i == 11) {
                    immediateValue[i] = instruction[7];
                } else if (i == 12) {
                    immediateValue[i] = instruction[31];
                } else {
                    if (!immediateValue[i - 1]) {
                        break;
                    };
                    immediateValue[i] = immediateValue[i - 1];
                }
            }
            break;
        }
        case 111: {
            // UJ Format
            for (int i = 0; i < 32; ++i) {
                if (i == 0) {
                    continue;
                } else if (i >= 1 && i <= 10) {
                    immediateValue[i] = instruction[i + 20];
                } else if (i == 11) {
                    immediateValue[i] = instruction[20];
                } else if (i >= 12 && i <= 19) {
                    immediateValue[i] = instruction[i];
                } else if (i == 20) {
                    immediateValue[i] = instruction[31];
                } else {
                    if (!immediateValue[i - 1]) {
                        break;
                    };
                    immediateValue[i] = immediateValue[i - 1];
                }
            }
            break;
        }    
    }
    immediateValueOut.write(immediateValue);
}
