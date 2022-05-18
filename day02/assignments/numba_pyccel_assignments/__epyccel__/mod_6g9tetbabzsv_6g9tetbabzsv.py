def solve_1d_burger_pyccel(u, un, nt:int, nx, dt, dx, nu):
    #fill the update of u
    for n in range(nt):
        un = u.copy()
        for i in range(nx-1):
            u[i] = un[i] - un[i] * dt/dx * (un[i] - un[i-1])+\
            nu * dt/(dx**2) * (un[i+1] - 2*un[i] + un[i-1])
        
        # periodicité
        u[-1] = un[-1] - un[-1] * dt/dx * (un[-1] - un[-2])+\
            nu * dt/(dx**2) * (un[0] - 2*un[-1] + un[-2])
        
    return 0
