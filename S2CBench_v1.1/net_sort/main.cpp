#include "net_sort.h"
#include "tb_net_sort.h"

int sc_main(int argc, char** argv)
{
  sc_clock                clk("clk", 25, SC_NS, 0.5, 12.5, SC_NS, true);
  sc_signal<bool>         rst;
 
   sc_signal<sc_uint<8> > indata;
   sc_signal<sc_uint<8> > odata;

   net_sort u_net_sort("net_sort");
   test_net_sort u_test("test_net_sort");

   //connect to bubble sort
   u_net_sort.clk( clk );
   u_net_sort.rst( rst );

   u_net_sort.indata( indata);
   u_net_sort.odata(  odata );
 
  // connect to test bench
  u_test.clk( clk );
  u_test.rst( rst );
  
  u_test.indata( indata );
  u_test.odata( odata );


#ifdef WAVE_DUMP
  // Trace files
  sc_trace_file* trace_file = sc_create_vcd_trace_file("trace_behav");

  // Top level signals
  sc_trace(trace_file, clk              , "clk");
  sc_trace(trace_file, rst              , "rst");
 
   sc_trace(trace_file, indata          , "indata"); 
   sc_trace(trace_file,  odata            ,"odata");
 
#endif  // End WAVE_DUMP

  sc_start( 25, SC_NS );
  rst.write(0);

  sc_start( 25, SC_NS );
  rst.write(1);

  sc_start();

#ifdef WAVE_DUMP
   sc_close_vcd_trace_file(trace_file);
#endif

    return 0;

};
