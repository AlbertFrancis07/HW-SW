
#ifndef FIR_DATA_H
#define FIR_DATA_H

//coefficients for FIR filter
short coeff[8] = {-3, 4, -3, 2, 5, -1, 4, 8};

//global array in dram1
int firOut_TIE[200] __attribute__((section(".dram1.data")));

#endif
