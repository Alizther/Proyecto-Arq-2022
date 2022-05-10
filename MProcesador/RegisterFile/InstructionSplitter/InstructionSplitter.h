#ifndef INSTRUCTION_SPLITTER_H
#define INSTRUCTION_SPLITTER_H

#include <systemc.h>

class InstructionSplitter : public sc_module {
    public:
        sc_in<sc_uint<32>> instructionIn;
        sc_out<sc_uint<7>> controlOut;
        sc_out<sc_uint<5>> addressReadAOut;
        sc_out<sc_uint<5>> addressReadBOut;
        sc_out<sc_uint<32>> instructionOut;
        sc_out<sc_uint<4>> functOut;
        sc_out<sc_uint<5>> addressWriteOut;

        SC_CTOR(InstructionSplitter);
        ~InstructionSplitter();
    
    private:
        void split();
};

#endif