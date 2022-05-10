#ifndef TESTBENCH_H
#define TESTBENCH_H

#include <systemc.h>


class Testbench : public sc_module {
public:
  sc_in_clk clkIn;

  sc_out<sc_uint<32>> instructionOut;
  sc_out<sc_uint<7>> controlOut;
  sc_in<sc_int<32>> immediateValueIn;

  SC_CTOR(Testbench);

private:
  void print();
  void test();
};

#endif
