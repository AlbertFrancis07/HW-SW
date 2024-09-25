/* Definitions for the fft TIE package */

/*
 * Copyright (c) 2004-2010 by Tensilica Inc.  ALL RIGHTS RESERVED.
 * These coded instructions, statements, and computer programs are the
 * copyrighted works and confidential proprietary information of Tensilica Inc.
 * They may not be modified, copied, reproduced, distributed, or disclosed to
 * third parties in any manner, medium, or form, in whole or in part, without
 * the prior written consent of Tensilica Inc.
 */

/* Do not modify. This is automatically generated.*/

#ifndef _XTENSA_fft_HEADER
#define _XTENSA_fft_HEADER

#ifdef __XTENSA__
#ifdef __XCC__

#include <xtensa/tie/xt_core.h>
#include <xtensa/tie/xt_booleans.h>
typedef _TIE_fft_vect8x16 vect8x16;

/*
 * The following prototypes describe intrinsic functions
 * corresponding to TIE instructions.  Some TIE instructions
 * may produce multiple results (designated as "out" operands
 * in the iclass section) or may have operands used as both
 * inputs and outputs (designated as "inout").  However, the C
 * and C++ languages do not provide syntax that can express
 * the in/out/inout constraints of TIE intrinsics.
 * Nevertheless, the compiler understands these constraints
 * and will check that the intrinsic functions are used
 * correctly.  To improve the readability of these prototypes,
 * the "out" and "inout" parameters are marked accordingly
 * with comments.
 */

extern void _TIE_fft_st_vect8x16(vect8x16 a, vect8x16 * b, immediate c);
extern void _TIE_fft_vect8x16_storei(vect8x16 a, vect8x16 * b, immediate c);
extern vect8x16 _TIE_fft_ld_vect8x16(const vect8x16 * b, immediate c);
extern vect8x16 _TIE_fft_vect8x16_loadi(const vect8x16 * b, immediate c);
extern vect8x16 _TIE_fft_mv_vect8x16(vect8x16 b);
extern vect8x16 _TIE_fft_vect8x16_move(vect8x16 b);
extern unsigned _TIE_fft_RUR_REG_K(void);
extern void _TIE_fft_WUR_REG_K(unsigned v);
extern unsigned _TIE_fft_FFT_REVERSE_BITS(unsigned d, unsigned size);
extern void _TIE_fft_FFT_DIT_CALC_FIRST_STAGE(unsigned k, xtbool inverse, xtbool shift, vect8x16 real /*inout*/, vect8x16 imag /*inout*/);
extern void _TIE_fft_FFT_DIT_CALC_SECOND_STAGE(unsigned k, xtbool inverse, xtbool shift, vect8x16 real /*inout*/, vect8x16 imag /*inout*/);
extern void _TIE_fft_FFT_DIT_CALC_THIRD_STAGE(unsigned k, xtbool inverse, xtbool shift, vect8x16 real /*inout*/, vect8x16 imag /*inout*/);
extern void _TIE_fft_FFT_DIF_CALC_THIRD_LAST_STAGE(unsigned k, xtbool inverse, xtbool shift, vect8x16 real /*inout*/, vect8x16 imag /*inout*/);
extern void _TIE_fft_FFT_DIF_CALC_SECOND_LAST_STAGE(unsigned k, xtbool inverse, xtbool shift, vect8x16 real /*inout*/, vect8x16 imag /*inout*/);
extern void _TIE_fft_FFT_DIF_CALC_LAST_STAGE(unsigned k, xtbool inverse, xtbool shift, vect8x16 real /*inout*/, vect8x16 imag /*inout*/);
extern void _TIE_fft_FFT_DIT_CALC_STAGE(vect8x16 real /*inout*/, vect8x16 imag /*inout*/, xtbool shift, unsigned m, xtbool inverse);
extern void _TIE_fft_FFT_DIF_CALC_STAGE(vect8x16 real /*inout*/, vect8x16 imag /*inout*/, xtbool shift, unsigned m, xtbool inverse);
extern xtbool _TIE_fft_FFT_CHECK_SHIFT_CONDITION(vect8x16 j_vector, vect8x16 m_vector);
extern vect8x16 _TIE_fft_FFT_SIMD_LOAD_SHUFFLED(const void * addr, unsigned offset, immediate reverse);
extern void _TIE_fft_FFT_SIMD_STORE_SHUFFLED(void * addr, unsigned offset, vect8x16 input, immediate reverse);
extern vect8x16 _TIE_fft_FFT_SIMD_LOAD(const void * addr, unsigned offset);
extern void _TIE_fft_FFT_SIMD_STORE(void * addr, unsigned offset, vect8x16 data);
extern void _TIE_fft_FFT_SIMD_LOAD_INTERLEAVED(const void * addr, unsigned offset, vect8x16 vec1 /*inout*/, vect8x16 vec2 /*inout*/, immediate load_upper);
extern void _TIE_fft_FFT_SIMD_STORE_INTERLEAVED(void * addr, unsigned offset, vect8x16 vec1, vect8x16 vec2, immediate store_upper);
#define st_vect8x16 _TIE_fft_st_vect8x16
#define vect8x16_storei _TIE_fft_vect8x16_storei
#define ld_vect8x16 _TIE_fft_ld_vect8x16
#define vect8x16_loadi _TIE_fft_vect8x16_loadi
#define mv_vect8x16 _TIE_fft_mv_vect8x16
#define vect8x16_move _TIE_fft_vect8x16_move
#define RUR_REG_K _TIE_fft_RUR_REG_K
#define RREG_K _TIE_fft_RUR_REG_K
#define RUR0 _TIE_fft_RUR_REG_K
#define WUR_REG_K _TIE_fft_WUR_REG_K
#define WREG_K _TIE_fft_WUR_REG_K
#define WUR0 _TIE_fft_WUR_REG_K
#define FFT_REVERSE_BITS _TIE_fft_FFT_REVERSE_BITS
#define FFT_DIT_CALC_FIRST_STAGE _TIE_fft_FFT_DIT_CALC_FIRST_STAGE
#define FFT_DIT_CALC_SECOND_STAGE _TIE_fft_FFT_DIT_CALC_SECOND_STAGE
#define FFT_DIT_CALC_THIRD_STAGE _TIE_fft_FFT_DIT_CALC_THIRD_STAGE
#define FFT_DIF_CALC_THIRD_LAST_STAGE _TIE_fft_FFT_DIF_CALC_THIRD_LAST_STAGE
#define FFT_DIF_CALC_SECOND_LAST_STAGE _TIE_fft_FFT_DIF_CALC_SECOND_LAST_STAGE
#define FFT_DIF_CALC_LAST_STAGE _TIE_fft_FFT_DIF_CALC_LAST_STAGE
#define FFT_DIT_CALC_STAGE _TIE_fft_FFT_DIT_CALC_STAGE
#define FFT_DIF_CALC_STAGE _TIE_fft_FFT_DIF_CALC_STAGE
#define FFT_CHECK_SHIFT_CONDITION _TIE_fft_FFT_CHECK_SHIFT_CONDITION
#define FFT_SIMD_LOAD_SHUFFLED _TIE_fft_FFT_SIMD_LOAD_SHUFFLED
#define FFT_SIMD_STORE_SHUFFLED _TIE_fft_FFT_SIMD_STORE_SHUFFLED
#define FFT_SIMD_LOAD _TIE_fft_FFT_SIMD_LOAD
#define FFT_SIMD_STORE _TIE_fft_FFT_SIMD_STORE
#define FFT_SIMD_LOAD_INTERLEAVED _TIE_fft_FFT_SIMD_LOAD_INTERLEAVED
#define FFT_SIMD_STORE_INTERLEAVED _TIE_fft_FFT_SIMD_STORE_INTERLEAVED

#ifndef RUR
#define RUR(NUM) RUR##NUM()
#endif

#ifndef WUR
#define WUR(VAL, NUM) WUR##NUM(VAL)
#endif

#endif /* __XCC__ */

#endif /* __XTENSA__ */

#endif /* !_XTENSA_fft_HEADER */
