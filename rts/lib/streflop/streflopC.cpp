/* Copyright (C) 2009 Tobi Vollebregt */

#include "streflopC.h"

#include "streflop_cond.h"

#ifdef __cplusplus
extern "C" {
#endif

void streflop_init_Simple() {
	streflop::streflop_init<streflop::Simple>();
}

void streflop_init_Double() {
	streflop::streflop_init<streflop::Double>();
}

inline StreflopSimple sqrtf(StreflopSimple x) {return math::sqrtf(x);}
inline StreflopSimple cbrtf(StreflopSimple x) {return math::cbrtf(x);}
inline StreflopSimple hypotf(StreflopSimple x, StreflopSimple y) {return streflop_libm::__ieee754_hypotf(x,y);}

inline StreflopSimple expf(StreflopSimple x) {return math::expf(x);}
inline StreflopSimple logf(StreflopSimple x) {return math::logf(x);}
inline StreflopSimple log2f(StreflopSimple x) {return math::log2f(x);}
inline StreflopSimple exp2f(StreflopSimple x) {return math::exp2f(x);}
inline StreflopSimple log10f(StreflopSimple x) {return math::log10f(x);}
inline StreflopSimple powf(StreflopSimple x, StreflopSimple y) {return streflop_libm::__ieee754_powf(x,y);}

inline StreflopSimple sinf(StreflopSimple x) {return math::sinf(x);}
inline StreflopSimple cosf(StreflopSimple x) {return math::cosf(x);}
inline StreflopSimple tanf(StreflopSimple x) {return math::tanf(x);}
inline StreflopSimple acosf(StreflopSimple x) {return math::acosf(x);}
inline StreflopSimple asinf(StreflopSimple x) {return math::asinf(x);}
inline StreflopSimple atanf(StreflopSimple x) {return math::atanf(x);}
inline StreflopSimple atan2f(StreflopSimple x, StreflopSimple y) {return math::atan2f(x,y);}

inline StreflopSimple coshf(StreflopSimple x) {return math::coshf(x);}
inline StreflopSimple sinhf(StreflopSimple x) {return math::sinhf(x);}
inline StreflopSimple tanhf(StreflopSimple x) {return math::tanhf(x);}
inline StreflopSimple acoshf(StreflopSimple x) {return math::acoshf(x);}
inline StreflopSimple asinhf(StreflopSimple x) {return math::asinhf(x);}
inline StreflopSimple atanhf(StreflopSimple x) {return math::atanhf(x);}

inline StreflopSimple fabsf(StreflopSimple x) {return math::fabsf(x);}
inline StreflopSimple floorf(StreflopSimple x) {return math::floorf(x);}
inline StreflopSimple ceilf(StreflopSimple x) {return math::ceilf(x);}
inline StreflopSimple truncf(StreflopSimple x) {return math::truncf(x);}
inline StreflopSimple fmodf(StreflopSimple x, StreflopSimple y) {return math::fmodf(x,y);}
inline StreflopSimple remainderf(StreflopSimple x, StreflopSimple y) {return math::remainderf(x,y);}
inline StreflopSimple remquof(StreflopSimple x, StreflopSimple y, int *quo) {return math::remquof(x,y,quo);}
inline StreflopSimple rintf(StreflopSimple x) {return math::rintf(x);}
inline long int lrintf(StreflopSimple x) {return math::lrintf(x);}
inline long long int llrintf(StreflopSimple x) {return math::llrintf(x);}
inline StreflopSimple roundf(StreflopSimple x) {return math::roundf(x);}
inline long int lroundf(StreflopSimple x) {return math::lroundf(x);}
inline long long int llroundf(StreflopSimple x) {return math::llroundf(x);}
inline StreflopSimple nearbyintf(StreflopSimple x) {return math::nearbyintf(x);}

inline StreflopSimple frexpf(StreflopSimple x, int *exp) {return math::frexpf(x,exp);}
inline StreflopSimple ldexpf(StreflopSimple value, int exp) {return math::ldexpf(value,exp);}
inline StreflopSimple logbf(StreflopSimple x) {return math::logbf(x);}
inline int ilogbf(StreflopSimple x) {return math::ilogbf(x);}
inline StreflopSimple copysignf(StreflopSimple x, StreflopSimple y) {return math::copysignf(x,y);}
inline int signbitf(StreflopSimple x) {return math::signbitf(x);}
inline StreflopSimple nextafter(StreflopSimple x, StreflopSimple y) {return math::nextafterf(x,y);}

inline StreflopSimple expm1(StreflopSimple x) {return math::expm1f(x);}
inline StreflopSimple log1p(StreflopSimple x) {return math::log1pf(x);}
inline StreflopSimple erf(StreflopSimple x) {return math::erff(x);}
inline StreflopSimple j0(StreflopSimple x) {return math::j0f(x);}
inline StreflopSimple j1(StreflopSimple x) {return math::j1f(x);}
inline StreflopSimple jn(int n, StreflopSimple x) {return math::jnf(n,x);}
inline StreflopSimple y0(StreflopSimple x) {return math::y0f(x);}
inline StreflopSimple y1(StreflopSimple x) {return math::y1f(x);}
inline StreflopSimple yn(int n, StreflopSimple x) {return math::ynf(n,x);}
inline StreflopSimple scalbn(StreflopSimple x, int n) {return math::scalbnf(x,n);}
inline StreflopSimple scalbln(StreflopSimple x, long int n) {return math::scalblnf(x,n);}

#define WRAP_DBL_STREFLOP_FUNC_N(func) StreflopDouble func(StreflopDouble x) { \
	streflop_init_Simple(); \
	StreflopSimple res; \
	res = func##f(x); \
	streflop_init_Double(); \
	return (StreflopDouble)res; \
}

#define WRAP_DBL_STREFLOP_FUNC_NN(func) StreflopDouble func(StreflopDouble x, StreflopDouble y) { \
	streflop_init_Simple(); \
	StreflopSimple res; \
	res = func##f(x, y); \
	streflop_init_Double(); \
	return (StreflopDouble)res; \
}

#define WRAP_DBL_STREFLOP_FUNC_N_INT(func) int func(StreflopDouble x) { \
	streflop_init_Simple(); \
	int res; \
	res = func##f(x); \
	streflop_init_Double(); \
	return res; \
}

WRAP_DBL_STREFLOP_FUNC_N(sqrt);
WRAP_DBL_STREFLOP_FUNC_N(cbrt);
WRAP_DBL_STREFLOP_FUNC_NN(hypot);

WRAP_DBL_STREFLOP_FUNC_N(exp);
WRAP_DBL_STREFLOP_FUNC_N(log);
WRAP_DBL_STREFLOP_FUNC_N(log2);
WRAP_DBL_STREFLOP_FUNC_N(exp2);
WRAP_DBL_STREFLOP_FUNC_N(log10);
WRAP_DBL_STREFLOP_FUNC_NN(pow);

WRAP_DBL_STREFLOP_FUNC_N(sin);
WRAP_DBL_STREFLOP_FUNC_N(cos);
WRAP_DBL_STREFLOP_FUNC_N(tan);
WRAP_DBL_STREFLOP_FUNC_N(acos);
WRAP_DBL_STREFLOP_FUNC_N(asin);
WRAP_DBL_STREFLOP_FUNC_N(atan);
WRAP_DBL_STREFLOP_FUNC_NN(atan2);

WRAP_DBL_STREFLOP_FUNC_N(cosh);
WRAP_DBL_STREFLOP_FUNC_N(sinh);
WRAP_DBL_STREFLOP_FUNC_N(tanh);
WRAP_DBL_STREFLOP_FUNC_N(acosh);
WRAP_DBL_STREFLOP_FUNC_N(asinh);
WRAP_DBL_STREFLOP_FUNC_N(atanh);

WRAP_DBL_STREFLOP_FUNC_N(fabs);
WRAP_DBL_STREFLOP_FUNC_N(floor);
WRAP_DBL_STREFLOP_FUNC_N(ceil);
WRAP_DBL_STREFLOP_FUNC_N(trunc);
WRAP_DBL_STREFLOP_FUNC_NN(fmod);
WRAP_DBL_STREFLOP_FUNC_NN(remainder);

StreflopDouble remquo(StreflopDouble x, StreflopDouble y, int *quo) {
	streflop_init_Simple();
	StreflopSimple res;
	res = remquof((StreflopSimple)x, (StreflopSimple)y, quo);
	streflop_init_Double();
	return (StreflopDouble)res;
}

WRAP_DBL_STREFLOP_FUNC_N(rint);
WRAP_DBL_STREFLOP_FUNC_N(round);
WRAP_DBL_STREFLOP_FUNC_N(nearbyint);

StreflopDouble frexp(StreflopDouble x, int *exp) {
	streflop_init_Simple();
	StreflopSimple res;
	res = frexpf((StreflopSimple)x, exp);
	streflop_init_Double();
	return (StreflopDouble)res;
}

StreflopDouble ldexp(StreflopDouble x, int exp) {
	streflop_init_Simple();
	StreflopSimple res;
	res = ldexpf((StreflopSimple)x, exp);
	streflop_init_Double();
	return (StreflopDouble)res;
}

WRAP_DBL_STREFLOP_FUNC_N(logb);
WRAP_DBL_STREFLOP_FUNC_N_INT(ilogb);
WRAP_DBL_STREFLOP_FUNC_NN(copysign);
WRAP_DBL_STREFLOP_FUNC_N_INT(signbit);

union StreflopIEEd2bits {
	double d;
	struct {
		unsigned int manl :32;
		unsigned int manh :20;
		unsigned int exp :11;
		unsigned int sign :1;
	} bits;
};

int fpclassify(StreflopDouble x) {
	union StreflopIEEd2bits u;
	u.d = x;
	if (u.bits.exp == 0) {
		if ((u.bits.manl | u.bits.manh) == 0)
			return STREFLOP_FP_ZERO;
		
		return STREFLOP_FP_SUBNORMAL;
	}

	if (u.bits.exp == 2047) {
		if ((u.bits.manl | u.bits.manh) == 0)
			return STREFLOP_FP_INFINITE;
		
		return STREFLOP_FP_NAN;
	}

	return STREFLOP_FP_NORMAL;
};

int isnan(StreflopDouble x) {
	union StreflopIEEd2bits u;
	u.d = x;

	return (u.bits.exp == 2047 && ((u.bits.manl | u.bits.manh) != 0));
};

int isinf(StreflopDouble x) {
	union StreflopIEEd2bits u;
	u.d = x;

	return (u.bits.exp == 2047 && ((u.bits.manl | u.bits.manh) == 0));
};

inline int isfinite(StreflopDouble x) {return !(isnan(x) || isinf(x));}

// Stolen from math.h and inlined instead of macroized.
// Return nonzero value if X is neither zero, subnormal, Inf, nor NaN.  */
inline int isnormal(StreflopDouble x) {return fpclassify(x) == STREFLOP_FP_NORMAL;}

/** Generic C99 "macros" for unordered comparison
	Defined as inlined for each type, thanks to C++ overloading
*/
inline int isunordered(StreflopDouble x, StreflopDouble y) {
	return (fpclassify(x) == STREFLOP_FP_NAN) || (fpclassify (y) == STREFLOP_FP_NAN);
}
inline int isgreater(StreflopDouble x, StreflopDouble y) {
	return (!isunordered(x,y)) && (x > y);
}
inline int isgreaterequal(StreflopDouble x, StreflopDouble y) {
	return (!isunordered(x,y)) && (x >= y);
}
inline int isless(StreflopDouble x, StreflopDouble y) {
	return (!isunordered(x,y)) && (x < y);
}
inline int islessequal(StreflopDouble x, StreflopDouble y) {
	return (!isunordered(x,y)) && (x <= y);
}
inline int islessgreater(StreflopDouble x, StreflopDouble y) {
	return (!isunordered(x,y)) && ((x < y) || (x > y));
}

#ifdef __cplusplus
} // extern "C"
#endif
