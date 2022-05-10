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
	sc_in<bool> clkIn, zeroIn;
  sc_in<sc_int<32>> cIn;
	sc_out<sc_int<32>> aOut, bOut;
  sc_out<sc_uint<32>> scOut;


	SC_CTOR(TB);
    ~TB();
    
private:
	void print();
	void test();
};

#endif