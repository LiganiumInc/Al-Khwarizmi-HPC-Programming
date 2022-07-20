#ifndef REDUCTION_TAB_Y285IIP3ER25_Y285IIP3ER25_H
#define REDUCTION_TAB_Y285IIP3ER25_Y285IIP3ER25_H

#include <stdlib.h>
#include "ndarrays.h"
#include <stdint.h>


void initialize_table(t_ndarray tab, int64_t nmolec, int64_t n, int64_t nmol);
void reduction(t_ndarray tab, t_ndarray tab1, t_ndarray tab2, int64_t nmolec, int64_t nmol, int64_t n);
#endif // REDUCTION_TAB_Y285IIP3ER25_Y285IIP3ER25_H
