#ifndef TESTBENCH_H
#define TESTBENCH_H

#include <iostream>
#include <systemc.h>


class TB : public sc_module {
public:
  /**
   * Como todo testbench, deberá recibir como entrada: el reloj y
   * los datos de salida del módulo a testear.
   * Y la salida será los datos de entrada del módulo a testear.
  */
	sc_in<bool> clkIn, RW, src, MW, MtoR, MR, Bh;
  sc_in<sc_uint<32>> AO;//ALuOP mas de 1 instruccions
  sc_out<sc_uint<32>> aOut;

	SC_CTOR(TB);
    ~TB();
    
private:
	void print();
	void test();
};

#endif