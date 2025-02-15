/* See the import.pl script for potential modifications */
/* e_log10f.c -- StreflopSimple version of e_log10.c.
 * Conversion to StreflopSimple by Ian Lance Taylor, Cygnus Support, ian@cygnus.com.
 */

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

#if defined(LIBM_SCCS) && !defined(lint)
static char rcsid[] = "$NetBSD: e_log10f.c,v 1.5f 1995/05/10 20:45:53 jtc Exp $";
#endif

#include "SMath.h"
#include "math_private.h"

namespace streflop_libm {
#ifdef __STDC__
static const Simple
#else
static Simple
#endif
two25      =  3.3554432000e+07f, /* 0x4c000000 */
ivln10     =  4.3429449201e-01f, /* 0x3ede5bd9 */
log10_2hi  =  3.0102920532e-01f, /* 0x3e9a2080 */
log10_2lo  =  7.9034151668e-07f; /* 0x355427db */

#ifdef __STDC__
static const StreflopSimple zero   =  0.0f;
#else
static StreflopSimple zero   =  0.0f;
#endif

#ifdef __STDC__
	StreflopSimple __ieee754_log10f(StreflopSimple x)
#else
	StreflopSimple __ieee754_log10f(x)
	StreflopSimple x;
#endif
{
	StreflopSimple y,z;
	int32_t i,k,hx;

	GET_FLOAT_WORD(hx,x);

        k=0;
        if (hx < 0x00800000) {			/* x < 2**-126  */
            if ((hx&0x7fffffff)==0)
                return -two25/(x-x);		/* log(+-0)=-inf */
            if (hx<0) return (x-x)/(x-x);	/* log(-#) = NaN */
            k -= 25; x *= two25; /* subnormal number, scale up x */
	    GET_FLOAT_WORD(hx,x);
        }
	if (hx >= 0x7f800000) return x+x;
	k += (hx>>23)-127;
	i  = ((u_int32_t)k&0x80000000)>>31;
        hx = (hx&0x007fffff)|((0x7f-i)<<23);
        y  = (Simple)(k+i);
	SET_FLOAT_WORD(x,hx);
	z  = y*log10_2lo + ivln10*__ieee754_logf(x);
	return  z+y*log10_2hi;
}
}
