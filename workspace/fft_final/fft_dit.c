//Implementation of DIT_FFT/IFFT with TIE

#include "fft.h"
#include <xtensa/tie/xt_booleans.h>
#include <xtensa/tie/fft_tie.h>
#include <stdio.h>

#define aligned_by_16 __attribute__ ((aligned(16)))
#define aligned_by_8 __attribute__ ((aligned(8)))
#define aligned_by_4 __attribute__ ((aligned(4)))
#define fixed_complex int

#define SHUFFLE 0
#define REVERSE_SHUFFLE 1

#define UPPER 1
#define LOWER 0



int fix_fft_dit(fixed fr[], fixed fi[], int m, int inverse)
{
    int mr,nn,i,j,l,k,istep, n, scale, shift;
    
    fixed qr,qi;		//even input
    fixed tr,ti;		//odd input
    fixed wr,wi;		//twiddle factor
    
    //number of input data
    n = 1<<m;
    int size=m;

    if(n > N_WAVE) return -1;

    mr = 0;
    nn = n - 1;
    scale = 0;

    /* decimation in time - re-order data */
    for(m=1; m<=nn; ++m) {

        mr = BIT_REVERSE(m,size);

        if(mr <= m) continue;
        tr = fr[m];
        fr[m] = fr[mr];
        fr[mr] = tr;
        
        ti = fi[m];
        fi[m] = fi[mr];
        fi[mr] = ti;
    }
	
    
    l = 1;
    k = LOG2_N_WAVE-1;
    while(l < n)
    {
        if(inverse)
        {
            /* variable scaling, depending upon data */
            shift = 0;
            for(i=0; i<n; i=i+8)
            {
                reg8x16 j_reg =SIMD_LOAD(fr,i);
                reg8x16 m_reg =SIMD_LOAD(fi,i);
                
                if(SHIFT_CONDITION(j_reg,m_reg))
                {
                    shift = 1;
                    break;
                }
            }
            if(shift) ++scale;
        }
        else
        {

            shift = 1;
        }
        
        if (l==1)
        {

        	register reg8x16 real, imag;

            for(i=0;i<n;i=i+8)
            {
                k=LOG2_N_WAVE-1;

                real=SIMD_LOAD(fr,i);
                imag=SIMD_LOAD(fi,i);

                DIT_FIRST_STAGE(k, inverse, shift, real, imag);
                --k;
                DIT_SECOND_STAGE(k, inverse, shift, real, imag);
                --k;
                DIT_THIRD_STAGE(k, inverse, shift, real, imag);


                SIMD_STORE_SHUFFLED(fr, i, real, REVERSE_SHUFFLE);
                SIMD_STORE_SHUFFLED(fi, i, imag, REVERSE_SHUFFLE);

            }
        
            l=4;
        }
        else { // Stages greater than 3
        	
        	register reg8x16 real_1, imag_1, real_2, imag_2;
        	
        	WUR_REG_K(k);
        	
        	for (i=0; i<n; i = i+2*l)
        	{
	        	for (m = i; m<l+i; m+=8)
	        	{
	        		// Loading of values
					SIMD_LOAD_INTERLEAVED(fr, m, real_1, real_2, UPPER);
					SIMD_LOAD_INTERLEAVED(fi, m, imag_1, imag_2, UPPER);
					
					SIMD_LOAD_INTERLEAVED(fr, m+l, real_1, real_2, LOWER);
					SIMD_LOAD_INTERLEAVED(fi, m+l, imag_1, imag_2, LOWER);
	

					//calculation part
					DIT_CALC_STAGE(real_1, imag_1, shift, m, inverse);
					DIT_CALC_STAGE(real_2, imag_2, shift, m+4, inverse);
					

					// Storing of Result Values
					SIMD_STORE_INTERLEAVED(fr, m, real_1, real_2, UPPER);
					SIMD_STORE_INTERLEAVED(fi, m, imag_1, imag_2, UPPER);
					
					SIMD_STORE_INTERLEAVED(fr, m+l, real_1, real_2, LOWER);
					SIMD_STORE_INTERLEAVED(fi, m+l, imag_1, imag_2, LOWER);
	        	}
        	}
        }           
        
        
        --k;
        l <<=1;
    }

    return scale;
}
