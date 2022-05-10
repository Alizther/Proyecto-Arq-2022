#include<InsMemory.h>
#include<testbench.h>


int sc_main(int argc,char*argv[])
{
    sc_time DELAY(10,SC_NS);
	sc_time PERIOD(10,SC_NS);
	
	sc_clock clk("clock",PERIOD,0.5,DELAY,true);
	sc_signal< sc_uint<5> > PC;
	sc_signal< sc_uint<32> > Instruction;
	sc_signal< bool > enable;
	InsMemory InsMemory("InsMemory");
	testbench test("test");

	InsMemory.dir_in(PC);
	InsMemory.dir_out(Instruction);
		
	test.instr_in(Instruction);
	test.instr_out(PC);
	test.clk(clk);
	

	sc_start();

 return 0;
}