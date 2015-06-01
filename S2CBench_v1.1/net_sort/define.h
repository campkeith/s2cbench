#ifndef DEFINE_H
#define DEFINE_H

#include "systemc.h"


#define SIZE 10
#define ELEMENT_BITS 8
#define SIZE_BITS 4

typedef sc_uint<ELEMENT_BITS> Element;
typedef sc_uint<SIZE_BITS> Size;
typedef Element Array[SIZE];

#endif
