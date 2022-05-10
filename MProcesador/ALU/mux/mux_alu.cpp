#include "mux_alu.h"

mux::mux (sc_module_name nm) : sc_module(nm){
    SC_METHOD(process);
    sensitive << d0In << d1In << SrcAlu;


}

void mux :: process(){

    sc_int<32> a = !SrcAlu.read(); //PENDIENTE CON LAS ENTRADAS O EL CAMBIO DE LAS IN// NEGADO PARA QUE 
    sc_int<32> b = d0In.read() and a;//En señal 0 active la i 0
    sc_int<32> c = d1In.read() and SrcAlu.read();//En señal 1 active esta y la otra negada en 0
    f0out.write(b or c);


    
}

mux::~mux() {}