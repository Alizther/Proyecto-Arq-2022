#ifndef TESTBENCH_H
#define TESTBENCH_H
#include <systemc.h>
#include <iostream>

class testbench : public sc_module
{

    public:
    sc_in_clk clk;
    sc_in <sc_uint <32>> instr_in;
    sc_out<sc_uint <5>> instr_out;

    SC_CTOR(testbench)
    {
        SC_THREAD(test);
            sensitive<< clk.neg();
            dont_initialize();
    }

    private:

    void print();
    void test();

};



#endif
