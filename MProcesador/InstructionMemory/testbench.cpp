#include <testbench.h>

void testbench:: test ()
{
    std::cout<<"\t\t______________________________________________________\n\n";
	std::cout << "\t" << "CLOCK" << " || " << "instr_out" << " | " << "instr_in  \n";
	
	for (int i = 0; i < 32; i++)
	{
	  instr_out.write(i);

	  wait();
	  print();
	}

    sc_stop();
}


void testbench:: print()
{
    std::cout << "\t" << sc_time_stamp() << " || " << instr_out.read() << " \t | " << instr_in.read().to_string(SC_BIN).substr(3) << endl;
	    std::cout<<"\t\t___________________________________________________"<<"\n";
}
