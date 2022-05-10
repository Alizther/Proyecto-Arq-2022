#include <systemc.h>
#include <iostream>

class mux : public sc_module{

    public: 
        sc_in<bool> SrcAlu;/*ALUSrc*/
        sc_in<sc_int<32>> d0In/*readData2*/, d1In;//immGen
        sc_out<sc_int<32>> f0out;//ADDALU
        

        SC_CTOR(mux);
        ~mux();

    private:
        void process();



};