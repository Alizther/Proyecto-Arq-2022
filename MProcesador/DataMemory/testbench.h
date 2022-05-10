#ifndef TESTBENCH_H
#define TESTBENCH_H
#include <systemc.h>
#include <iostream>

class testbench : public sc_module
{
    public:
    sc_in_clk clk;
    sc_out<sc_uint<32>> data_out;
    sc_out<bool> write_enable_out;
    sc_out<sc_uint<5>> dir_out;
    sc_in<sc_uint<32>> data_in;

    SC_CTOR(testbench);
    
    private:
    void test();
    void print();

};


#endif