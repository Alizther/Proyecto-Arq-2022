#include "Testbench.h"
#include <iomanip>

Testbench::Testbench(sc_module_name mn) : sc_module(mn) {
  SC_THREAD(test);
  sensitive << clkIn.pos();
  dont_initialize();
}

void Testbench::print() {
  std::cout << instructionOut.read().to_string(SC_BIN, false) << " "
  << controlIn.read().to_string(SC_BIN, false) << " "
  << addressReadAIn.read().to_string(SC_BIN, false) << " "
  << addressReadBIn.read().to_string(SC_BIN, false) << " "
  << functIn.read().to_string(SC_BIN, false) << " "
  << addressWriteIn.read().to_string(SC_BIN, false) << " "
  << instructionIn.read().to_string(SC_BIN, false) << " "
  << "\n";
}

void Testbench::test() {
  std::cout << " insOut                         .  control  adrsA  adrsB  func  adrsW  insIn                          .\n";
//instructionOut.write("0bus00000001111100000111000001111111");
  instructionOut.write("0bus00000000000011111000000000000000");
  wait();
  print();
//instructionOut.write("0bus00000001111100000111000001111111");
  instructionOut.write("0bus00000001111100000000000000000000");
  wait();
  print();
//instructionOut.write("0bus00000001111100000111000001111111");
  instructionOut.write("0bus00000000000000000111000000000000");
  wait();
  print();
//instructionOut.write("0bus00000001111100000111000001111111");
  instructionOut.write("0bus01000000000000000111000000000000");
  wait();
  print();
//instructionOut.write("0bus00000001111100000111000001111111");
  instructionOut.write("0bus01000000000000000000000000000000");
  wait();
  print();
//instructionOut.write("0bus00000001111100000111000001111111");
  instructionOut.write("0bus00000000000000000000111110000000");
  wait();
  print();
//instructionOut.write("0bus00000001111100000111000001111111");
  instructionOut.write("0bus00000000000000000000000001111111");
  wait();
  print();
  sc_stop();
}
