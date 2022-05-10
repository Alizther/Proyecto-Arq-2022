#include "Testbench.h"
#include <iomanip>

Testbench::Testbench(sc_module_name mn) : sc_module(mn) {
  SC_THREAD(test);
  sensitive << clkIn;
  dont_initialize();
}

void Testbench::print() {
  std::cout << std::setw(6) << sc_time_stamp();
  std::cout << std::setw(4) << "";
  std::cout << std::setw(4) << clkIn.read();
  std::cout << std::setw(4) << "";
  std::cout << std::setw(4) << writeEnableOut.read();
  std::cout << std::setw(4) << "";
  std::cout << std::setw(4) << addressAOut.read();
  std::cout << std::setw(4) << "";
  std::cout << std::setw(4) << addressBOut.read();
  std::cout << std::setw(4) << "";
  std::cout << std::setw(4) << addressWOut.read();
  std::cout << std::setw(4) << "";
  std::cout << std::setw(4) << aIn.read();
  std::cout << std::setw(4) << "";
  std::cout << std::setw(4) << bIn.read();
  std::cout << std::setw(4) << "";
  std::cout << std::setw(4) << wOut.read();
  std::cout << "\n";
}

void Testbench::test() {
  std::cout << "Tiempo    clkIn    weOut    _aOut    _bOut    _wOut    aIn    bIn    wOut\n";
  writeEnableOut.write(1);
  for (int i = 0; i < 32; ++i) {
    if (!clkIn.read()) {
      addressWOut.write(i);
      wOut.write(32 * (i + 1));
    } else {
      i--;
    }
    std::cout << "-----------------------------------------------------------------------\n";
    wait();
    print();
  }
  writeEnableOut.write(0);
  for (int i = 0; i < 32; ++i) {
    std::cout << "-----------------------------------------------------------------------\n";
    addressAOut.write(i);
    addressBOut.write(15);
    wait();
    print();
  }

  sc_stop();
}
