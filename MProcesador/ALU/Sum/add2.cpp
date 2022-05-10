#include "add2.h"

add2::add2 (sc_module_name nm) : sc_module(nm){
    SC_METHOD(process);
    sensitive << aIn << bIn;


}

void add2 :: process(){

    cOut.write(aIn.read() + bIn.read());

    
}

add2::~add2() {}