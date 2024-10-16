//main.c

#include 		"fft.h"
#include        <stdio.h>
#include        <math.h>

#define DO_FFT	1

#define M       3

#define N       (1<<M)

fixed real[N] __attribute__ ((section(".dram0.data")));
fixed imag[N] __attribute__ ((section(".dram1.data")));

fixed  real_dit_ref[N];
fixed  imag_dit_ref[N];

fixed  real_dif_ref[N];
fixed  imag_dif_ref[N];

fixed  real_dit[N];
fixed  imag_dit[N];

fixed  real_dif[N];
fixed  imag_dif[N];


int main()
{
    int i;

    for(i=0; i<N; i++)
    {
        real[i] = 1000*cos(i*2*3.1415926535/N);
//        real_dit_ref[i]=real[i];
//        real_dif_ref[i]=real[i];
        real_dit[i]=real[i];
        //real_dif[i]=real[i];

        imag[i] = 0;
//        imag_dit_ref[i]=imag[i];
//        imag_dif_ref[i]=imag[i];
        imag_dit[i]=imag[i];
        //imag_dif[i]=imag[i];
    }
    
    printf("\nInput Data\n");
    for (i=0; i<N; i++)
    {
    	printf("%d: %d, %d\n", i, real[i], imag[i]);
    }
	
    
    //FFT
#if (DO_FFT==1)

//    fix_fft_dit_ref(real_dit_ref, imag_dit_ref, M, 0);
//    fix_fft_dif_ref(real_dif_ref, imag_dif_ref, M, 0);
    fix_fft_dit(real_dit,imag_dit,M,0);
    //fix_fft_dif(real_dif,imag_dif,M,0);

    printf("--------------DIT-------------\n");
    //printf("\nFFT_DIT with TIE  |  FFT_DIT without TIE\n");
    //printf("\nFFT_DIT with TIE\n");
    for (i=0; i<N; i++)
    {
       // printf("%d: %d, %d    |   %d,  %d\n", i, real_dit[i], imag_dit[i],real_dit_ref[i],imag_dit_ref[i]);
        printf("%d: %d, %d \n", i, real_dit[i], imag_dit[i]);
    }
    

    /*printf("--------------DIF-------------\n");
    //printf("\nFFT_DIF with TIE  |  FFT_DIF without TIE\n");
    for (i=0; i<N; i++)
    {
       // printf("%d: %d, %d    |   %d,  %d\n", i, real_dif[i], imag_dif[i],real_dif_ref[i],imag_dif_ref[i]);
        printf("%d: %d, %d\n", i, real_dif[i], imag_dif[i]);
    }*/

#else
    //IFFT
    //fix_fft_dit_ref(real_dit_ref, imag_dit_ref, M, 1);
    //fix_fft_dif_ref(real_dif_ref, imag_dif_ref, M, 1);
    fix_fft_dit(real_dit,imag_dit,M,1);
    //fix_fft_dif(real_dif,imag_dif,M,1);
    

    printf("--------------DIT-------------\n");
    //printf("\nIFFT_DIT with TIE  |  IFFT_DIT without TIE\n");
    for (i=0; i<N; i++)
    {
        //printf("%d: %d, %d    |   %d,  %d\n", i, real_dit[i], imag_dit[i],real_dit_ref[i],imag_dit_ref[i]);
        printf("%d: %d, %d\n", i, real_dit[i], imag_dit[i]);
    }
    

   /* printf("--------------DIF-------------\n");
    //printf("\nIFFT_DIF with TIE  |  IFFT_DIF without TIE\n");
    for (i=0; i<N; i++)
   {
        printf("%d: %d, %d\n", i, real_dif[i], imag_dif[i]);
    }*/

    
#endif

    return 0;
}

