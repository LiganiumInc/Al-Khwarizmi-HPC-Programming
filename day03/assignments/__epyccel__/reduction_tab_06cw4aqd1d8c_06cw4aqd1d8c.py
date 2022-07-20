
def threads_num():
#     complete this function for getting threads 
    from pyccel.stdlib.internal.openmp import omp_get_num_threads 
    return omp_get_num_threads

def initialize_table(tab, nmolec, n, nmol):
    # Initialisation du tableau
    # First-touch pour garantir un fonctionnement optimal sur les systemes NUMA
    
    #$ omp parallel
    #$ omp for 
    for k in range(nmolec):
        for j in range(n):
            for i in range(nmol):
                tab[ i,j,k ] = i + j + k
                
    #$ omp end parallel

def reduction(tab, tab1, tab2, nmolec, nmol, n):
    
    #$ omp parallel
    #$ omp for 
    for k in range(nmolec):
        tab1[:nmol] = 0
        for j in range(n):
            for i in range(nmol):
                tab1[i] = tab1[i] + tab[i,j,k]
        tab2[:nmol] = tab2[:nmol] + 2 * tab1[:nmol]
        
    #$ omp end parallel