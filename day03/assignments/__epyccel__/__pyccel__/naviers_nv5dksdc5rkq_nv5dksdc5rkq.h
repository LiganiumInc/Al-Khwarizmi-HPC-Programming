#ifndef NAVIERS_NV5DKSDC5RKQ_NV5DKSDC5RKQ_H
#define NAVIERS_NV5DKSDC5RKQ_NV5DKSDC5RKQ_H

#include <stdlib.h>
#include "ndarrays.h"
#include <stdint.h>


void build_up_b_cel(t_ndarray b, double rho, double dt, t_ndarray u, t_ndarray v, double dx, double dy);
void pressure_poisson_cel(t_ndarray p, double dx, double dy, t_ndarray b, int64_t nit);
void cavity_flow_cel(int64_t nt, t_ndarray u, t_ndarray v, double dt, int64_t nx, int64_t ny, double dx, double dy, t_ndarray p, double rho, double nu, int64_t nit);
#endif // NAVIERS_NV5DKSDC5RKQ_NV5DKSDC5RKQ_H
