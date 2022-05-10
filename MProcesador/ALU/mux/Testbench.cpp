#include "Testbench.h"


Testbench::Testbench(sc_module_name mn) : sc_module(mn) {
  SC_THREAD(test);
  sensitive << clkIn.pos();
  dont_initialize();
}

void Testbench::print() {
  cout << sc_time_stamp() << "    ";
  cout << d0Out.read() << "    ";
  cout << d1Out.read() << "    ";
  cout << s0Out.read() << "    ";
  cout << fIn.read() << "\n";
}

/**
 * Al correr el programa, verán la salida f del multiplexor
 * seleccionando ambas entradas de datos para todas las combinaciones
 * posibles para la entrada de datos (cada combinación separada por
 * una linea).
 */
void Testbench::test() {
  cout << "Tiempo   d1   d0   s0   f\n";
  cout << "-------------------------\n";

  for (int i=0; i<2; ++i) {
    d0Out.write(i);
    for (int j=0; j<2; ++j) {
      d1Out.write(j);
      for (int k=0; k<2; k++) {
        s0Out.write(k);
        wait();
        print();
      }
      cout << "-------------------------\n";
    }
  }
  sc_stop();
}