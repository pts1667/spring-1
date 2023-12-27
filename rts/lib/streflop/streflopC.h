/* Copyright (C) 2009 Tobi Vollebregt */

/*
	Serves as a C compatible interface to the most basic streflop functions.
*/

#ifndef STREFLOP_C_H
#define STREFLOP_C_H

#ifndef StreflopSimple
	#define StreflopSimple float
	#define StreflopDouble double
#endif

#ifdef __cplusplus
extern "C" {
#endif

enum
{
	STREFLOP_FP_NAN = 0,
	STREFLOP_FP_INFINITE = 1,
	STREFLOP_FP_ZERO = 2,
	STREFLOP_FP_SUBNORMAL = 3,
	STREFLOP_FP_NORMAL = 4
};

/// Initializes the FPU to single precision
void streflop_init_Simple();

/// Initializes the FPU to double precision
void streflop_init_Double();

StreflopSimple sqrtf(StreflopSimple x);
StreflopSimple cbrtf(StreflopSimple x);
StreflopSimple hypotf(StreflopSimple x, StreflopSimple y);

StreflopSimple expf(StreflopSimple x);
StreflopSimple logf(StreflopSimple x);
StreflopSimple log2f(StreflopSimple x);
StreflopSimple exp2f(StreflopSimple x);
StreflopSimple log10f(StreflopSimple x);
StreflopSimple powf(StreflopSimple x, StreflopSimple y);

StreflopSimple sinf(StreflopSimple x);
StreflopSimple cosf(StreflopSimple x);
StreflopSimple tanf(StreflopSimple x);
StreflopSimple acosf(StreflopSimple x);
StreflopSimple asinf(StreflopSimple x);
StreflopSimple atanf(StreflopSimple x);
StreflopSimple atan2f(StreflopSimple x, StreflopSimple y);

StreflopSimple coshf(StreflopSimple x);
StreflopSimple sinhf(StreflopSimple x);
StreflopSimple tanhf(StreflopSimple x);
StreflopSimple acoshf(StreflopSimple x);
StreflopSimple asinhf(StreflopSimple x);
StreflopSimple atanhf(StreflopSimple x);

StreflopSimple fabsf(StreflopSimple x);
StreflopSimple floorf(StreflopSimple x);
StreflopSimple ceilf(StreflopSimple x);
StreflopSimple truncf(StreflopSimple x);
StreflopSimple fmodf(StreflopSimple x, StreflopSimple y);
StreflopSimple remainderf(StreflopSimple x, StreflopSimple y);
StreflopSimple remquof(StreflopSimple x, StreflopSimple y, int *quo);
StreflopSimple rintf(StreflopSimple x);
long int lrintf(StreflopSimple x);
long long int llrintf(StreflopSimple x);
StreflopSimple roundf(StreflopSimple x);
long int lroundf(StreflopSimple x);
long long int llroundf(StreflopSimple x);
StreflopSimple nearbyintf(StreflopSimple x);

StreflopSimple frexpf(StreflopSimple x, int *exp);
StreflopSimple ldexpf(StreflopSimple value, int exp);
StreflopSimple logbf(StreflopSimple x);
int ilogbf(StreflopSimple x);
StreflopSimple copysignf(StreflopSimple x, StreflopSimple y);
int signbitf(StreflopSimple x);
StreflopSimple nextafterf(StreflopSimple x, StreflopSimple y);

StreflopSimple expm1f(StreflopSimple x);
StreflopSimple log1pf(StreflopSimple x);
StreflopSimple erff(StreflopSimple x);
StreflopSimple j0f(StreflopSimple x);
StreflopSimple j1f(StreflopSimple x);
StreflopSimple jnf(int n, StreflopSimple x);
StreflopSimple y0f(StreflopSimple x);
StreflopSimple y1f(StreflopSimple x);
StreflopSimple ynf(int n, StreflopSimple x);
StreflopSimple scalbnf(StreflopSimple x, int n);
StreflopSimple scalblnf(StreflopSimple x, long int n);

int fpclassifyf(StreflopSimple x);
int isnanf(StreflopSimple x);
int isinff(StreflopSimple x);
int isfinitef(StreflopSimple x);
int isnormalf(StreflopSimple x);

int isunorderedf(StreflopSimple x, StreflopSimple y);
int isgreaterf(StreflopSimple x, StreflopSimple y);
int isgreaterequalf(StreflopSimple x, StreflopSimple y);
int islessf(StreflopSimple x, StreflopSimple y);
int islessequalf(StreflopSimple x, StreflopSimple y);
int islessgreaterf(StreflopSimple x, StreflopSimple y);

#define WRAP_DBL_STREFLOP_FUNC_N_DECL(func) StreflopDouble func(StreflopDouble x)
#define WRAP_DBL_STREFLOP_FUNC_NN_DECL(func) StreflopDouble func(StreflopDouble x, StreflopDouble y)

#define WRAP_DBL_STREFLOP_FUNC_N_INT_DECL(func) int func(StreflopDouble x)

WRAP_DBL_STREFLOP_FUNC_N_DECL(sqrt);
WRAP_DBL_STREFLOP_FUNC_N_DECL(cbrt);
WRAP_DBL_STREFLOP_FUNC_NN_DECL(hypot);

WRAP_DBL_STREFLOP_FUNC_N_DECL(exp);
WRAP_DBL_STREFLOP_FUNC_N_DECL(log);
WRAP_DBL_STREFLOP_FUNC_N_DECL(log2);
WRAP_DBL_STREFLOP_FUNC_N_DECL(exp2);
WRAP_DBL_STREFLOP_FUNC_N_DECL(log10);
WRAP_DBL_STREFLOP_FUNC_NN_DECL(pow);

WRAP_DBL_STREFLOP_FUNC_N_DECL(sin);
WRAP_DBL_STREFLOP_FUNC_N_DECL(cos);
WRAP_DBL_STREFLOP_FUNC_N_DECL(tan);
WRAP_DBL_STREFLOP_FUNC_N_DECL(acos);
WRAP_DBL_STREFLOP_FUNC_N_DECL(asin);
WRAP_DBL_STREFLOP_FUNC_N_DECL(atan);
WRAP_DBL_STREFLOP_FUNC_NN_DECL(atan2);

WRAP_DBL_STREFLOP_FUNC_N_DECL(cosh);
WRAP_DBL_STREFLOP_FUNC_N_DECL(sinh);
WRAP_DBL_STREFLOP_FUNC_N_DECL(tanh);
WRAP_DBL_STREFLOP_FUNC_N_DECL(acosh);
WRAP_DBL_STREFLOP_FUNC_N_DECL(asinh);
WRAP_DBL_STREFLOP_FUNC_N_DECL(atanh);

WRAP_DBL_STREFLOP_FUNC_N_DECL(fabs);
WRAP_DBL_STREFLOP_FUNC_N_DECL(floor);
WRAP_DBL_STREFLOP_FUNC_N_DECL(ceil);
WRAP_DBL_STREFLOP_FUNC_N_DECL(trunc);
WRAP_DBL_STREFLOP_FUNC_NN_DECL(fmod);
WRAP_DBL_STREFLOP_FUNC_NN_DECL(remainder);

StreflopDouble remquo(StreflopDouble x, StreflopDouble y, int *quo);

WRAP_DBL_STREFLOP_FUNC_N_DECL(rint);
WRAP_DBL_STREFLOP_FUNC_N_DECL(round);
WRAP_DBL_STREFLOP_FUNC_N_DECL(nearbyint);

StreflopDouble frexp(StreflopDouble x, int *exp);
StreflopDouble ldexp(StreflopDouble x, int exp);

WRAP_DBL_STREFLOP_FUNC_N_DECL(logb);
WRAP_DBL_STREFLOP_FUNC_N_INT_DECL(ilogb);
WRAP_DBL_STREFLOP_FUNC_NN_DECL(copysign);
WRAP_DBL_STREFLOP_FUNC_N_INT_DECL(signbit);

int fpclassify(StreflopDouble x);
int isnan(StreflopDouble x);
int isinf(StreflopDouble x);
inline int isfinite(StreflopDouble x);

// Stolen from math.h and inlined instead of macroized.
// Return nonzero value if X is neither zero, subnormal, Inf, nor NaN.  */
inline int isnormal(StreflopDouble x);

/** Generic C99 "macros" for unordered comparison
	Defined as inlined for each type, thanks to C++ overloading
*/
inline int isunordered(StreflopDouble x, StreflopDouble y);
inline int isgreater(StreflopDouble x, StreflopDouble y);
inline int isgreaterequal(StreflopDouble x, StreflopDouble y);
inline int isless(StreflopDouble x, StreflopDouble y);
inline int islessequal(StreflopDouble x, StreflopDouble y);
inline int islessgreater(StreflopDouble x, StreflopDouble y);

#ifdef __cplusplus
} // extern "C"
#endif

#endif // STREFLOP_C_H
