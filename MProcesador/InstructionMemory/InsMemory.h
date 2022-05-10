#ifndef INSMEMORY_H
#define INSMEMORY_H
#include <systemc.h>
#include <fstream>

using namespace std;

class InsMemory : public sc_module {

    public:
    sc_in <sc_uint<5>> dir_in;
    sc_out<sc_uint<32>> dir_out;
    //sc_out<sc_uint<32>> dircontrol_out;
    ifstream MemoryFile;

    SC_CTOR(InsMemory);
    ~InsMemory();

    private:
    
    void search();

};


#endif
