#ifndef TESTBENCH_H
#define TESTBENCH_H

#include <iostream>

#include <systemc.h>


class Testbench : public sc_module {
public:
  /**
   * Como todo testbench, deberá recibir como entrada: el reloj y
   * los datos de salida del módulo a testear.
   * Y la salida será los datos de entrada del módulo a testear.
  */
	sc_in<bool> clkIn;
  sc_in<sc_int<32>> fIn;
	sc_out<sc_int<32>> d0Out, d1Out;
  sc_out<bool> s0Out;
	SC_CTOR(Testbench);

private:
	void print();
	void test();
};

#endif