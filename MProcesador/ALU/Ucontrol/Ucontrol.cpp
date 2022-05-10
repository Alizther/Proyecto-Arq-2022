#include "Ucontrol.h"

UC::UC (sc_module_name nm) : sc_module(nm){
    SC_METHOD(process);
    sensitive << aIn;


}

void UC :: process(){

    //RegWrite*, ALUsrc*, MemWrite*, ALUOp, MemtoReg*, MemRead*, Branch*;//Out
    
    
    RegWrite.write(aIn.read().range(0,0));
    ALUsrc.write(aIn.read().range(1,1));
    MemWrite.write(aIn.read().range(2,2));
    MemtoReg.write(aIn.read().range(3,3));
    MemRead.write(aIn.read().range(4,4));
    Branch.write(aIn.read().range(5,5));
    ALUOp.write(aIn.read().range(9,6));
}   

UC::~UC() {}