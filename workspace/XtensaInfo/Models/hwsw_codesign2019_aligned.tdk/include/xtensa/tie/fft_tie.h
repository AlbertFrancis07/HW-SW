/* Definitions for the fft_tie TIE package */

/*
 * Copyright (c) 2004-2010 by Tensilica Inc.  ALL RIGHTS RESERVED.
 * These coded instructions, statements, and computer programs are the
 * copyrighted works and confidential proprietary information of Tensilica Inc.
 * They may not be modified, copied, reproduced, distributed, or disclosed to
 * third parties in any manner, medium, or form, in whole or in part, without
 * the prior written consent of Tensilica Inc.
 */

/* Do not modify. This is automatically generated.*/

#ifndef _XTENSA_fft_tie_HEADER
#define _XTENSA_fft_tie_HEADER

#ifdef __XTENSA__
#ifdef __XCC__

#include <xtensa/tie/xt_core.h>
#include <xtensa/tie/xt_booleans.h>
typedef _TIE_fft_tie_reg8x16 reg8x16;

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

extern void _TIE_fft_tie_st_reg8x16(reg8x16 a, reg8x16 * b, immediate c);
extern void _TIE_fft_tie_reg8x16_storei(reg8x16 a, reg8x16 * b, immediate c);
extern reg8x16 _TIE_fft_tie_ld_reg8x16(const reg8x16 * b, immediate c);
extern reg8x16 _TIE_fft_tie_reg8x16_loadi(const reg8x16 * b, immediate c);
extern reg8x16 _TIE_fft_tie_mv_reg8x16(reg8x16 b);
extern reg8x16 _TIE_fft_tie_reg8x16_move(reg8x16 b);
extern unsigned _TIE_fft_tie_RUR_REG_K(void);
extern void _TIE_fft_tie_WUR_REG_K(unsigned v);
extern unsigned _TIE_fft_tie_BIT_REVERSE(unsigned d, unsigned size);
extern void _TIE_fft_tie_DIT_FIRST_STAGE(unsigned k, xtbool inverse, xtbool shift, reg8x16 real /*inout*/, reg8x16 imag /*inout*/);
extern void _TIE_fft_tie_DIT_SECOND_STAGE(unsigned k, xtbool inverse, xtbool shift, reg8x16 real /*inout*/, reg8x16 imag /*inout*/);
extern void _TIE_fft_tie_DIT_THIRD_STAGE(unsigned k, xtbool inverse, xtbool shift, reg8x16 real /*inout*/, reg8x16 imag /*inout*/);
extern void _TIE_fft_tie_DIT_CALC_STAGE(reg8x16 real /*inout*/, reg8x16 imag /*inout*/, xtbool shift, unsigned m, xtbool inverse);
extern void _TIE_fft_tie_DIF_FIRST_STAGE(unsigned k, xtbool inverse, xtbool shift, reg8x16 real /*inout*/, reg8x16 imag /*inout*/);
extern void _TIE_fft_tie_DIF_SECOND_STAGE(unsigned k, xtbool inverse, xtbool shift, reg8x16 real /*inout*/, reg8x16 imag /*inout*/);
extern void _TIE_fft_tie_DIF_LAST_STAGE(unsigned k, xtbool inverse, xtbool shift, reg8x16 real /*inout*/, reg8x16 imag /*inout*/);
extern void _TIE_fft_tie_DIF_CALC_STAGE(reg8x16 real /*inout*/, reg8x16 imag /*inout*/, xtbool shift, unsigned m, xtbool inverse);
extern xtbool _TIE_fft_tie_SHIFT_CONDITION(reg8x16 j_vector, reg8x16 m_vector);
extern reg8x16 _TIE_fft_tie_SIMD_LOAD(const void * addr, unsigned offset);
extern void _TIE_fft_tie_SIMD_STORE(void * addr, unsigned offset, reg8x16 data);
extern reg8x16 _TIE_fft_tie_SIMD_LOAD_SHUFFLED(const void * addr, unsigned offset, immediate reverse);
extern void _TIE_fft_tie_SIMD_STORE_SHUFFLED(void * addr, unsigned offset, reg8x16 input, immediate reverse);
extern void _TIE_fft_tie_SIMD_LOAD_INTERLEAVED(const void * addr, unsigned offset, reg8x16 vec1 /*inout*/, reg8x16 vec2 /*inout*/, immediate load_upper);
extern void _TIE_fft_tie_SIMD_STORE_INTERLEAVED(void * addr, unsigned offset, reg8x16 vec1, reg8x16 vec2, immediate store_upper);
#define st_reg8x16 _TIE_fft_tie_st_reg8x16
#define reg8x16_storei _TIE_fft_tie_reg8x16_storei
#define ld_reg8x16 _TIE_fft_tie_ld_reg8x16
#define reg8x16_loadi _TIE_fft_tie_reg8x16_loadi
#define mv_reg8x16 _TIE_fft_tie_mv_reg8x16
#define reg8x16_move _TIE_fft_tie_reg8x16_move
#define RUR_REG_K _TIE_fft_tie_RUR_REG_K
#define RREG_K _TIE_fft_tie_RUR_REG_K
#define RUR0 _TIE_fft_tie_RUR_REG_K
#define WUR_REG_K _TIE_fft_tie_WUR_REG_K
#define WREG_K _TIE_fft_tie_WUR_REG_K
#define WUR0 _TIE_fft_tie_WUR_REG_K
#define BIT_REVERSE _TIE_fft_tie_BIT_REVERSE
#define DIT_FIRST_STAGE _TIE_fft_tie_DIT_FIRST_STAGE
#define DIT_SECOND_STAGE _TIE_fft_tie_DIT_SECOND_STAGE
#define DIT_THIRD_STAGE _TIE_fft_tie_DIT_THIRD_STAGE
#define DIT_CALC_STAGE _TIE_fft_tie_DIT_CALC_STAGE
#define DIF_FIRST_STAGE _TIE_fft_tie_DIF_FIRST_STAGE
#define DIF_SECOND_STAGE _TIE_fft_tie_DIF_SECOND_STAGE
#define DIF_LAST_STAGE _TIE_fft_tie_DIF_LAST_STAGE
#define DIF_CALC_STAGE _TIE_fft_tie_DIF_CALC_STAGE
#define SHIFT_CONDITION _TIE_fft_tie_SHIFT_CONDITION
#define SIMD_LOAD _TIE_fft_tie_SIMD_LOAD
#define SIMD_STORE _TIE_fft_tie_SIMD_STORE
#define SIMD_LOAD_SHUFFLED _TIE_fft_tie_SIMD_LOAD_SHUFFLED
#define SIMD_STORE_SHUFFLED _TIE_fft_tie_SIMD_STORE_SHUFFLED
#define SIMD_LOAD_INTERLEAVED _TIE_fft_tie_SIMD_LOAD_INTERLEAVED
#define SIMD_STORE_INTERLEAVED _TIE_fft_tie_SIMD_STORE_INTERLEAVED

#ifndef RUR
#define RUR(NUM) RUR##NUM()
#endif

#ifndef WUR
#define WUR(VAL, NUM) WUR##NUM(VAL)
#endif

#endif /* __XCC__ */

#endif /* __XTENSA__ */

#endif /* !_XTENSA_fft_tie_HEADER */
