#include "mux_alu.h"
#include "Testbench.h"


int sc_main(int argv, char* argc[]) {
  // Configuración del reloj
  sc_time period(10,SC_NS);
  sc_time delay(10,SC_NS);

  // Creando el reloj
  sc_clock clock("clock", period, 0.5, delay, true);

  // Creando instancias de los módulos
  mux mux1("mux1");
  Testbench tb("tb");

  // Necesitaremos cables para conectar los módulos
  sc_signal<sc_int<32>> fSg;
  sc_signal<sc_int<32>> d0Sg, d1Sg;
  sc_signal<bool> s0Sg;

  // Conectando los módulos a los cables
  mux1.SrcAlu(s0Sg);
  mux1.d0In(d0Sg);
  mux1.d1In(d1Sg);
  mux1.f0out(fSg);

  tb.fIn(fSg);
  tb.s0Out(s0Sg);
  tb.d0Out(d0Sg);
  tb.d1Out(d1Sg);

  // Conectando el reloj al testbench
  tb.clkIn(clock);

  // Inicializando el simulador
  sc_start();

  return 0;
}
