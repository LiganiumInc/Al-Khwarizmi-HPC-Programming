if "__name__" == "__main__" :
    from pyccel.stdlib.internal.openmp import omp_get_thread_num, omp_get_num_threads, omp_set_num_threads
    
    #$ omp parallel 
    rank = omp_get_thread_num()
    print('Hello from the rank ',rank,' thread')
    n = omp_get_num_threads()
    #$ omp end parallel

    print('Parallel execution of hello_world with ',n,' threads')
