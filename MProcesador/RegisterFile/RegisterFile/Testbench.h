#ifndef TESTBENCH_H
#define TESTBENCH_H

#include <systemc.h>


class Testbench : public sc_module {
public:
  sc_in_clk clkIn;
  sc_out<bool> writeEnableOut;
  sc_out<sc_uint<32>> wOut;
  sc_out<sc_uint<5>> addressAOut, addressBOut, addressWOut;
  sc_in<sc_uint<32>> aIn, bIn;

  SC_CTOR(Testbench);

private:
  void print();
  void test();
};

#endif
