#include <iostream>
#include <systemc.h>


class sumalu : public sc_module{

    public:
        
        sc_in<sc_uint<32>> scAlu;
        sc_in<sc_int<32>> aIn, bIn;//ReadData/Mux/Control
        sc_out<sc_int<32>> cOut;//DataMemori 
        sc_out<bool> zero;//salto
        
        SC_CTOR(sumalu);
        ~sumalu();


    private:
        void process();
        void suma();
        void resta();
        void mult();
        void salt(int s);
        void and1();
        void or1();
        void div();
        void modu();
};