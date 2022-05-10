#include "ImmediateGenerator.h"
#include "Testbench.h"


int sc_main(int argv, char* argc[]) {
  sc_time period(10,SC_NS);
  sc_time delay(0, SC_NS);

  sc_clock clock("clock", period, 0.5, delay, true);

  ImmediateGenerator immediateGenerator("immediateGenerator");
  Testbench tb("tb");

  sc_signal<sc_uint<32>> instructionSg;
  sc_signal<sc_uint<7>> controlSg;
  sc_signal<sc_int<32>> immediateSg;

  immediateGenerator.instructionIn(instructionSg);
  immediateGenerator.controlIn(controlSg);
  immediateGenerator.immediateValueOut(immediateSg);

  tb.instructionOut(instructionSg);
  tb.controlOut(controlSg);
  tb.immediateValueIn(immediateSg);

  tb.clkIn(clock);
  
  sc_start();

  return 0;
}
