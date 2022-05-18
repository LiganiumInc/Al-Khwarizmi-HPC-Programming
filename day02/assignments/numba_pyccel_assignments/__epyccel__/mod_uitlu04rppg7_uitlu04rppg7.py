def solve_1d_diff_pyccel(u:'float[:]', un:'float[:]', nt:'int', nx:'int', dt:'float', dx:'float', nu:'float'):
    
    #fill the update of u
    for n in range(nt):
        un = u.copy()
        for i in range(1,nx-1):
            u[i] = un[i] + nu*(dt/dx**2) * (un[i+1]-2*un[i]+un[i-1])
    
    return 0
