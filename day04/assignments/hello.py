from mpi4py import MPI
COMM = MPI.COMM_WORLD
RANK = COMM.Get_rank()
SIZE = COMM.Get_size()

print()
print("Hello from the rank {rank} process".format(rank=RANK))
COMM.Barrier()
if RANK == SIZE-1:
    print("Parallel execution of hello_world with {} process".format(SIZE))
