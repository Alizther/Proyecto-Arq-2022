#ifndef DATAMEMORY_H
#define DATAMEMORY_H
#include <systemc.h>
#include <fstream>

using namespace std;

class DataMemory : public sc_module
{
    public:
    sc_in_clk clk;
    sc_in <sc_uint<32>> data_in;
    sc_in <bool> write_enable_in;
    sc_in <sc_uint<5>> dir_in; // el tamaño de la direccion cambia en base a lo que la Alu retorne
    sc_out <sc_uint<32>> data_out;

    SC_CTOR(DataMemory);
    ~DataMemory();
    fstream DataFile;

    private:

    void write();
    void read();

};

#endif