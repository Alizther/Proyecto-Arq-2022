#include <testbench.h>

testbench::testbench(sc_module_name moduleName):sc_module(moduleName)
{
    SC_THREAD(test);
        sensitive<< clk.neg();
        dont_initialize();
}

void testbench::test()
{
    std::cout<<"\t___________________________________________________\n\n";
    std::cout << "\t" << "CLOCK" <<  " | " << "DATA_OUT" << " || " << " | " << "dir_out" << " || " << "data_IN" << "\n\n\n";
    for (int i=0; i <10; i++)
    {
        data_out.write(i);
        dir_out.write(i);
        wait();
        print();
    }
    sc_stop();
}

void testbench::print()
{
    std::cout << "\t" << sc_time_stamp() << " || " << data_out.read() <<  "\t | " << dir_out.read() << "  | " << data_in.read() << "\n";
	std::cout<<"\t___________________________________________________"<<"\n";

}