#include "TBalu.h"

TB::TB(sc_module_name moduleName) : sc_module(moduleName) {
    SC_THREAD(test);
    sensitive << clkIn.pos();
};

TB::~TB() {}
//aOut, bOut, scOut;s
//cIn, zeroIn;

void TB::print() {
    cout << aOut.read() << " " << bOut.read() << " " << scOut.read() << " " << cIn.read() << " "<< zeroIn.read() << " \t" <<  cIn.read().to_string(SC_BIN) << endl;
}

void TB::test() {
    cout << "Starting test" << endl;
    cout << "A B Sc C Z" << endl;
    
    int s[9];
    
    for(int i = 0; i<9 ; i++){
        s[i] = i+1;
    }

    int a[31];
    int b[31];
    for(int i = 0; i<31 ; i++){
        a[i] = i+1;
        b[i] = i+81;
    }

    for (int i = 0; i < 9; ++i) {
        //señal y ahi se cuadra lo demas y sinc con el swift
        scOut.write(s[i]);
        aOut.write(a[i]);
        bOut.write(b[i]);
        wait();
        print();
    
    }
    sc_stop();
}
