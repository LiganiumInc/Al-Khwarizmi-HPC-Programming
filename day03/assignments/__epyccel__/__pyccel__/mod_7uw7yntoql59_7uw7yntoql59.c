#include "mod_7uw7yntoql59_7uw7yntoql59.h"
#include <stdlib.h>
#include "ndarrays.h"
#include <stdint.h>
#include <math.h>


/*........................................*/
int jacobi(t_ndarray a, t_ndarray b, t_ndarray x, int64_t n, double eps, double *stand, int64_t *iteration)
{
    t_ndarray x_courant = {.shape = NULL};
    int64_t i;
    int64_t j;
    double absmax;
    double curr;
    /*print("Execution of Jacobi in parallel with", nb_tasks, "threads")*/
    /*Jacobi method resolution*/
    x_courant = array_create(1, (int64_t[]){n}, nd_double);
    (*iteration) = 0;
    #pragma omp parallel
    {
        while((1 != 0))
        {
            (*iteration) += 1;
            #pragma omp for
            for (i = 0; i < n; i += 1)
            {
                GET_ELEMENT(x_courant, nd_double, (int64_t)i) = 0;
                for (j = 0; j < i; j += 1)
                {
                    GET_ELEMENT(x_courant, nd_double, (int64_t)i) += GET_ELEMENT(a, nd_double, (int64_t)j, (int64_t)i) * GET_ELEMENT(x, nd_double, (int64_t)j);
                }
                for (j = i + 1; j < n; j += 1)
                {
                    GET_ELEMENT(x_courant, nd_double, (int64_t)i) += GET_ELEMENT(a, nd_double, (int64_t)j, (int64_t)i) * GET_ELEMENT(x, nd_double, (int64_t)j);
                }
                GET_ELEMENT(x_courant, nd_double, (int64_t)i) = (GET_ELEMENT(b, nd_double, (int64_t)i) - GET_ELEMENT(x_courant, nd_double, (int64_t)i)) / GET_ELEMENT(a, nd_double, (int64_t)i, (int64_t)i);
            }
            /*Convergence test*/
            absmax = 0.0;
            #pragma omp for
            for (i = 0; i < n; i += 1)
            {
                curr = fabs(GET_ELEMENT(x, nd_double, (int64_t)i) - GET_ELEMENT(x_courant, nd_double, (int64_t)i));
                if (curr > absmax)
                {
                    absmax = curr;
                }
            }
            (*stand) = absmax / n;
            if ((*stand) <= eps || (*iteration) > n)
            {
                break;
            }
            /*copy x_courant into x*/
            #pragma omp for
            for (i = 0; i < n; i += 1)
            {
                GET_ELEMENT(x, nd_double, (int64_t)i) = GET_ELEMENT(x_courant, nd_double, (int64_t)i);
            }
        }
    }
    free_array(x_courant);
    return 0;
}
/*........................................*/

