def matrix_prod(A:'double[:,:]', B:'double[:,:]', C:'double[:,:]', N:'int', M:'int'):
    
    for i in range( M ):
        for j in range( N ):
            A[ i, j ] = (i + 1) + (j + 1)

    
    for i in range( N ):
        for j in range( M ):
            B[ i, j ] = (i + 1) - (j + 1)

    
    for i in range( M ):
        for j in range( M ):
            C[ i, j ] = 0
    # ...

    # Matrix Production
    
    #$ omp parallel private(i,j,k) 
    #$ omp for
    for i in range( M ):
        for j in range( M ):
            for k in range( N ):
                C[ i, j ] += A[ i, k ] * B[ k, j ]
#     nb_threads = omp_get_num_threads()
#     print("Execution of Matrix production in parallele with",nb_threads, "threads")
    
    #$ omp end  parallel
    print()
