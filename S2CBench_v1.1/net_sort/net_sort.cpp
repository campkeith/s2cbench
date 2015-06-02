#include "net_sort.h"

void net_sort::run() {
    dout_vld.write(0);
    wait();
PROCESS_LOOP:
    while(true) {
        bool data_valid = din_vld.read();
        Size size = insize.read();
        Array array;
        if (data_valid)
        {
            typedef sc_bv<SIZE> Mask;
            Mask mask = Mask(-1) << size;
RCV_INPUTS:
            for (size_t index = 0; index < SIZE; index++) {
                array[index] = mask.get_bit(index) ? Element(-1) : indata[index].read();
            }

            sort(array);
        }
PIPE_STAGES:;
	if (data_valid)  {
            osize.write(size);
SEND_OUTPUTS:
            for (size_t index = 0; index < SIZE; index++) {
                odata[index].write(array[index]);
            }
        }
        dout_vld.write(data_valid);
        wait();
    }
}

inline void sort2(Element & a, Element & b)
{
    bool ordered = a < b;
    Element new_a = ordered ? a : b;
    Element new_b = ordered ? b : a;
    a = new_a;
    b = new_b;
}

void net_sort::sort(Array array) {
    /* Each sort net line contains operations that can run in parallel */
    const size_t sort_net[][2] = {
        {4,9},{3,8},{2,7},{1,6},{0,5},
        {1,4},{6,9},{0,3},{5,8},
        {0,2},{3,6},{7,9},
        {0,1},{2,4},{5,7},{8,9},
        {1,2},{4,6},{7,8},{3,5},
        {2,5},{6,8},{1,3},{4,7},
        {2,3},{6,7},
        {3,4},{5,6},
        {4,5},
    };
    const size_t sort_net_size = sizeof(sort_net) / sizeof(sort_net[0]);
COMPARE:
    for (size_t index = 0; index < sort_net_size; index++)
    {
        sort2(array[sort_net[index][0]], array[sort_net[index][1]]);
    }
}

#if defined(__CTOS__) 
SC_MODULE_EXPORT(net_sort)
#endif
