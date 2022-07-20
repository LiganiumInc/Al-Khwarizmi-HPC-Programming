from mpi4py import MPI
import numpy as np
COMM = MPI.COMM_WORLD
RANK = COMM.Get_rank()

if RANK == 0 :
    sendbuf = 456
else :
    sendbuf = None
    
recvbuf = COMM.bcast(sendbuf,root=0)
print("I am t h e p r o c e s s {rank} , I r e c e i v e d d a t a {data} from 2 ".format(rank=RANK,
data=recvbuf))
