#include<InsMemory.h>

InsMemory::InsMemory(sc_module_name moduleName) : sc_module(moduleName)
{
    MemoryFile.open("InstructionMemory.txt");

    SC_METHOD(search);
    sensitive<< dir_in;    
}


InsMemory::~InsMemory()
{
    MemoryFile.close();
}

void InsMemory::search()
{
    unsigned int dir;
    sc_uint<32> instruction;
    char InstructionRead[32];
    dir = dir_in.read();
    MemoryFile.seekg(dir*(33), ios::beg);
    MemoryFile.read(InstructionRead, 33);
    
    for(int i=0 ; i < 32 ; i++)
    {
        if (InstructionRead[i] == '1')
        {
            instruction[31-i] = 1;
        }
        else
        {
            instruction[31-i] = 0;
        }
    }
 
    dir_out.write(instruction);
}