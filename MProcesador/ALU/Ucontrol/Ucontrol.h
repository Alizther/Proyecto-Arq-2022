#include <iostream>
#include <systemc.h>

class UC : public sc_module{

    public: 
        sc_in<sc_uint<32>> aIn;//Instrucction 0-6
        sc_out<sc_uint<32>>  ALUOp;//Out
        sc_out<bool> RegWrite, ALUsrc, MemWrite, MemtoReg, MemRead, Branch;
        
        SC_CTOR(UC);
        ~UC();

    private:

        void process();



};