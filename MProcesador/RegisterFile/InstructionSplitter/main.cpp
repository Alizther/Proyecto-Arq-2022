#include "InstructionSplitter.h"
#include "Testbench.h"


int sc_main(int argv, char* argc[]) {
  sc_time period(10,SC_NS);
  sc_time delay(0, SC_NS);

  sc_clock clock("clock", period, 0.5, delay, true);

  InstructionSplitter instructionSplitter("instructionSplitter");
  Testbench tb("tb");

  sc_signal<sc_uint<7>> controlSg;
  sc_signal<sc_uint<5>> addressASg, addressBSg, addressWSg;
  sc_signal<sc_uint<4>> functSg;
  sc_signal<sc_uint<32>> instructionASg, instructionBSg;

  instructionSplitter.instructionIn(instructionASg);
  instructionSplitter.controlOut(controlSg);
  instructionSplitter.addressReadAOut(addressASg);
  instructionSplitter.addressReadBOut(addressBSg);
  instructionSplitter.instructionOut(instructionBSg);
  instructionSplitter.functOut(functSg);
  instructionSplitter.addressWriteOut(addressWSg);
  
  tb.instructionOut(instructionASg);
  tb.controlIn(controlSg);
  tb.addressReadAIn(addressASg);
  tb.addressReadBIn(addressBSg);
  tb.instructionIn(instructionBSg);
  tb.functIn(functSg);
  tb.addressWriteIn(addressWSg);

  tb.clkIn(clock);

  // sc_uint<4> ui4 = "0b1001";
  // sc_int<4> i4 = ui4.to_int();
  // sc_int<32> i32 = i4;
  // cout << i32.to_string(SC_BIN) << endl;
  sc_start();

  return 0;
}
