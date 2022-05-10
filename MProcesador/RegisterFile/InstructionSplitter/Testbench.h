#ifndef TESTBENCH_H
#define TESTBENCH_H

#include <systemc.h>


class Testbench : public sc_module {
public:
  sc_in_clk clkIn;

  sc_out<sc_uint<32>> instructionOut;
  sc_in<sc_uint<32>> instructionIn;
  sc_in<sc_uint<7>> controlIn;
  sc_in<sc_uint<5>> addressReadAIn, addressReadBIn, addressWriteIn;
  sc_in<sc_uint<4>> functIn;

  SC_CTOR(Testbench);

private:
  void print();
  void test();
};

#endif
