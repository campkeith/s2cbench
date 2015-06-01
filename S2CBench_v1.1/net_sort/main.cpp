
#include "net_sort.h"

#ifdef CTOS_MODEL
#include "net_sort_ctos_wrapper.h"
#else
#endif

#include "tb_net_sort.h"

int sc_main(int argc, char * argv[])
{
    sc_clock                clk("clk", 25, SC_NS, 0.5, 12.5, SC_NS, true);
    sc_signal<bool>         rst;

    sc_signal<bool> din_vld;
    sc_signal<bool> dout_vld;
    sc_signal<Size> insize;
    sc_signal<Size> osize;
    sc_signal<Element> indata[SIZE];
    sc_signal<Element> odata[SIZE];

#ifdef CTOS_MODEL
    net_sort_ctos_wrapper u_net_sort("u_net_sort", CTOS_TARGET_SUFFIX(CTOS_MODEL));
#else
    net_sort u_net_sort("u_net_sort");
#endif

    test_net_sort u_test("u_test");

    u_net_sort.clk( clk );
    u_net_sort.rst( rst );
    u_net_sort.din_vld( din_vld );
    u_net_sort.insize( insize );
    u_net_sort.dout_vld( dout_vld );
    u_net_sort.osize( osize );
    for (size_t index = 0; index < SIZE; index++) {
        u_net_sort.indata[index]( indata[index]);
        u_net_sort.odata[index](  odata[index] );
    }
 
    u_test.clk( clk );
    u_test.rst( rst );
    u_test.din_vld( din_vld );
    u_test.insize( insize );
    u_test.dout_vld( dout_vld );
    u_test.osize( osize );
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
