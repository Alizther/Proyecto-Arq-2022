#include "Ucontrol.h"
#include "TBUC.h"


int sc_main(int argv, char* argc[]){

    //crear reloj
    sc_time period(10,SC_NS);
    sc_time delay(10,SC_NS);

    // Creando el reloj
    sc_clock clock("clock", period, 0.5, delay, true);

    //creando instancias

    UC ct("ct");
    TB tst("tst");

    //crear cables
    sc_signal<sc_uint<32>> AO_tb, tb_Uc;
    sc_signal<bool> RW_tb, src_tb, MW_tb, MtoR_tb, MR_tb, Bh_tb;

    //conectar
    ct.aIn(tb_Uc);//IN
    ct.ALUOp(AO_tb);//OUT
    ct.RegWrite(RW_tb);
    ct.ALUsrc(src_tb);
    ct.MemWrite(MW_tb);
    ct.MemtoReg(MtoR_tb);
    ct.MemRead(MR_tb);
    ct.Branch(Bh_tb);



    tst.aOut(tb_Uc);
    tst.AO(AO_tb);
    tst.RW(RW_tb);
    tst.src(src_tb);
    tst.MW(MW_tb);
    tst.MtoR(MtoR_tb);
    tst.MR(MR_tb);
    tst.Bh(Bh_tb);
    
    


    //iniciar reloj
    tst.clkIn(clock);

    //iniciando sim
    sc_start();

    return 0;
}