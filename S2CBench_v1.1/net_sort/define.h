#ifndef DEFINE_H
#define DEFINE_H

#include "systemc.h"

#include <iostream>
#include "stdio.h"


#define SIZE 10
#define ELEMENT_BITS 8
#define SIZE_BITS 4

#define INFILENAME               "net_sort_in_data.txt"


#define OUTFILENAME_GOLDEN       "net_sort_output_golden.txt"
#define OUTFILENAME              "net_sort_output.txt"
#define DIFFFILENAME             "net_sort_diff.txt"

typedef sc_uint<ELEMENT_BITS> Element;
typedef sc_uint<SIZE_BITS> Size;
typedef Element Array[SIZE];

#endif
