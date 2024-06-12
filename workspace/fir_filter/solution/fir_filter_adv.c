/*
 * fir_filter_adv.c
 * 
 * FIR filter implementation with dedicated states and operations
 * with 8 coefficients
 * 
 * in:	pointer to input array
 * out:	pointer to output array
 * len:	#input values
 */

#include "fir_filter.h"

#if FIR_TIE==2

void FIR_advancedTIE(short *in, int *out, int len)
{
	int i;
	
	WUR_st_cnt(1);
	WUR_ptr_in((unsigned)in);
	WUR_ptr_out((unsigned)out);
	
	//load first 8 elements
	FIR_LD();
	
	//load second 8 elements, write the first 8 into in128_1
	FIR_LD();
	WUR_in128_1_0(RUR_in128_2_0());
	WUR_in128_1_1(RUR_in128_2_1());
	WUR_in128_1_2(RUR_in128_2_2());
	WUR_in128_1_3(RUR_in128_2_3());
	
	//load third 8 elements
	FIR_LD();
	
	for(i=0; i<((len+14)>>3)-2; i++)
	{
		//8 times
		FIR_CALC_ST();
		FIR_CALC_ST();
		FIR_CALC_ST();
		FIR_CALC_ST();
		FIR_CALC_ST();
		FIR_CALC_ST();
		FIR_CALC_ST();
		FIR_CALC_ST();
		
		FIR_LD();
	}
	
	//8 times
	FIR_CALC_ST();
	FIR_CALC_ST();
	FIR_CALC_ST();
	FIR_CALC_ST();
	FIR_CALC_ST();
	FIR_CALC_ST();
	FIR_CALC_ST();
	FIR_CALC_ST();
	
	//2 times, because of pipelining
	FIR_CALC_ST();
	FIR_CALC_ST();
}

#endif
