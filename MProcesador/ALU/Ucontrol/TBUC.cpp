#include "TBUC.h"


TB::TB(sc_module_name moduleName) : sc_module(moduleName) {
    SC_THREAD(test);
    sensitive << clkIn.pos();
};

TB::~TB() {}

void TB::print() {
    cout << RW.read() << "   " << src.read() << "   " << MW.read() << "   " << MtoR.read() << "   " << MR.read() << "   " << Bh.read(); 
    cout << "   " << AO.read() <<" \t" <<  aOut.read().to_string(SC_BIN) << endl;
}
//RW, src, MW, MtoR, MR, Bh;
void TB::test() {
    cout << "Starting test" << endl;
    cout << "RW src MW MtoR MR Bh ALUOp    A" << endl;
            
    //RW=0No escribe/=1 Escrbie
    //src=0Reg Leido/=1 Inmediato
    //Mw=0Nada/=1
    //MR=0Nada/=1
    //Bh=0Pc+4/=1Valor del Sum
    //MtoR=0OutAlu/=1DtaRead
    //ALUOP=Quehace la Alu;



                                        //-OP-BRtWSR            
    aOut.write("0bus00000000000000000000001001000011");
    //Llenar Ao

    wait();
    print();
    

    sc_stop();
}