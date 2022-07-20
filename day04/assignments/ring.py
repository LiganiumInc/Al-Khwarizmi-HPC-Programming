from mpi4py import MPI
COMM = MPI.COMM_WORLD
RANK = COMM.Get_rank()
SIZE = COMM.Get_size()

if RANK == 0 :
    print()
    sendbuf = int(input()) 
    COMM.send(sendbuf, dest = RANK+1)

if RANK != 0:
    recvbuf = COMM.recv(source=RANK-1)
    print("Process : ", RANK, "obtain ",recvbuf, "from ",RANK-1)

    if RANK < SIZE - 1:
        COMM.send(recvbuf, dest = RANK+1)
