# write your program here
import random 
import timeit
from mpi4py import MPI


COMM = MPI.COMM_WORLD
nbproc = COMM.Get_size()
RANK = COMM.Get_rank()

INTERVAL = 1000 ** 2

local_int = INTERVAL //nbproc 
random.seed(42)  

def gen_points():
     
    
    nbpoints= 0

    
    for i in range(local_int): 
      
        # on choisit de générer les points x et y 
        # suivant une loi uniforme sur [0,2]
                
        x= random.uniform(0, 2) 
        y= random.uniform(0, 2) 
      
        # Distance entre chaque point (x, y) et le centre du cercle O(1,1)
        dist_centre= (x - 1)**2 + (y - 1)**2
      
        # on vérifie si (x, y) est à l'intérieur du cercle 
        if dist_centre<= 1: 
            nbpoints+= 1
    
    return nbpoints


start = timeit.default_timer()
nb_points = gen_points()
end = timeit.default_timer()

# on fait la somme de tous les points obtenus au niveau de chaque processus
nb_points = COMM.reduce(nb_points, op = MPI.SUM, root = 0)
if RANK == 0:
    
    pi = 4 * nb_points/ INTERVAL
    print('\n')
    print("Circle points number :",nb_points)
    print("Final Estimation of Pi=", pi, "cpu time :",(end-start) * 1000) 
