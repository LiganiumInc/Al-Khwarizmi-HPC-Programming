#include "mod_6sqanu0cau09_6sqanu0cau09.h"
#include <stdlib.h>
#include <stdint.h>


/*........................................*/
int64_t iter_factorial(int64_t n)
{
    int64_t i;
    int64_t fact;
    fact = 1;
    for (i = 2; i < n + 1; i += 1)
    {
        fact *= i;
    }
    return fact;
}
/*........................................*/

