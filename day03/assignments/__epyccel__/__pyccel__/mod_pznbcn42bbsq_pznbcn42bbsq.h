#ifndef MOD_PZNBCN42BBSQ_PZNBCN42BBSQ_H
#define MOD_PZNBCN42BBSQ_PZNBCN42BBSQ_H

#include <stdlib.h>
#include "ndarrays.h"
#include <stdint.h>


int jacobi(t_ndarray a, t_ndarray b, t_ndarray x, int64_t n, double eps, double *stand, int64_t *iteration);
#endif // MOD_PZNBCN42BBSQ_PZNBCN42BBSQ_H
