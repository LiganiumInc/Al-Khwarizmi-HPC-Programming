import time 
import numpy as np
from scipy.sparse import lil_matrix
from numpy.random import rand, seed
from numba import njit
from mpi4py import MPI

COMM = MPI.COMM_WORLD
nbproc = COMM.Get_size()
RANK = COMM.Get_rank()

seed(42)

# function générique pour le produit matrice vecteur
def matVectMult(A, b, C):
    
    row, col = A.shape
    for i in range(row):
        a = A[i]
        for j in range(col):
            C[i] += a[j] * b[j]

    return 0


# créons la matrice A et le vecteur b
SIZE = 1000
local_size = SIZE // nbproc


# counts est la liste contenant les blocks de chaque  proc
proc_block = local_size * SIZE
counts =  [proc_block for i in range(nbproc)]

if RANK == 0:
    A = lil_matrix((SIZE, SIZE))
    A[0, :100] = rand(100)
    A[1, 100:200] = A[0, :100]
    A.setdiag(rand(SIZE))
    A = A.toarray()
    b = rand(SIZE)
else :
    A = None
    b = None

## on envoie une copie de b sur chaque proc et on distribue une partie de  A 
## à chaque processus

localMatrix = np.empty((local_size, SIZE), dtype = np.float64)
b = COMM.bcast(b, root = 0)

COMM.Scatterv([A, counts, MPI.DOUBLE], localMatrix, root = 0)

## Au niveau de chaque processus on fait un produit entre la matrice locale et b
localC = np.zeros(local_size)
start = MPI.Wtime()
matVectMult(localMatrix, b, localC)
stop = MPI.Wtime()
if RANK == 0:
    print("\n\n CPU time of parallel multiplication using", nbproc,"processes is ", (stop - start)*1000)


## On rassemble maintenant les résultats obtenus au niveau de chaque processus

sendcounts = [local_size for i in range(nbproc)] 
if RANK == 0: 
    C = np.empty(SIZE, dtype = np.float64)
else :
    C = None

# rassemblement des résultats dans C
COMM.Gatherv(localC,[C, sendcounts, MPI.DOUBLE], root = 0)

if RANK == 0 :
    C_ = A.dot(b)
    print("The error comparing to the dot product is :", np.max(C_ - C))
