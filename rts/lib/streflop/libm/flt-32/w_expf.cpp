/* See the import.pl script for potential modifications */
/* The original libm wrapper may call the Double implementation
   and declares Double constants.
   This wrapper purely wraps the StreflopSimple version
*/

#include "math_private.h"

namespace streflop_libm {
StreflopSimple __expf(StreflopSimple x) {
    return __ieee754_expf(x);
}
}
