#ifndef REGISTER_FILE_H
#define REGISTER_FILE_H

#include <systemc.h>

class RegisterFile : public sc_module {
    public:
        sc_in_clk clkIn;
        sc_in<sc_uint<5>> addressAIn;
        sc_in<sc_uint<5>> addressBIn;
        sc_in<sc_uint<5>> addressWIn;
        sc_in<sc_uint<32>> wIn;
        sc_in<bool> writeEnableIn;
        sc_out<sc_uint<32>> aOut;
        sc_out<sc_uint<32>> bOut;

        SC_CTOR(RegisterFile);
        ~RegisterFile();
    
    private:
        sc_uint<32> registers[32];
        void read();
        void write();
};

#endif