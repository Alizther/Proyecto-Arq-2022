#include "add2.h"
#include "TBadd2.h"


int sc_main(int argv, char* argc[]){

    //crear reloj
    sc_time period(10,SC_NS);
    sc_time delay(10,SC_NS);

    // Creando el reloj
    sc_clock clock("clock", period, 0.5, delay, true);

    //creando instancias

    add2 sum("sum");
    TB test("test");

    //crear cables
    sc_signal<sc_int<32>> ad_tb, tb_ad1, tb_ad2;

    //conectar
    sum.aIn(tb_ad1);
    sum.bIn(tb_ad2);
    sum.cOut(ad_tb);

    test.aIn(ad_tb);
    test.d0Out(tb_ad1);
    test.d1Out(tb_ad2);
    
    //iniciar reloj
    test.clkIn(clock);

    //iniciando sim
    sc_start();

    return 0;
}