#include "TBadd2.h"


TB::TB(sc_module_name moduleName) : sc_module(moduleName) {
    SC_THREAD(test);
    sensitive << clkIn.pos();
};

TB::~TB() {}

void TB::print() {
    cout << d0Out.read() << " " << d1Out.read() << " " << " " << aIn.read() << " \t" <<  aIn.read().to_string(SC_BIN) << endl;
}

void TB::test() {
    cout << "Starting test" << endl;
    cout << "A B S" << endl;
    //int a[] = {2, 3, 5, 7};
    //int b[] = {4, 6, 8, 9};
    int a[31];
    int b[31];
    for(int i = 0; i<31 ; i++){
        a[i] = i+1;
        b[i] = i+81;
    }
    
    for (int i = 0; i < 31; ++i) {
        d0Out.write(a[i]);
        d1Out.write(b[i]);
        wait();
        print();
    
    }
    sc_stop();
}