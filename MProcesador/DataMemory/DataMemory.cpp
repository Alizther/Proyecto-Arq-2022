#include<DataMemory.h>

DataMemory::DataMemory(sc_module_name moduleName):sc_module(moduleName)
{
    SC_METHOD(write);
        sensitive << clk.pos();
    
    SC_METHOD(read);
        sensitive << clk.neg();

    DataFile.open("DataMemory.txt", std::fstream::in | std::fstream::out | std::fstream::app);

}

DataMemory::~DataMemory()
{
    DataFile.close();
}

void DataMemory::write()
{
    unsigned int dir;
    sc_uint<32> data;
    data= data_in.read();
    dir= dir_in.read();
    DataFile.seekp(dir*(33),ios::beg);
    for(int i=0; i < 32; i++)
    {
        if (data [31-i] == 1)
        {
            DataFile << '1';
        }
        else 
        {
            DataFile << '0';
        }
    }
    DataFile << '\n';
}

void DataMemory::read()
{
    char aux[32];
    sc_uint<32> data;
    unsigned int dir;
    dir = dir_in.read();
    DataFile.seekg(dir*(33),ios::beg);
    DataFile.read(aux,33);
    for(int i =0; i< 32; i++)
    {
        if(aux[i] == '1')
        {
            data[31-i] = 1;
        }
        else
        {
            data[31-i] = 0;
        }
    }
    data_out.write(data);
}