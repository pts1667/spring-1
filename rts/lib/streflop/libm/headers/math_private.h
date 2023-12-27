/* See the import.pl script for potential modifications */
/*
 * ====================================================
 * Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.
 *
 * Developed at SunPro, a Sun Microsystems, Inc. business.
 * Permission to use, copy, modify, and distribute this
 * software is freely granted, provided that this notice
 * is preserved.
 * ====================================================
 */

/*
 * from: @(#)fdlibm.h 5.1 93/09/24
 */

#ifndef _MATH_PRIVATE_H_
#define _MATH_PRIVATE_H_

/* import.pl: Skipped the macro definitions, keep only the declarations, converted to use streflop types (aliases or wrappers) */
#include "../streflop_libm_bridge.h"

namespace streflop_libm {

#ifdef LIBM_COMPILING_FLT32
#define __sqrtf __ieee754_sqrtf
#define fabsf __fabsf
#define copysignf __copysignf
extern StreflopSimple __log1pf(StreflopSimple x);
extern StreflopSimple __fabsf(StreflopSimple x);
extern StreflopSimple __atanf(StreflopSimple x);
extern StreflopSimple __expm1f(StreflopSimple x);
extern int __isinff(StreflopSimple x);
extern StreflopSimple __rintf(StreflopSimple x);
extern StreflopSimple __cosf(StreflopSimple x);
extern void __sincosf (StreflopSimple x, StreflopSimple *sinx, StreflopSimple *cosx);
extern StreflopSimple __floorf(StreflopSimple x);
extern StreflopSimple __scalbnf (StreflopSimple x, int n);
extern StreflopSimple __frexpf(StreflopSimple x, int *eptr);
extern StreflopSimple __ldexpf(StreflopSimple value, int exp);
extern int __finitef(StreflopSimple x);
#endif

#ifdef LIBM_COMPILING_DBL64
#define __sqrt __ieee754_sqrt
#define fabs __fabs
#define copysign __copysign
extern Double __log1p(Double x);
extern Double __fabs(Double x);
extern Double atan(Double x);
extern Double __expm1(Double x);
extern int __isinf(Double x);
extern Double __rint(Double x);
extern Double __cos(Double x);
extern void __sincos (Double x, Double *sinx, Double *cosx);
extern Double __floor(Double x);
extern Double __scalbn(Double x, int n);
extern Double __frexp(Double x, int *eptr);
extern Double __ldexp(Double value, int exp);
extern int __finite(Double x);
#endif

#ifdef LIBM_COMPILING_LDBL96
#if defined(Extended)
#define fabsl __fabsl
extern Extended __cosl(Extended x);
extern Extended __sinl(Extended x);
extern Extended __fabsl(Extended x);
#endif
#endif

#ifdef LIBM_COMPILING_DBL64
extern Double __ieee754_sqrt (Double);
extern Double __ieee754_acos (Double);
extern Double __ieee754_acosh (Double);
extern Double __ieee754_log (Double);
extern Double __ieee754_atanh (Double);
extern Double __ieee754_asin (Double);
extern Double __ieee754_atan2 (Double,Double);
extern Double __ieee754_exp (Double);
extern Double __ieee754_exp2 (Double);
extern Double __ieee754_exp10 (Double);
extern Double __ieee754_cosh (Double);
extern Double __ieee754_fmod (Double,Double);
extern Double __ieee754_pow (Double,Double);
extern Double __ieee754_lgamma_r (Double,int *);
extern Double __ieee754_gamma_r (Double,int *);
extern Double __ieee754_lgamma (Double);
extern Double __ieee754_gamma (Double);
extern Double __ieee754_log10 (Double);
extern Double __ieee754_log2 (Double);
extern Double __ieee754_sinh (Double);
extern Double __ieee754_hypot (Double,Double);
extern Double __ieee754_j0 (Double);
extern Double __ieee754_j1 (Double);
extern Double __ieee754_y0 (Double);
extern Double __ieee754_y1 (Double);
extern Double __ieee754_jn (int,Double);
extern Double __ieee754_yn (int,Double);
extern Double __ieee754_remainder (Double,Double);
extern int32_t __ieee754_rem_pio2 (Double,Double*);
extern Double __ieee754_scalb (Double,Double);
#endif

/* fdlibm kernel function */
#ifdef LIBM_COMPILING_DBL64
extern Double __kernel_standard (Double,Double,int);
extern Double __kernel_sin (Double,Double,int);
extern Double __kernel_cos (Double,Double);
extern Double __kernel_tan (Double,Double,int);
extern int    __kernel_rem_pio2 (Double*,Double*,int,int,int, const int32_t*);
#endif

/* internal functions.  */
#ifdef LIBM_COMPILING_DBL64
extern Double __copysign (Double x, Double __y);
#endif

#if 0
#ifdef LIBM_COMPILING_DBL64
extern inline Double __copysign (Double x, Double y)
{ return __builtin_copysign (x, y); }
#endif
#endif

/* ieee style elementary StreflopSimple functions */
#ifdef LIBM_COMPILING_FLT32
extern StreflopSimple __ieee754_sqrtf (Simple);
extern StreflopSimple __ieee754_acosf (Simple);
extern StreflopSimple __ieee754_acoshf (Simple);
extern StreflopSimple __ieee754_logf (Simple);
extern StreflopSimple __ieee754_atanhf (Simple);
extern StreflopSimple __ieee754_asinf (Simple);
extern StreflopSimple __ieee754_atan2f (Simple,Simple);
extern StreflopSimple __ieee754_expf (Simple);
extern StreflopSimple __ieee754_exp2f (Simple);
extern StreflopSimple __ieee754_exp10f (Simple);
extern StreflopSimple __ieee754_coshf (Simple);
extern StreflopSimple __ieee754_fmodf (Simple,Simple);
extern StreflopSimple __ieee754_powf (Simple,Simple);
extern StreflopSimple __ieee754_lgammaf_r (Simple,int *);
extern StreflopSimple __ieee754_gammaf_r (Simple,int *);
extern StreflopSimple __ieee754_lgammaf (Simple);
extern StreflopSimple __ieee754_gammaf (Simple);
extern StreflopSimple __ieee754_log10f (Simple);
extern StreflopSimple __ieee754_log2f (Simple);
extern StreflopSimple __ieee754_sinhf (Simple);
extern StreflopSimple __ieee754_hypotf (Simple,Simple);
extern StreflopSimple __ieee754_j0f (Simple);
extern StreflopSimple __ieee754_j1f (Simple);
extern StreflopSimple __ieee754_y0f (Simple);
extern StreflopSimple __ieee754_y1f (Simple);
extern StreflopSimple __ieee754_jnf (int,Simple);
extern StreflopSimple __ieee754_ynf (int,Simple);
extern StreflopSimple __ieee754_remainderf (Simple,Simple);
extern int32_t __ieee754_rem_pio2f (Simple,Simple*);
extern StreflopSimple __ieee754_scalbf (Simple,Simple);
#endif


/* StreflopSimple versions of fdlibm kernel functions */
#ifdef LIBM_COMPILING_FLT32
extern StreflopSimple __kernel_sinf (Simple,Simple,int);
extern StreflopSimple __kernel_cosf (Simple,Simple);
extern StreflopSimple __kernel_tanf (Simple,Simple,int);
extern int   __kernel_rem_pio2f (Simple*,Simple*,int,int,int, const int32_t*);
#endif

/* internal functions.  */
#ifdef LIBM_COMPILING_FLT32
extern StreflopSimple __copysignf (StreflopSimple x, StreflopSimple __y);
#endif

#if 0
#ifdef LIBM_COMPILING_FLT32
extern inline StreflopSimple __copysignf (StreflopSimple x, StreflopSimple y)
{ return __builtin_copysignf (x, y); }
#endif
#endif

#if defined(Extended)
/* ieee style elementary Extended functions */
#ifdef LIBM_COMPILING_LDBL96
extern Extended __ieee754_sqrtl (Extended);
extern Extended __ieee754_acosl (Extended);
extern Extended __ieee754_acoshl (Extended);
extern Extended __ieee754_logl (Extended);
extern Extended __ieee754_atanhl (Extended);
extern Extended __ieee754_asinl (Extended);
extern Extended __ieee754_atan2l (Extended,Extended);
extern Extended __ieee754_expl (Extended);
extern Extended __ieee754_exp2l (Extended);
extern Extended __ieee754_exp10l (Extended);
extern Extended __ieee754_coshl (Extended);
extern Extended __ieee754_fmodl (Extended,Extended);
extern Extended __ieee754_powl (Extended,Extended);
extern Extended __ieee754_lgammal_r (Extended,int *);
extern Extended __ieee754_gammal_r (Extended,int *);
extern Extended __ieee754_lgammal (Extended);
extern Extended __ieee754_gammal (Extended);
extern Extended __ieee754_log10l (Extended);
extern Extended __ieee754_log2l (Extended);
extern Extended __ieee754_sinhl (Extended);
extern Extended __ieee754_hypotl (Extended,Extended);
extern Extended __ieee754_j0l (Extended);
extern Extended __ieee754_j1l (Extended);
extern Extended __ieee754_y0l (Extended);
extern Extended __ieee754_y1l (Extended);
extern Extended __ieee754_jnl (int,Extended);
extern Extended __ieee754_ynl (int,Extended);
extern Extended __ieee754_remainderl (Extended,Extended);
extern int   __ieee754_rem_pio2l (Extended,Extended*);
extern Extended __ieee754_scalbl (Extended,Extended);
#endif

/* Extended versions of fdlibm kernel functions */
#ifdef LIBM_COMPILING_LDBL96
extern Extended __kernel_sinl (Extended,Extended,int);
extern Extended __kernel_cosl (Extended,Extended);
extern Extended __kernel_tanl (Extended,Extended,int);
extern void __kernel_sincosl (Extended,Extended,
			      Extended *,Extended *, int);
extern int   __kernel_rem_pio2l (Extended*,Extended*,int,int,
				 int,const int*);
#endif

#ifndef NO_LONG_DOUBLE
/* prototypes required to compile the ldbl-96 support without warnings */
#ifdef LIBM_COMPILING_LDBL96
extern int __finitel (Extended);
extern int __ilogbl (Extended);
extern int __isinfl (Extended);
extern int __isnanl (Extended);
extern Extended __atanl (Extended);
extern Extended __copysignl (Extended, Extended);
extern Extended __expm1l (Extended);
extern Extended __floorl (Extended);
extern Extended __frexpl (Extended, int *);
extern Extended __ldexpl (Extended, int);
extern Extended __log1pl (Extended);
extern Extended __nanl (const char *);
extern Extended __rintl (Extended);
extern Extended __scalbnl (Extended, int);
extern Extended __sqrtl (Extended x);
extern Extended fabsl (Extended x);
extern void __sincosl (Extended, Extended *, Extended *);
extern Extended __logbl (Extended x);
extern Extended __significandl (Extended x);
#endif

#if 0
#ifdef LIBM_COMPILING_LDBL96
extern inline Extended __copysignl (Extended x, Extended y)
{ return __builtin_copysignl (x, y); }
#endif
#endif

#endif

#endif

/* Prototypes for functions of the IBM Accurate Mathematical Library.  */
#ifdef LIBM_COMPILING_DBL64
extern Double __exp1 (Double __x, Double __xx, Double __error);
extern Double __sin (Double __x);
extern Double __cos (Double __x);
extern int __branred (Double __x, Double *__a, Double *__aa);
extern void __doasin (Double __x, Double __dx, Double __v[]);
extern void __dubsin (Double __x, Double __dx, Double __v[]);
extern void __dubcos (Double __x, Double __dx, Double __v[]);
extern Double __halfulp (Double __x, Double __y);
extern Double __sin32 (Double __x, Double __res, Double __res1);
extern Double __cos32 (Double __x, Double __res, Double __res1);
extern Double __mpsin (Double __x, Double __dx);
extern Double __mpcos (Double __x, Double __dx);
extern Double __mpsin1 (Double __x);
extern Double __mpcos1 (Double __x);
extern Double __slowexp (Double __x);
extern Double __slowpow (Double __x, Double __y, Double __z);
extern void __docos (Double __x, Double __dx, Double __v[]);
#endif

}

#endif /* _MATH_PRIVATE_H_ */
