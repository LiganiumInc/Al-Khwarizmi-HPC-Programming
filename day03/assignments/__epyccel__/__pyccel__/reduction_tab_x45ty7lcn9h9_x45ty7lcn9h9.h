#ifndef REDUCTION_TAB_X45TY7LCN9H9_X45TY7LCN9H9_H
#define REDUCTION_TAB_X45TY7LCN9H9_X45TY7LCN9H9_H

#include <stdlib.h>
#include <stdint.h>
#include "ndarrays.h"


int32_t threads_num(void);
void initialize_table(t_ndarray tab, int64_t nmolec, int64_t n, int64_t nmol);
void reduction(t_ndarray tab, t_ndarray tab1, t_ndarray tab2, int64_t nmolec, int64_t nmol, int64_t n);
#endif // REDUCTION_TAB_X45TY7LCN9H9_X45TY7LCN9H9_H
