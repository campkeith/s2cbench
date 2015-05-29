#ifndef NET_SORT_H
#define NET_SORT_H

#include "define.h"

SC_MODULE(net_sort)
{
    sc_in<bool> clk;
    sc_in<bool> rst;

    sc_in<bool> din_vld;
    sc_in<Size> insize;
    sc_in<Element> indata[SIZE];
    sc_out<bool> dout_vld;
    sc_out<Size> osize;
    sc_out<Element> odata[SIZE];

    void run();
    void sort(Array &);

    SC_CTOR( net_sort) {
        SC_CTHREAD(run, clk.pos());
        reset_signal_is(rst, false);
    }

    ~net_sort() {}

};

#endif // NET_SORT_H
