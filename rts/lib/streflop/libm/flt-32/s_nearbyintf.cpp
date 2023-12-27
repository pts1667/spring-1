/* See the import.pl script for potential modifications */
/* s_rintf.c -- StreflopSimple version of s_rint.c.
 * Conversion to StreflopSimple by Ian Lance Taylor, Cygnus Support, ian@cygnus.com.
 */
/* Adapted for use as nearbyint by Ulrich Drepper <drepper@cygnus.com>.  */

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


#include "../streflop_libm_bridge.h"
#include "SMath.h"
#include "math_private.h"

namespace streflop_libm {
#ifdef __STDC__
static const Simple
#else
static Simple
#endif
TWO23[2]={
  8.3886080000e+06f, /* 0x4b000000 */
 -8.3886080000e+06f, /* 0xcb000000 */
};

#ifdef __STDC__
	StreflopSimple __nearbyintf(StreflopSimple x)
#else
	StreflopSimple __nearbyintf(x)
	StreflopSimple x;
#endif
{
	fpenv_t env;
	int32_t i0,j0,sx;
	u_int32_t i,i1;
	StreflopSimple w,t;
	GET_FLOAT_WORD(i0,x);
	sx = (i0>>31)&1;
	j0 = ((i0>>23)&0xff)-0x7f;
	if(j0<23) {
	    if(j0<0) {
		if((i0&0x7fffffff)==0) return x;
		i1 = (i0&0x07fffff);
		i0 &= 0xfff00000;
		i0 |= ((i1|-i1)>>9)&0x400000;
		SET_FLOAT_WORD(x,i0);
		feholdexcept (&env);
	        w = TWO23[sx]+x;
	        t =  w-TWO23[sx];
		fesetenv (&env);
		GET_FLOAT_WORD(i0,t);
		SET_FLOAT_WORD(t,(i0&0x7fffffff)|(sx<<31));
	        return t;
	    } else {
		i = (0x007fffff)>>j0;
		if((i0&i)==0) return x; /* x is integral */
		i>>=1;
		if((i0&i)!=0) i0 = (i0&(~i))|((0x100000)>>j0);
	    }
	} else {
	    if(j0==0x80) return x+x;	/* inf or NaN */
	    else return x;		/* x is integral */
	}
	SET_FLOAT_WORD(x,i0);
	feholdexcept (&env);
	w = TWO23[sx]+x;
	t = w-TWO23[sx];
	fesetenv (&env);
	return t;
}
weak_alias (__nearbyintf, nearbyintf)
}
