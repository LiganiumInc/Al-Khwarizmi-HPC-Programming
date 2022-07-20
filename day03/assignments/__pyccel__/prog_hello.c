#include "omp.h"
#include "hello.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
int main()
{
    int32_t rank;
    int32_t n;
    #pragma omp parallel
    {
        rank = omp_get_thread_num();
        printf("%s %d %s\n", "Hello from the rank ", rank, " thread");
        n = omp_get_num_threads();
    }
    printf("%s %d %s\n", "Parallel execution of hello_world with ", n, " threads");
    return 0;
}