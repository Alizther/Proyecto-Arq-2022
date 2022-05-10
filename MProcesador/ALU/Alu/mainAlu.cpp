#include "add_Alu.h"
#include "TBalu.h"

int sc_main(int argv, char* argc[]){

    //crear reloj
    sc_time period(10,SC_NS);
    sc_time delay(10,SC_NS);

    // Creando el reloj
    sc_clock clock("clock", period, 0.5, delay, true);

    //creando instancias

    sumalu al("sum");
    TB tt("tt");

    //crear cables
    sc_signal<sc_int<32>> al_tb, tb_a, tb_b;
    sc_signal<sc_uint<32>> sc1;
    sc_signal<bool> ze_tb;
    //conectar
    al.aIn(tb_a);
    al.bIn(tb_b);
    al.scAlu(sc1);
    al.cOut(al_tb);
    al.zero(ze_tb);

    tt.cIn(al_tb);
    tt.zeroIn(ze_tb);
    tt.scOut(sc1);
    tt.aOut(tb_a);
    tt.bOut(tb_b);
    
    //iniciar reloj
    tt.clkIn(clock);

    //iniciando sim
    sc_start();

    return 0;
}