#include <iostream>
#include <systemc.h>

class add2 : public sc_module{

    public: 
        sc_in<sc_int<32>> aIn;//IF
        sc_in<sc_int<32>> bIn;//ImmGen
       
        sc_out<sc_int<32>> cOut;//registro

        SC_CTOR(add2);
        ~add2();

    private:

        void process();



};