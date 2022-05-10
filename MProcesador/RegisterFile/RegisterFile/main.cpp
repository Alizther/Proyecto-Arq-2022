#include "RegisterFile.h"
#include "Testbench.h"


int sc_main(int argv, char* argc[]) {
  sc_time period(10,SC_NS);
  sc_time delay(0, SC_NS);

  sc_clock clock("clock", period, 0.5, delay, true);

  RegisterFile registerFile("registerFile");
  Testbench tb("tb");

  sc_signal<sc_uint<5>> addressASg, addressBSg, addressWSg;
  sc_signal<sc_uint<32>> aSg, bSg, wSg;
  sc_signal<bool> writeEnableSg;

  registerFile.addressAIn(addressASg);
  registerFile.addressBIn(addressBSg);
  registerFile.addressWIn(addressWSg);
  registerFile.writeEnableIn(writeEnableSg);
  registerFile.aOut(aSg);
  registerFile.bOut(bSg);
  registerFile.wIn(wSg);
  
  tb.addressAOut(addressASg);
  tb.addressBOut(addressBSg);
  tb.addressWOut(addressWSg);
  tb.writeEnableOut(writeEnableSg);
  tb.aIn(aSg);
  tb.bIn(bSg);
  tb.wOut(wSg);

  registerFile.clkIn(clock);
  tb.clkIn(clock);

  sc_start();

  return 0;
}
