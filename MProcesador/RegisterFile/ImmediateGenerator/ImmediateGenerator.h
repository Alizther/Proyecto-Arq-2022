#ifndef IMMEDIATE_GENERATOR_H
#define IMMEDIATE_GENERATOR_H

#include <systemc.h>

class ImmediateGenerator : public sc_module {
    public:
        sc_in<sc_uint<32>> instructionIn;
        sc_in<sc_uint<7>> controlIn;
        sc_out<sc_int<32>> immediateValueOut;

        SC_CTOR(ImmediateGenerator);
        ~ImmediateGenerator();
    
    private:
        void generate();
};

#endif