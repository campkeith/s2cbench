#include "net_sort.h"
#include "tb_net_sort.h"

int sc_main(int argc, char * argv[])
{
    sc_clock                clk("clk", 25, SC_NS, 0.5, 12.5, SC_NS, true);
    sc_signal<bool>         rst;

    sc_signal<Element> indata[SIZE];
    sc_signal<Element> odata[SIZE];

    net_sort u_net_sort("net_sort");
    test_net_sort u_test("test_net_sort");

    u_net_sort.clk( clk );
    u_net_sort.rst( rst );
    for (size_t index = 0; index < SIZE; index++) {
        u_net_sort.indata[index]( indata[index]);
        u_net_sort.odata[index](  odata[index] );
    }
 
    u_test.clk( clk );
    u_test.rst( rst );
    for (size_t index = 0; index < SIZE; index++) {  
        u_test.indata[index]( indata[index] );
        u_test.odata[index]( odata[index] );
    }

    sc_start(25, SC_NS );
    rst.write(0);

    sc_start(25, SC_NS );
    rst.write(1);

    sc_start();
    return 0;
};
