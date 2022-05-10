#include "Testbench.h"
#include <iomanip>

Testbench::Testbench(sc_module_name mn) : sc_module(mn) {
  SC_THREAD(test);
  sensitive << clkIn.pos();
  dont_initialize();
}

void Testbench::print() {
  std::cout << instructionOut.read().to_string(SC_BIN, false) << " "
  << controlOut.read().to_string(SC_BIN, false) << " "
  << controlOut.read().to_string(SC_DEC, false) << " "
  << immediateValueIn.read().to_string(SC_BIN, false) << " "
  << immediateValueIn.read().to_string(SC_DEC, false) << " "
  << "\n";
}

void Testbench::test() {
  std::cout << " insOut                         .  control  ctrl  immed                          .  imm\n";
  //--------------------I Format------------------------------
  cout << "We are using I format" << endl;
  //                    0bus00000001111100000111000001111111
  instructionOut.write("0bus00000000000100000000001011110011");
                               controlOut.write("0bus1110011");
  wait(); print();
  
  //                    0bus00000001111100000111000001111111
  instructionOut.write("0bus01000000000000000000001010010011");
                               controlOut.write("0bus0010011");
  wait(); print();
  
  //                    0bus00000001111100000111000001111111
  instructionOut.write("0bus10000000000000000000001010000011");
                               controlOut.write("0bus0000011");
  wait(); print();

  //--------------------U Format------------------------------
  cout << "We are using U format" << endl;
  //                    0bus00000001111100000111000001111111
  instructionOut.write("0bus00000000000000000001001010010111");
                               controlOut.write("0bus0010111");
  wait(); print();
  
  //                    0bus00000001111100000111000001111111
  instructionOut.write("0bus10000000000000000000001010110111");
                               controlOut.write("0bus0110111");
  wait(); print();
  
  //--------------------S Format------------------------------
  cout << "We are using S format" << endl;
  //                    0bus00000001111100000111000001111111
  instructionOut.write("0bus00000000011000101000111110100011");
                               controlOut.write("0bus0100011");
  wait(); print();
  
  //                    0bus00000001111100000111000001111111
  instructionOut.write("0bus00000000011000101000000010100011");
                               controlOut.write("0bus0100011");
  wait(); print();
  
  //                    0bus00000001111100000111000001111111
  instructionOut.write("0bus00000000011000101000100000100011");
                               controlOut.write("0bus0100011");
  wait(); print();

  //                    0bus00000001111100000111000001111111
  instructionOut.write("0bus11111110011000101000000000100011");
                               controlOut.write("0bus0100011");
  wait(); print();

  //                    0bus00000001111100000111000001111111
  instructionOut.write("0bus00000010011000101000000000100011");
                               controlOut.write("0bus0100011");
  wait(); print();
  
  //                    0bus00000001111100000111000001111111
  instructionOut.write("0bus10000000011000101000000000100011");
                               controlOut.write("0bus0100011");
  wait(); print();

  //--------------------B Format------------------------------
  cout << "We are using B format" << endl;
  //                    0bus00000001111100000111000001111111
  instructionOut.write("0bus00000000011000101000111101100011");
                               controlOut.write("0bus1100011");
  wait(); print();

  //                    0bus00000001111100000111000001111111
  instructionOut.write("0bus01111110011000101000000001100011");
                               controlOut.write("0bus1100011");
  wait(); print();

  //                    0bus00000001111100000111000001111111
  instructionOut.write("0bus00000000011000101000000011100011");
                               controlOut.write("0bus1100011");
  wait(); print();

  //                    0bus00000001111100000111000001111111
  instructionOut.write("0bus10000000011000101000000001100011");
                               controlOut.write("0bus1100011");
  wait(); print();

  //--------------------J Format------------------------------
  cout << "We are using J format" << endl;
  //                    0bus00000001111100000111000001111111
  instructionOut.write("0bus01111111111000000000001011101111");
                               controlOut.write("0bus1101111");
  wait(); print();
  
  //                    0bus00000001111100000111000001111111
  instructionOut.write("0bus00000000000100000000001011101111");
                               controlOut.write("0bus1101111");
  wait(); print();
  
  //                    0bus00000001111100000111000001111111
  instructionOut.write("0bus00000000000011111111001011101111");
                               controlOut.write("0bus1101111");
  wait(); print();
  
  //                    0bus00000001111100000111000001111111
  instructionOut.write("0bus10000000000000000000001011101111");
                               controlOut.write("0bus1101111");
  wait(); print();
  sc_stop();
}
