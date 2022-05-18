#include "hello.h"
#include "omp.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
int main()
{
    int64_t rank;
    int64_t n;
    omp_set_num_threads(3);
    #pragma omp parallel
    {
        rank = omp_get_thread_num();
        printf("%s %ld %s\n", "Hello from the rank ", rank, " thread");
        n = omp_get_num_threads();
    }
    printf("%s %ld %s\n", "Parallel execution of hello_world with ", n, " threads");
    return 0;
}