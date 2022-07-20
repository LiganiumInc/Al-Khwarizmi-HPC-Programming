#include "reduction_tab_y285iip3er25_y285iip3er25.h"
#include <stdlib.h>
#include "ndarrays.h"
#include <stdint.h>


/*........................................*/
void initialize_table(t_ndarray tab, int64_t nmolec, int64_t n, int64_t nmol)
{
    int64_t k;
    int64_t j;
    int64_t i;
    /*Initialisation du tableau*/
    /*First-touch pour garantir un fonctionnement optimal sur les systemes NUMA*/
    #pragma omp parallel
    {
        #pragma omp for
        for (k = 0; k < nmolec; k += 1)
        {
            for (j = 0; j < n; j += 1)
            {
                for (i = 0; i < nmol; i += 1)
                {
                    GET_ELEMENT(tab, nd_double, (int64_t)i, (int64_t)j, (int64_t)k) = i + j + k;
                }
            }
        }
    }
}
/*........................................*/
/*........................................*/
void reduction(t_ndarray tab, t_ndarray tab1, t_ndarray tab2, int64_t nmolec, int64_t nmol, int64_t n)
{
    int64_t k;
    int64_t j;
    int64_t i;
    int64_t i_0001;
    #pragma omp parallel
    {
        #pragma omp for
        for (k = 0; k < nmolec; k += 1)
        {
            for (i_0001 = 0; i_0001 < nmol; i_0001 += 1)
            {
                GET_ELEMENT(tab1, nd_double, (int64_t)i_0001) = 0;
            }
            for (j = 0; j < n; j += 1)
            {
                for (i = 0; i < nmol; i += 1)
                {
                    GET_ELEMENT(tab1, nd_double, (int64_t)i) = GET_ELEMENT(tab1, nd_double, (int64_t)i) + GET_ELEMENT(tab, nd_double, (int64_t)i, (int64_t)j, (int64_t)k);
                }
            }
            for (i_0001 = 0; i_0001 < nmol; i_0001 += 1)
            {
                GET_ELEMENT(tab2, nd_double, (int64_t)i_0001) = GET_ELEMENT(tab2, nd_double, (int64_t)i_0001) + 2 * GET_ELEMENT(tab1, nd_double, (int64_t)i_0001);
            }
        }
    }
}
/*........................................*/

