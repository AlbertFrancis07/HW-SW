
#ifndef FFT_H
#define FFT_H


#define FIX_MPY(DEST,A,B)       DEST = ((long)(A) * (long)(B))>>15

#define N_WAVE          1024    /* dimension of Sinewave[] */
#define LOG2_N_WAVE     10      /* log2(N_WAVE) */

#ifndef fixed
#define fixed short
#endif

extern fixed Sinewave[N_WAVE];

//function prototypes
fixed fix_mpy(fixed a, fixed b);
int fix_fft_dit_ref(fixed *fr, fixed *fi, int m, int inverse);
int fix_fft_dif_ref(fixed *fr, fixed *fi, int m, int inverse);
int fix_fft_dit(fixed *fr, fixed *fi, int m, int inverse);
int fix_fft_dif(fixed fr[], fixed fi[], int m, int inverse);



#endif	//FFT_H
