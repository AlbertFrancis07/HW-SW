/*
 * FIR filter implementation by using fusion and SIMD
 * with 8 coefficients
 * 
 * in:	pointer to input array
 * out:	pointer to output array
 * len:	#input values
 */


#include "fir_filter.h"

#if FIR_TIE==1

extern short coeff[8];

void fir_simdTIE(short *in, int *out, int len)
{
	int i;

	VR_fir *vr_p_coeff = (VR_fir*)coeff;
	VR_fir vr_inpArr_slice;

	for (i = 0; i < len+7; i++)
	{
    	memcpy((void*)&vr_inpArr_slice, (void*)&in[i], 16);
    	out[i] = FIR_MAC_SIMD(vr_inpArr_slice, *vr_p_coeff);
	}
}

#endif
