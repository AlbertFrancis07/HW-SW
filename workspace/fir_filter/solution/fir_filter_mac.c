/*
 * fir_filter_mac.c
 * 
 * FIR filter implementation by using fusion
 * with 8 coefficients
 * 
 * in:	pointer to input array
 * out:	pointer to output array
 * len:	#input values
 */

#include "fir_filter.h"

#if FIR_TIE==0

extern short coeff[8];

void fir_macTIE(short *in, int *out, int len)
{
	int i, j;
	
	for (i = 0; i < len+7; i++)
	{
		for (j = 0; j < 8; j++) FIR_MAC(out[i], in[i+7-j], coeff[j]);
    }
}

#endif
