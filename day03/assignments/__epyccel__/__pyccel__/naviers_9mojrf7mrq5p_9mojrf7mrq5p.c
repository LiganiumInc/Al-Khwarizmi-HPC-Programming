#include "naviers_9mojrf7mrq5p_9mojrf7mrq5p.h"
#include <stdlib.h>
#include "ndarrays.h"
#include <stdint.h>
#include <math.h>


/*........................................*/
void build_up_b_cel(t_ndarray b, double rho, double dt, t_ndarray u, t_ndarray v, double dx, double dy)
{
    int64_t i;
    int64_t i_0001;
    /*row, col = p.shape*/
    /*fill the update of b*/
    for (i = 0; i < b.shape[0] - 1 - 1; i += 1)
    {
        for (i_0001 = 0; i_0001 < b.shape[1] - 1 - 1; i_0001 += 1)
        {
            GET_ELEMENT(b, nd_double, (int64_t)i + 1, (int64_t)i_0001 + 1) = rho * (1 / dt * ((GET_ELEMENT(u, nd_double, (int64_t)i + 1, (int64_t)i_0001 + 2) - GET_ELEMENT(u, nd_double, (int64_t)i + 1, (int64_t)i_0001)) / (2 * dx) + (GET_ELEMENT(v, nd_double, (int64_t)i + 2, (int64_t)i_0001 + 1) - GET_ELEMENT(v, nd_double, (int64_t)i, (int64_t)i_0001 + 1)) / (2 * dy)) - pow(((GET_ELEMENT(u, nd_double, (int64_t)i + 1, (int64_t)i_0001 + 2) - GET_ELEMENT(u, nd_double, (int64_t)i + 1, (int64_t)i_0001)) / (2 * dx)), 2.0) - 2 * ((GET_ELEMENT(u, nd_double, (int64_t)i + 2, (int64_t)i_0001 + 1) - GET_ELEMENT(u, nd_double, (int64_t)i, (int64_t)i_0001 + 1)) / (2 * dy) * (GET_ELEMENT(v, nd_double, (int64_t)i + 1, (int64_t)i_0001 + 2) - GET_ELEMENT(v, nd_double, (int64_t)i + 1, (int64_t)i_0001)) / (2 * dx)) - pow(((GET_ELEMENT(v, nd_double, (int64_t)i + 2, (int64_t)i_0001 + 1) - GET_ELEMENT(v, nd_double, (int64_t)i, (int64_t)i_0001 + 1)) / (2 * dy)), 2.0));
        }
    }
    /*return b*/
}
/*........................................*/
/*........................................*/
void pressure_poisson_cel(t_ndarray p, double dx, double dy, t_ndarray b, int64_t nit)
{
    t_ndarray pn = {.shape = NULL};
    int64_t row;
    int64_t col;
    int64_t i;
    int64_t j;
    int64_t q;
    int64_t i_0001;
    int64_t i_0002;
    pn = array_create(2, (int64_t[]){p.shape[0], p.shape[1]}, nd_double, false);
    row = p.shape[0];
    col = p.shape[1];
    /*pn = np.empty_like(p)*/
    for (i = 0; i < row; i += 1)
    {
        for (j = 0; j < col; j += 1)
        {
            GET_ELEMENT(pn, nd_double, (int64_t)i, (int64_t)j) = GET_ELEMENT(p, nd_double, (int64_t)i, (int64_t)j);
        }
    }
    /*fill the update of p*/
    for (q = 0; q < nit; q += 1)
    {
        for (i = 0; i < row; i += 1)
        {
            for (j = 0; j < col; j += 1)
            {
                GET_ELEMENT(pn, nd_double, (int64_t)i, (int64_t)j) = GET_ELEMENT(p, nd_double, (int64_t)i, (int64_t)j);
            }
        }
        for (i_0001 = 0; i_0001 < p.shape[0] - 1 - 1; i_0001 += 1)
        {
            for (i_0002 = 0; i_0002 < p.shape[1] - 1 - 1; i_0002 += 1)
            {
                GET_ELEMENT(p, nd_double, (int64_t)i_0001 + 1, (int64_t)i_0002 + 1) = ((GET_ELEMENT(pn, nd_double, (int64_t)i_0001 + 1, (int64_t)i_0002 + 2) + GET_ELEMENT(pn, nd_double, (int64_t)i_0001 + 1, (int64_t)i_0002)) * (dy * dy) + (GET_ELEMENT(pn, nd_double, (int64_t)i_0001 + 2, (int64_t)i_0002 + 1) + GET_ELEMENT(pn, nd_double, (int64_t)i_0001, (int64_t)i_0002 + 1)) * (dx * dx)) / (2 * (dx * dx + dy * dy)) - dx * dx * (dy * dy) / (2 * (dx * dx + dy * dy)) * GET_ELEMENT(b, nd_double, (int64_t)i_0001 + 1, (int64_t)i_0002 + 1);
            }
        }
        for (i_0001 = 0; i_0001 < p.shape[0]; i_0001 += 1)
        {
            GET_ELEMENT(p, nd_double, (int64_t)i_0001, (int64_t)p.shape[1] - 1) = GET_ELEMENT(p, nd_double, (int64_t)i_0001, (int64_t)p.shape[1] - 2);
        }
        for (i_0001 = 0; i_0001 < p.shape[1]; i_0001 += 1)
        {
            GET_ELEMENT(p, nd_double, (int64_t)0, (int64_t)i_0001) = GET_ELEMENT(p, nd_double, (int64_t)1, (int64_t)i_0001);
        }
        for (i_0001 = 0; i_0001 < p.shape[0]; i_0001 += 1)
        {
            GET_ELEMENT(p, nd_double, (int64_t)i_0001, (int64_t)0) = GET_ELEMENT(p, nd_double, (int64_t)i_0001, (int64_t)1);
        }
        for (i_0001 = 0; i_0001 < p.shape[1]; i_0001 += 1)
        {
            GET_ELEMENT(p, nd_double, (int64_t)p.shape[0] - 1, (int64_t)i_0001) = 0;
        }
    }
    free_array(pn);
}
/*........................................*/
/*........................................*/
void cavity_flow_cel(int64_t nt, t_ndarray u, t_ndarray v, double dt, int64_t nx, int64_t ny, double dx, double dy, t_ndarray p, double rho, double nu, int64_t nit)
{
    int64_t rowu;
    int64_t colu;
    int64_t rowv;
    int64_t colv;
    t_ndarray un = {.shape = NULL};
    t_ndarray vn = {.shape = NULL};
    t_ndarray b = {.shape = NULL};
    int64_t n;
    int64_t i;
    int64_t j;
    int64_t i_0001;
    int64_t i_0002;
    rowu = u.shape[0];
    colu = u.shape[1];
    rowv = v.shape[0];
    colv = v.shape[1];
    un = array_create(2, (int64_t[]){u.shape[0], u.shape[1]}, nd_double, false);
    vn = array_create(2, (int64_t[]){v.shape[0], v.shape[1]}, nd_double, false);
    b = array_create(2, (int64_t[]){ny, nx}, nd_double, false);
    array_fill((double)0.0, b);
    for (n = 0; n < nt; n += 1)
    {
        for (i = 0; i < rowu; i += 1)
        {
            for (j = 0; j < colu; j += 1)
            {
                GET_ELEMENT(un, nd_double, (int64_t)i, (int64_t)j) = GET_ELEMENT(u, nd_double, (int64_t)i, (int64_t)j);
            }
        }
        for (i = 0; i < rowv; i += 1)
        {
            for (j = 0; j < colv; j += 1)
            {
                GET_ELEMENT(vn, nd_double, (int64_t)i, (int64_t)j) = GET_ELEMENT(v, nd_double, (int64_t)i, (int64_t)j);
            }
        }
        /*b = bb_cel(b, rho, dt, u, v, dx, dy)*/
        /*p = pp_cel(p, dx, dy, b)*/
        build_up_b_cel(b, rho, dt, u, v, dx, dy);
        pressure_poisson_cel(p, dx, dy, b, nit);
        for (i_0001 = 0; i_0001 < u.shape[0] - 1 - 1; i_0001 += 1)
        {
            for (i_0002 = 0; i_0002 < u.shape[1] - 1 - 1; i_0002 += 1)
            {
                GET_ELEMENT(u, nd_double, (int64_t)i_0001 + 1, (int64_t)i_0002 + 1) = GET_ELEMENT(un, nd_double, (int64_t)i_0001 + 1, (int64_t)i_0002 + 1) - GET_ELEMENT(un, nd_double, (int64_t)i_0001 + 1, (int64_t)i_0002 + 1) * dt / dx * (GET_ELEMENT(un, nd_double, (int64_t)i_0001 + 1, (int64_t)i_0002 + 1) - GET_ELEMENT(un, nd_double, (int64_t)i_0001 + 1, (int64_t)i_0002)) - GET_ELEMENT(vn, nd_double, (int64_t)i_0001 + 1, (int64_t)i_0002 + 1) * dt / dy * (GET_ELEMENT(un, nd_double, (int64_t)i_0001 + 1, (int64_t)i_0002 + 1) - GET_ELEMENT(un, nd_double, (int64_t)i_0001, (int64_t)i_0002 + 1)) - dt / (2 * rho * dx) * (GET_ELEMENT(p, nd_double, (int64_t)i_0001 + 1, (int64_t)i_0002 + 2) - GET_ELEMENT(p, nd_double, (int64_t)i_0001 + 1, (int64_t)i_0002)) + nu * (dt / (dx * dx) * (GET_ELEMENT(un, nd_double, (int64_t)i_0001 + 1, (int64_t)i_0002 + 2) - 2 * GET_ELEMENT(un, nd_double, (int64_t)i_0001 + 1, (int64_t)i_0002 + 1) + GET_ELEMENT(un, nd_double, (int64_t)i_0001 + 1, (int64_t)i_0002)) + dt / (dy * dy) * (GET_ELEMENT(un, nd_double, (int64_t)i_0001 + 2, (int64_t)i_0002 + 1) - 2 * GET_ELEMENT(un, nd_double, (int64_t)i_0001 + 1, (int64_t)i_0002 + 1) + GET_ELEMENT(un, nd_double, (int64_t)i_0001, (int64_t)i_0002 + 1)));
            }
        }
        for (i_0001 = 0; i_0001 < v.shape[0] - 1 - 1; i_0001 += 1)
        {
            for (i_0002 = 0; i_0002 < v.shape[1] - 1 - 1; i_0002 += 1)
            {
                GET_ELEMENT(v, nd_double, (int64_t)i_0001 + 1, (int64_t)i_0002 + 1) = GET_ELEMENT(vn, nd_double, (int64_t)i_0001 + 1, (int64_t)i_0002 + 1) - GET_ELEMENT(un, nd_double, (int64_t)i_0001 + 1, (int64_t)i_0002 + 1) * dt / dx * (GET_ELEMENT(vn, nd_double, (int64_t)i_0001 + 1, (int64_t)i_0002 + 1) - GET_ELEMENT(vn, nd_double, (int64_t)i_0001 + 1, (int64_t)i_0002)) - GET_ELEMENT(vn, nd_double, (int64_t)i_0001 + 1, (int64_t)i_0002 + 1) * dt / dy * (GET_ELEMENT(vn, nd_double, (int64_t)i_0001 + 1, (int64_t)i_0002 + 1) - GET_ELEMENT(vn, nd_double, (int64_t)i_0001, (int64_t)i_0002 + 1)) - dt / (2 * rho * dy) * (GET_ELEMENT(p, nd_double, (int64_t)i_0001 + 2, (int64_t)i_0002 + 1) - GET_ELEMENT(p, nd_double, (int64_t)i_0001, (int64_t)i_0002 + 1)) + nu * (dt / (dx * dx) * (GET_ELEMENT(vn, nd_double, (int64_t)i_0001 + 1, (int64_t)i_0002 + 2) - 2 * GET_ELEMENT(vn, nd_double, (int64_t)i_0001 + 1, (int64_t)i_0002 + 1) + GET_ELEMENT(vn, nd_double, (int64_t)i_0001 + 1, (int64_t)i_0002)) + dt / (dy * dy) * (GET_ELEMENT(vn, nd_double, (int64_t)i_0001 + 2, (int64_t)i_0002 + 1) - 2 * GET_ELEMENT(vn, nd_double, (int64_t)i_0001 + 1, (int64_t)i_0002 + 1) + GET_ELEMENT(vn, nd_double, (int64_t)i_0001, (int64_t)i_0002 + 1)));
            }
        }
        for (i_0001 = 0; i_0001 < u.shape[1]; i_0001 += 1)
        {
            GET_ELEMENT(u, nd_double, (int64_t)0, (int64_t)i_0001) = 0;
        }
        for (i_0001 = 0; i_0001 < u.shape[0]; i_0001 += 1)
        {
            GET_ELEMENT(u, nd_double, (int64_t)i_0001, (int64_t)0) = 0;
            GET_ELEMENT(u, nd_double, (int64_t)i_0001, (int64_t)u.shape[1] - 1) = 0;
        }
        for (i_0001 = 0; i_0001 < u.shape[1]; i_0001 += 1)
        {
            GET_ELEMENT(u, nd_double, (int64_t)u.shape[0] - 1, (int64_t)i_0001) = 1;
        }
        for (i_0001 = 0; i_0001 < v.shape[1]; i_0001 += 1)
        {
            GET_ELEMENT(v, nd_double, (int64_t)0, (int64_t)i_0001) = 0;
            GET_ELEMENT(v, nd_double, (int64_t)v.shape[0] - 1, (int64_t)i_0001) = 0;
        }
        for (i_0001 = 0; i_0001 < v.shape[0]; i_0001 += 1)
        {
            GET_ELEMENT(v, nd_double, (int64_t)i_0001, (int64_t)0) = 0;
            GET_ELEMENT(v, nd_double, (int64_t)i_0001, (int64_t)v.shape[1] - 1) = 0;
        }
    }
    free_array(un);
    free_array(vn);
    free_array(b);
}
/*........................................*/

