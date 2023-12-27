// Includes Math.h in turn
#include "streflop.h"

namespace streflop {

    // Constants

    const StreflopSimple SimpleZero(0.0f);
    const StreflopSimple SimplePositiveInfinity = Simple(1.0f) / SimpleZero;
    const StreflopSimple SimpleNegativeInfinity = Simple(-1.0f) / SimpleZero;
    // TODO: non-signaling version
    const StreflopSimple SimpleNaN = SimplePositiveInfinity + SimpleNegativeInfinity;

    const StreflopDouble DoubleZero(0.0f);
    const StreflopDouble DoublePositiveInfinity = Double(1.0f) / DoubleZero;
    const StreflopDouble DoubleNegativeInfinity = Double(-1.0f) / DoubleZero;
    // TODO: non-signaling version
    const StreflopDouble DoubleNaN = DoublePositiveInfinity + DoubleNegativeInfinity;

// Extended are not always available
#ifdef Extended

    const Extended ExtendedZero(0.0f);
    const Extended ExtendedPositiveInfinity = Extended(1.0f) / ExtendedZero;
    const Extended ExtendedNegativeInfinity = Extended(-1.0f) / ExtendedZero;
    // TODO: non-signaling version
    const Extended ExtendedNaN = ExtendedPositiveInfinity + ExtendedNegativeInfinity;

#endif



    // Default environment. Initialized to 0, and really set on first access
#if defined(STREFLOP_X87)
    fpenv_t FE_DFL_ENV = 0;
#elif defined(STREFLOP_SSE)
    fpenv_t FE_DFL_ENV = {0,0};
#elif defined(STREFLOP_SOFT)
    fpenv_t FE_DFL_ENV = {42,0,0};
#else
#error STREFLOP: Invalid combination or unknown FPU type.
#endif

}
