#ifndef NET_SORT_H
#define NET_SORT_H

#include "define.h"

typedef sc_uint<8> Element;
typedef Element Array[SIZE];

SC_MODULE(net_sort)
{
    sc_in<bool> clk;
    sc_in<bool> rst;

    sc_in<Element> indata;
    sc_out<Element> odata;

    void run();
    void sort(Array &);

    SC_CTOR( net_sort) {
        SC_CTHREAD(run, clk.pos());
        reset_signal_is(rst, false);
    }

    ~net_sort() {}

};

#endif // NET_SORT_H
